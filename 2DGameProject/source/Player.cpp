#include "Player.h"
#include "InputManager.h"
#include "PlayerParam.h"
#include "Time.h"
#include <DxLib.h>
#include <cmath>

Player::Player() :m_isGround(false), m_isJump(false), m_jumpTimer(0), m_landingSpeed(0), m_state(PlayerState::Idle), m_currentAnim(nullptr)
{
	//パラメータ読み込み
	PlayerParam::Load();
	LoadAnimation();
	m_currentAnim = &m_idleAnim;
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
	m_idleAnim.SetFPS(8);
	//移動
	for (int i = 0; i < 6; i++)
	{
		m_walkAnim.AddFrame(motion_walk, i * 150, 0, 150, 100);
	}
	m_walkAnim.SetFPS(8);
	//上昇
	for (int i = 0; i < 7; i++)
	{
		m_jumpUpAnim.AddFrame(motion_jump, i * 150, 0, 150, 100);
	}
	m_jumpUpAnim.SetFPS(8);
	//下降
	for (int i = 0; i < 5; i++)
	{
		m_jumpDownAnim.AddFrame(motion_jump, i * 150, 100, 150, 100);
	}
	m_jumpDownAnim.SetFPS(8);
	//着地
	for (int i = 0; i < 8; i++)
	{
		m_stepAnim.AddFrame(motion_step, i * 150, 0, 150, 100);
	}
	m_stepAnim.SetFPS(8);

}

void Player::Update()
{
	//入力処理
	Input();
	//ジャンプ処理
	Jump();
	//重力処理
	ApplyGravity();
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
	}

	//アニメーション処理
	if (m_currentAnim && m_sprite)
	{
		m_currentAnim->Update();
		m_currentAnim->Apply(*m_sprite);
	}

	//更新
	GameObject::Update();
}

void Player::Input()
{
	//毎フレーム初期化
	m_velocity.x = 0;
	//適応のキーで左右に移動
	if (InputManager::Press(KEY_INPUT_A) && !InputManager::Press(KEY_INPUT_D))
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
		m_velocity.y = PlayerParam::JumpPower;
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
			m_velocity.y += PlayerParam::AddJumpPower * Time::DeltaTime();
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


