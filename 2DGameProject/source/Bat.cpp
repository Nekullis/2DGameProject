#include "Bat.h"
#include "Player.h"
#include "EnemyParamManager.h"
#include "Animation.h"
#include "Time.h"

Bat::Bat(Player* player) :m_state(BAT_STATE::Idle), m_moveSpeed(0.0f), m_waveTimer(0.0f), m_waveSpeed(4.0f), m_waveAmplitude(0.4f)
{
    m_player = player;
    m_currentAnim = &m_idleAnim;
    m_moveSpeed = EnemyParamManager::Get("Bat").MoveSpeed;
    m_detectRange = EnemyParamManager::Get("Bat").DetectRange;
    m_lostRange = EnemyParamManager::Get("Bat").LostRange;
    LoadAnimation();
}

void Bat::Update()
{
    m_waveTimer += Time::DeltaTime();

    //各状態の処理
    switch (m_state)
    {
    case BAT_STATE::Idle:
        ChangeAnimation(&m_idleAnim);
        UpdateIdle();
        break;
    case BAT_STATE::Chase:
        ChangeAnimation(&m_ChaseAnim);
        UpdateChase();
        break;
    case BAT_STATE::Return:
        ChangeAnimation(&m_ReturnAnim);
        UpdateReturn();
        break;
    }
    GameObject::Update();

    //アニメーション処理
    if (m_currentAnim && m_sprite)
    {
        m_currentAnim->Update();
        m_currentAnim->Apply(*m_sprite);
    }

    if (!m_player->IsActive())
    {
        m_velocity = Vector2D(0, 0);
    }
}

void Bat::ChangeState(BAT_STATE state)
{
    if (m_state == state) { return; }

    m_state = state;
}

void Bat::LoadAnimation()
{
    //アニメーション読み込み
    auto motion_idle = std::make_shared<Texture>("res/enemy/bat/Bat_Idle.png");
    auto motion_move = std::make_shared<Texture>("res/enemy/bat/Bat_Move.png");
    //各アニメーションをフレーム登録
    //待機
    for (int i = 0; i < 5; i++)
    {
        m_idleAnim.AddFrame(motion_idle, i * 100, 0, 100, 100);
    }
    m_idleAnim.SetFPS(10);
    m_idleAnim.SetLoop(true);
    for (int i = 0; i < 4; i++)
    {
        m_ChaseAnim.AddFrame(motion_move, i * 200, 0, 200, 100);
    }
    m_ChaseAnim.SetFPS(10);
    m_ChaseAnim.SetLoop(true);
    for (int i = 0; i < 4; i++)
    {
        m_ReturnAnim.AddFrame(motion_move, i * 200, 0, 200, 100);
    }
    m_ReturnAnim.SetFPS(10);
    m_ReturnAnim.SetLoop(true);
    m_sprite = std::make_shared<Sprite>(motion_idle);
}

void Bat::UpdateIdle()
{
    m_velocity = Vector2D(0, 0);
    //近づいたら追跡状態に
    float dist = Vector2D::Distance(m_position,m_player->GetPosition());
    if (dist <= m_detectRange)
    {
        ChangeState(BAT_STATE::Chase);
    }
}

void Bat::UpdateChase()
{
    //移動の向きを設定
    Vector2D dir = (m_player->GetPosition() - m_position).Normalize();
    //進行方向に対して垂直なベクトル
    Vector2D perp(-dir.y, dir.x);
    //サイン波で左右に揺らす
    float offset = sinf(m_waveTimer * m_waveSpeed) * m_waveAmplitude;
    //揺れを加える
    Vector2D moveDir = (dir + perp * offset).Normalize();

    //移動量設定
    m_velocity = moveDir * m_moveSpeed;
    //一定距離離れると帰還する
    float dist = Vector2D::Distance(m_position, m_player->GetPosition());
    if (dist > m_lostRange)
    {
        ChangeState(BAT_STATE::Return);
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
        ChangeState(BAT_STATE::Idle);
        return;
    }
    //向きの正規化
    dir = dir.Normalize();
    m_velocity = dir * m_moveSpeed;
}
