//----------------------------------------------------------------------
// @filename Player.h
// @author: Fukuma Kyohei
// @explanation
// オブジェクトから派生したプレイアブルキャラクタークラス
//----------------------------------------------------------------------
#pragma once
#include "GameObject.h"
#include "mymath.h"

class TileMap;

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

enum class Direction
{
    Left,
    Right
};

class Player : public GameObject
{
public:
	Player(TileMap* tilemap);
	void Update()override;
    void Draw()override;
	//自身のrectを取得
	MYRECT GetRect() const;
	//当たり判定
	void Collision();

private:
	//タイルマップ情報
	TileMap* m_tilemap;

	//左右入力
	void Input();
	//ジャンプ処理
	void Jump();
	//重力処理
	void ApplyGravity();
	//状態更新
	void UpdateState();
	//アニメーション登録
	void LoadAnimation();
    //接地判定
    void CheckGround();

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

    //左右の向き
    Direction m_direction;

	//アニメーション関連
	Animation m_idleAnim;
	Animation m_walkAnim;
	Animation m_jumpUpAnim;
	Animation m_jumpDownAnim;
	Animation m_stepAnim;

};

