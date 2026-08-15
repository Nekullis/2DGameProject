#include "SonarWave.h"
#include "Time.h"
#include <DxLib.h>
#include "camera.h"
#include "SonarParam.h"

SonarWave::SonarWave() :m_radius(0.0f), m_speed(0.0f), m_maxRadius(0.0f), m_alpha(1.0f), m_active(false)
{
}

void SonarWave::Start(const Vector2D& pos, float landingSpeed)
{
    //初期化処理
    m_position = pos;
    m_radius = 0.0f;
    m_speed = SonarParam::Speed;
    //m_maxRadius = SonarParam::MaxRadius + landingSpeed;
    m_maxRadius = SonarParam::MaxRadius;
    m_active = true;
    m_hitobjects.clear();
}

void SonarWave::Update()
{
    //初期化処理できていないならスルー
    if (!m_active)
    {
        return;
    }
    //ソナー範囲を伸ばす
    m_radius += m_speed * Time::DeltaTime();

    //ソナー範囲が最大値なら終了
    if (m_radius >= m_maxRadius)
    {
        m_alpha -= Time::DeltaTime() * 2.0f;
        if (m_alpha <= 0.0f)
        {
            m_active = false;
        }
    }

    for (auto& distortion : m_distortions)
    {
        //歪み時間を減らす
        if (distortion.time > 0.0f)
        {
            distortion.time -= Time::DeltaTime();

            //時間が切れたら減衰開始
            if (distortion.time < 0.0f)
            {
                distortion.time = 0.0f;
            }
        }

        //歪みが残っている場合、徐々に弱める
        if (distortion.power > 0.0f)
        {
            //徐々にゆがみ始める
            distortion.power -= 20.0f * Time::DeltaTime();

            //0未満にならないように
            if (distortion.power < 0.0f)
            {
                distortion.power = 0.0f;
            }
        }
    }
    
    //歪みが無くなったものを削除
    m_distortions.erase(std::remove_if(m_distortions.begin(), m_distortions.end(),
        [](const DistortionEvent& distortion){return distortion.power <= 0.0;}),
        m_distortions.end());
    
}

void SonarWave::Draw() const
{
    //初期化処理、もしくはソナーが最大範囲に達しているならスルー
    if (!m_active)
    {
        return;
    }

    Vector2D pos =
    {
        m_position.x - Camera::w_camera._pos.x,
        m_position.y - Camera::w_camera._pos.y
    };

    int ringwidth = SonarParam::RingWidth;
    //ソナーリング本体の描画
    for (int i = 0; i < ringwidth; i++)
    {
        //外側ほど明るくなるよう補間値を計算
        float t = (float)i / ringwidth;
        float intensity = powf(1.0f - t, 0.5f);

        //α値設定
        int alpha = static_cast<int>(255 * intensity * m_alpha);
        DrawRing(pos, m_radius - i, alpha);
    }

    //発光表現用
    const int glowWidth = 8;
    //外側へ向かって薄く描画
    for (int i = 1; i <= glowWidth; i++)
    {
        int alpha = static_cast<int>(80.0f * (1.0f - (float)i / glowWidth) * m_alpha);
        DrawRing(pos, m_radius + i, alpha);
    }

    //ブレンドモードに戻す
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    
}

void SonarWave::DrawRing(const Vector2D& pos, float radius, int alpha) const
{
    const int DIV = 64;
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

    for (int i = 1; i <= DIV; i++)
    {
        //現在の頂点と次の頂点の角度
        float angle1 = DX_PI_F * 2.0f * i / DIV;
        float angle2 = DX_PI_F * 2.0f * (i + 1) / DIV;

        //サイン波で半径を変化させ、リングを波立たせる
        float noise1 = CalcDistortion(angle1);
        float noise2 = CalcDistortion(angle2);

        //ノイズを加えた半径
        float r1 = radius + noise1;
        float r2 = radius + noise2;

        //円周上の2点を線で結び、リングを描画
        DrawLine(pos.x + cosf(angle1) * r1, pos.y + sinf(angle1) * r1, pos.x + cosf(angle2) * r2, pos.y + sinf(angle2) * r2, GetColor(255, 255, 255));
    }
}

bool SonarWave::HasHitObject(GameObject* object) const
{
    return m_hitobjects.find(object) != m_hitobjects.end();
}

void SonarWave::AddHitObject(GameObject* object)
{
    m_hitobjects.insert(object);
}

void SonarWave::AddDistortion(float angle, float power, float time)
{
    DistortionEvent distortion;

    distortion.angle = angle;
    distortion.power = power;
    distortion.time = time;

    m_distortions.push_back(distortion);
}

float SonarWave::CalcDistortion(float angle) const
{
    float noise = 0.0f;

    //発生中の歪みをすべて加算
    for (const auto& distortion : m_distortions)
    {
        //現在の頂点と歪み方向との角度差
        float diff = fabsf(angle - distortion.angle);
        //角度差を0からπに補正
        if (diff > DX_PI_F)
        {
            diff = DX_PI_F * 2.0f - diff;
        }

        //正面ほど影響が強いように
        float influence = cosf(diff);
        if (influence < 0.0f)
        {
            influence = 0.0f;
        }

        //歪みを加算
        noise += sinf(angle * 5.0f + m_radius * 0.08f) * distortion.power * influence;
    }

    return noise;
}
