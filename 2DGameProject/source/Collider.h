//----------------------------------------------------------------------
// @filename Collider.h
// @author: Fukuma Kyohei
// @explanation
// オブジェクトが持つ当たり判定に関するクラス
//----------------------------------------------------------------------
#pragma once
#include "Vector2D.h"

enum class ColliderType
{
	Box,
	Circle
};

enum class CollisionLayer
{
    None,
    Player,
    Enemy,
    Stage,
    Gorl
};

class Collider
{
public:
	Collider();
	//当たり判定
	bool IsHit(const Collider& other) const;
	//座標設定
	void SetPosition(const Vector2D& pos) { m_position = pos; }
	//サイズ設定
	void SetSize(float width, float height) { m_width = width; m_height = height; }
	//円半径
	void SetRadius(float radius) { m_radius = radius; }
	//タイプ変更
	void SetType(ColliderType type) { m_type = type; }
	//座標取得
	Vector2D GetPosition() const { return m_position; }
	//横幅
	float GetWidth() const { return m_width; }
	//高さ
	float GetHeight() const { return m_height; }
    //レイヤー取得
    CollisionLayer GetLayer() const { return m_layer; }
    //レイヤー設定
    void SetLayer(CollisionLayer layer) { m_layer = layer; }

private:
	//左上座標
	Vector2D m_position;
	//横幅
	float m_width;
	//高さ
	float m_height;
	//Circle用
	float m_radius;
	//当たり判定タイプ
	ColliderType m_type;
    //当たり判定レイヤー
    CollisionLayer m_layer;

};

