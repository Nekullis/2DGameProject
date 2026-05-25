//----------------------------------------------------------------------
// @filename GameObject.h
// @author: Fukuma Kyohei
// @explanation
// オブジェクトから派生したプレイアブルキャラクタークラス
//----------------------------------------------------------------------
#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	void Update()override;

private:
	//左右入力
	void Input();
	//ジャンプ処理
	void Jump();
	//重力処理
	void ApplyGravity();

	//地面接触中か
	bool m_isGround;
	//ジャンプ継続中か
	bool m_isJump;
	//長押し時間
	float m_jumpTimer;
	//落下速度保存
	float m_landingSpeed;
};

