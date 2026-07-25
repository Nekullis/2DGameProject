#include "Collider.h"
#include "mymath.h"

Collider::Collider() :m_position(0, 0), m_width(0), m_height(0), m_radius(0), m_type(ColliderType::Box), m_layer(CollisionLayer::None)
{
}

namespace
{
    bool CanCollide(CollisionLayer a, CollisionLayer b)
    {
        //PlayerとEnemy
        if (a == CollisionLayer::Player && b == CollisionLayer::Enemy) { return true; }
        if (a == CollisionLayer::Enemy && b == CollisionLayer::Player) { return true; }

        return false;
    }
}

bool Collider::IsHit(const Collider& other) const
{
    if (!CanCollide(m_layer, other.m_layer)) { return false; }
	//どちらも矩形の場合
	if (m_type == ColliderType::Box && other.m_type == ColliderType::Box)
	{
		//MYRECTへ変換
		MYRECT a;
		a.x = (int)m_position.x;
		a.y = (int)m_position.y;
		a.w = (int)m_width;
		a.h = (int)m_height;

		MYRECT b;
		b.x = (int)other.m_position.x;
		b.y = (int)other.m_position.y;
		b.w = (int)other.m_width;
		b.h = (int)other.m_height;

		//当たり判定を返す
		return IsHitBox(a,b);
	}
	//どちらも円の場合
	if (m_type == ColliderType::Circle && other.m_type == ColliderType::Circle)
	{
		//中心点距離
		float distance = Vector2D::Distance(m_position, other.m_position);
		//半径合計
		float totalRadius = m_radius + other.m_radius;

		return distance <= totalRadius;
	}
	//自身が円、対象が矩形の場合
	if (m_type == ColliderType::Circle && other.m_type == ColliderType::Box)
	{
		MYCIRCLE c;
		c.x = m_position.x;
		c.y = m_position.y;
		c.r = m_radius;

		MYRECT r;
		r.x = (int)other.m_position.x;
		r.y = (int)other.m_position.y;
		r.w = (int)other.m_width;
		r.h = (int)other.m_height;

		return IsHitCircleBox(c, r);
	}
	//逆の場合
	if (m_type == ColliderType::Box && other.m_type == ColliderType::Circle)
	{
		return other.IsHit(*this);
	}
	return false;
}
