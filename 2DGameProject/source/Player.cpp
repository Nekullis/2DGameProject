#include "Player.h"
#include "InputManager.h"
#include "PlayerParam.h"
#include "Time.h"
#include <DxLib.h>

Player::Player() :m_isGround(false), m_isJump(false), m_jumpTimer(0), m_landingSpeed(0)
{
	//パラメータ読み込み
	PlayerParam::Load();
}

void Player::Update()
{
	//入力処理
	Input();
	//ジャンプ処理
	Jump();
	//重力処理
	ApplyGravity();
	
	//落下速度保存
	if (m_velocity.y > 0)
	{
		m_landingSpeed = m_velocity.y;
	}

	//更新
	GameObject::Update();
}

void Player::Input()
{
	//適応のキーで左右に移動
	if (InputManager::Press(KEY_INPUT_A))
	{
		m_velocity.x = -PlayerParam::MoveSpeed;
	}
	if (InputManager::Press(KEY_INPUT_D))
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
		m_velocity.y -= PlayerParam::Gravity * Time::DeltaTime();
	}
}
