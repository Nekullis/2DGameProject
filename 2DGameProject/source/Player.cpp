#include "Player.h"
#include "InputManager.h"
#include "PlayerParam.h"
#include "Time.h"
#include "TileMap.h"
#include <DxLib.h>
#include <cmath>
#include "Physics.h"

Player::Player(TileMap* tilemap) :m_tilemap(tilemap), m_isGround(false), m_prevGround(false), m_isJump(false), m_jumpTimer(0), m_landingSpeed(0), m_state(PlayerState::Idle), m_currentAnim(nullptr)
{
	//パラメータ読み込み
	PlayerParam::Load();
	LoadAnimation();
	m_currentAnim = &m_idleAnim;
}


void Player::Update()
{
	//入力処理
	Input();
	//ジャンプ処理
	Jump();
	//重力処理
	ApplyGravity();
    //更新
    GameObject::Update();
	//衝突判定
	Collision();
    //接地判定
    CheckGround();
	//状態更新
	UpdateState();
	
	//落下速度保存
	if (m_velocity.y > 0)
	{
		m_landingSpeed = m_velocity.y;
	}

	//各状態のアニメーション
	switch (m_state)
	{
	case PlayerState::Idle:
		ChangeAnimation(&m_idleAnim);
		break;
	case PlayerState::Move:
		ChangeAnimation(&m_walkAnim);
		break;
	case PlayerState::Jump:
		ChangeAnimation(&m_jumpUpAnim);
		break;
	case PlayerState::Fall:
		ChangeAnimation(&m_jumpDownAnim);
		break;
    case PlayerState::Land:
        ChangeAnimation(&m_stepAnim);
        break;
	}

	//アニメーション処理
	if (m_currentAnim && m_sprite)
	{
		m_currentAnim->Update();
		m_currentAnim->Apply(*m_sprite);
	}

	//最後に保存
	m_prevGround = m_isGround;
}

void Player::Draw()
{
    static int hitCount = 0;
    if (m_isGround)
    {
        hitCount++;
    }
    GameObject::Draw();

    DrawFormatString(0, 40, GetColor(255, 255, 255), "Ground=%d vel=%.2f", m_isGround, m_velocity.x);
    DrawFormatString(0, 240, GetColor(255, 255, 255), "PosX=%.2f, PosY=%.2f", m_position.x,m_position.y);
    DrawFormatString(0, 260, GetColor(255, 255, 255), "DT=%.6f", Time::DeltaTime());
    //DrawFormatString(0, 280, GetColor(255, 255, 255), "hit=%d", (int)m_debugHit);
    DrawFormatString(0, 300, GetColor(255, 255, 255), "State=%d",(int)m_state);
}


void Player::LoadAnimation()
{
    //アニメーション読み込み
    auto motion_idle = std::make_shared<Texture>("res/player/player_motion/Slime_Idle.png");
    auto motion_walk = std::make_shared<Texture>("res/player/player_motion/Slime_Walk.png");
    auto motion_jump = std::make_shared<Texture>("res/player/player_motion/Slime_Jump.png");
    auto motion_step = std::make_shared<Texture>("res/player/player_motion/Slime_Step.png");
    m_sprite = std::make_shared<Sprite>(motion_idle);
    //各アニメーションをフレーム登録
    //待機
    for (int i = 0; i < 9; i++)
    {
        m_idleAnim.AddFrame(motion_idle, i * 150, 0, 150, 100);
    }
    m_idleAnim.SetFPS(10);
    m_idleAnim.SetLoop(true);
    //移動
    for (int i = 0; i < 6; i++)
    {
        m_walkAnim.AddFrame(motion_walk, i * 150, 0, 150, 100);
    }
    m_walkAnim.SetFPS(10);
    m_walkAnim.SetLoop(true);
    //上昇
    for (int i = 0; i < 7; i++)
    {
        m_jumpUpAnim.AddFrame(motion_jump, i * 150, 0, 150, 100);
    }
    m_jumpUpAnim.SetFPS(10);
    m_jumpUpAnim.SetLoop(false);
    //下降
    for (int i = 0; i < 5; i++)
    {
        m_jumpDownAnim.AddFrame(motion_jump, i * 150, 100, 150, 100);
    }
    m_jumpDownAnim.SetFPS(10);
    m_jumpDownAnim.SetLoop(false);
    //着地
    for (int i = 0; i < 8; i++)
    {
        m_stepAnim.AddFrame(motion_step, i * 150, 0, 150, 100);
    }
    m_stepAnim.SetFPS(10);
    m_stepAnim.SetLoop(false);

}

