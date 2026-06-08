//----------------------------------------------------------------------
// @filename GameObject.h
// @author: Fukuma Kyohei
// @explanation
// オブジェクトの基底クラス
//----------------------------------------------------------------------
#pragma once
#include <memory>
#include "Vector2D.h"
#include "Sprite.h"
#include "Collider.h"

class GameObject
{
public:
	//コンストラクタ
	GameObject();
	//仮想デストラクタ
	virtual ~GameObject();
	//更新
	virtual void Update();
	//描画
	virtual void Draw();
	//死亡フラグ
	void Destory();

	//座標設定
	void SetPosition(const Vector2D& pos);
	//座標取得
	Vector2D GetPosition() const { return m_position; }
    //移動速度取得
    Vector2D GetVelocity() const { return m_velocity; }
	bool IsActive() const { return m_isActive; }

protected:
	//座標
	Vector2D m_position;
	//移動速度
	Vector2D m_velocity;
	//使用スプライト
	std::shared_ptr<Sprite> m_sprite;
	//当たり判定
	Collider m_collider;
	//生存フラグ
	bool m_isActive;

};

