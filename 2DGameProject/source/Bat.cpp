#include "Bat.h"
#include "Player.h"

Bat::Bat(Player* player) :m_state(BAT_STATE::Idle), m_moveSpeed(0.0f)
{
    m_player = player;

}

void Bat::Update()
{
    //各状態の処理
    switch (m_state)
    {
    case BAT_STATE::Idle:
        UpdateIdle();
        break;
    case BAT_STATE::Chase:
        UpdateChase();
        break;
    case BAT_STATE::Return:
        UpdateReturn();
        break;
    }
    GameObject::Update();
}

void Bat::UpdateIdle()
{
    //近づいたら追跡状態に
    float dist = Vector2D::Distance(m_position,m_player->GetPosition());
    if (dist <= m_detectRange)
    {
        m_state = BAT_STATE::Chase;
    }
}

void Bat::UpdateChase()
{
    //移動の向きを設定
    Vector2D dir = m_player->GetPosition() - m_position;
    //正規化
    dir.Normalize();
    //移動量設定
    m_velocity = dir * m_moveSpeed;
    //一定距離離れると帰還する
    float dist = Vector2D::Distance(m_position, m_player->GetPosition());
    if (dist > m_detectRange)
    {
        m_state = BAT_STATE::Return;
    }
}

void Bat::UpdateReturn()
{
    //帰還地点の向きを確認
    Vector2D dir = m_spawnPos - m_position;
    float dist = dir.Length();
    //初期地点に近づいたら待機状態に
    if (dist < 10.0f)
    {
        m_position = m_spawnPos;
        m_velocity = Vector2D(0.0f, 0.0f);
        m_state = BAT_STATE::Idle;
        return;
    }
    //向きの正規化
    dir.Normalize();
    m_velocity = dir * m_moveSpeed;
}