void Player::CheckGround()
{
    m_isGround = false;
    MYRECT footRect = GetRect();
    //足元周りの判定強化
    footRect.y += footRect.h;
    footRect.h = 2;
    auto walls = m_tilemap->GetWallRects();
    for (auto& wall : walls)
    {
        if (IsHitBox(footRect, wall))
        {
            m_isGround = true;
            return;
        }
    }
}

MYRECT Player::GetRect() const
{
	MYRECT rect;
	rect.x = (int)m_position.x;
	rect.y = (int)m_position.y;
	rect.w = 150;
	rect.h = 100;

	return rect;
}

void Player::Collision()
{
	//接地初期化
	m_isGround = false;
	//壁一覧取得
	auto walls = m_tilemap->GetWallRects();
	//プレイヤー矩形取得
	MYRECT playerRect = GetRect();
	//全壁と判定
	for (auto& wall : walls)
	{
		CollisionSide hit = Physics::ResolveBoxCollision(playerRect, wall);
        if (hit == CollisionSide::None)
		{
			continue;
		}
        switch (hit)
        {
        case CollisionSide::Top:
            m_velocity.y = 0;
            m_isJump = false;
            break;
        case CollisionSide::Bottom:
            m_velocity.y = 0;
            break;
        case CollisionSide::Left:
        case CollisionSide::Right:
            //m_velocity.x = 0;
            break;
        }
        //rect結果反映
        m_position.x = (float)playerRect.x;
        m_position.y = (float)playerRect.y;

        m_collider.SetPosition(m_position);
	}
}

void Player::Input()
{
	//毎フレーム初期化
	m_velocity.x = 0;
	//適応のキーで左右に移動
	if (InputManager::Press(KEY_INPUT_A))
	{
		m_velocity.x = -PlayerParam::MoveSpeed;
	}
	else if (InputManager::Press(KEY_INPUT_D))
	{
		m_velocity.x = PlayerParam::MoveSpeed;
	}
}

void Player::Jump()
{
	//ジャンプ処理
	if (m_isGround && InputManager::Trigger(KEY_INPUT_SPACE))
	{
		m_velocity.y -= PlayerParam::JumpPower;
		//空中にいる判定にする
		m_isGround = false;
		m_isJump = true;
		m_jumpTimer = 0;
	}
	//長押し処理
	if (m_isJump && InputManager::Press(KEY_INPUT_SPACE))
	{
		if (m_jumpTimer < PlayerParam::MaxJumpTime)
		{
			//上昇追加
			m_velocity.y -= PlayerParam::AddJumpPower * Time::DeltaTime();
			m_jumpTimer += Time::DeltaTime();
		}
	}
	//離した
	if (InputManager::Release(KEY_INPUT_SPACE))
	{
		m_isJump = false;
	}
}

void Player::ApplyGravity()
{
	//重力によって下降
	if (!m_isGround)
	{
		m_velocity.y += PlayerParam::Gravity * Time::DeltaTime();
	}
}

void Player::UpdateState()
{
	//着地の瞬間
	if (!m_prevGround && m_isGround)
	{
		//移動していないなら
		if (std::abs(m_velocity.x) < 0.01f)
		{
			m_state = PlayerState::Land;

			return;
		}
	}

	//着地アニメ中
	if (m_state == PlayerState::Land)
	{
		//終了していなければ維持
		if (!m_stepAnim.IsFinished())
		{
			return;
		}
		//終わったので移動か待機状態に
		if (std::abs(m_velocity.x) > 0.01f)
		{
			m_state = PlayerState::Move;
		}
		else
		{
			m_state = PlayerState::Idle;
		}

        return;
	}

	//空中なら優先
	if (!m_isGround)
	{
		//上昇速度が0でないなら上昇モーションに
		if (m_velocity.y < 0)
		{
			m_state = PlayerState::Jump;
		}
		//下降モーションに
		else
		{
			m_state = PlayerState::Fall;
		}

		return;
	}

	//左右移動中
	//移動量が0でなければ移動モーションに
	if (std::abs(m_velocity.x) > 0.01f)
	{
		m_state = PlayerState::Move;
	}
	//待機モーションに
	else
	{
		m_state = PlayerState::Idle;
	}
}

void Player::ChangeAnimation(Animation* anim)
{
	//同じアニメーションならなにもしない
	if (m_currentAnim == anim)
	{
		return;
	}
	//切り替え
	m_currentAnim = anim;
	m_currentAnim->Reset();
}


