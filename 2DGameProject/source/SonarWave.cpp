#include "SonarWave.h"
#include "Time.h"
#include <DxLib.h>
#include "camera.h"
#include "SonarParam.h"

SonarWave::SonarWave() :m_radius(0.0f), m_speed(0.0f), m_maxRadius(0.0f), m_active(false)
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
        m_active = false;
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
    DrawCircle(pos.x, pos.y, (int)m_radius, GetColor(100, 100, 100), TRUE);
}
