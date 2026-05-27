//----------------------------------------------------------------------
// @filename GameObject.h
// @author: Fukuma Kyohei
// @explanation
// オブジェクトから派生したプレイアブルキャラクタークラス
//----------------------------------------------------------------------
#pragma once
#include "GameObject.h"
#include "Animation.h"

//プレイヤー状態
enum class PlayerState
{
	//待機
	Idle,
	//移動
	Move,
	//上昇
	Jump,
	//下降
	Fall,
	//着地
	Land
};

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
	//状態更新
	void UpdateState();
	//アニメーション変更
	void ChangeAnimation(Animation* anim);
	//アニメーション登録
	void LoadAnimation();

	//地面接触中か
	bool m_isGround;
	//前フレーム設置状態
	bool m_prevGround;
	//ジャンプ継続中か
	bool m_isJump;
	//長押し時間
	float m_jumpTimer;
	//落下速度保存
	float m_landingSpeed;

	//プレイヤー状態
	PlayerState m_state;

	//アニメーション関連
	Animation m_idleAnim;
	Animation m_walkAnim;
	Animation m_jumpUpAnim;
	Animation m_jumpDownAnim;
	Animation m_stepAnim;
	//現在再生中のアニメーション
	Animation* m_currentAnim;
};

