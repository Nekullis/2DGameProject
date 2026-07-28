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
    for (int i = 0; i < ringwidth; i++)
    {
        float t = (float)i / ringwidth;
        float intensity = powf(1.0f - t, 0.5f);
        //外側ほど明るくする
        int alpha = static_cast<int>(255 * intensity * m_alpha);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        DrawCircle(pos.x, pos.y, (int)m_radius - i, GetColor(255, 255, 255), FALSE);
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    
}

bool SonarWave::HasHitObject(GameObject* object) const
{
    return m_hitobjects.find(object) != m_hitobjects.end();
}

void SonarWave::AddHitObject(GameObject* object)
{
    m_hitobjects.insert(object);
}
