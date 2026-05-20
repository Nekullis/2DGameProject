#include "Collider.h"
#include "mymath.h"

Collider::Collider() :m_position(0, 0), m_width(0), m_height(0), m_radius(0), m_type(ColliderType::Box)
{
}

bool Collider::IsHit(const Collider& other)
{
	//‚Ç‚¿‚ç‚àBox‚Ìê‡
	if (m_type == ColliderType::Box && other.m_type == ColliderType::Box)
	{
		//MYRECT‚Ö•ÏŠ·
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

		//“–‚½‚è”»’è‚ğ•Ô‚·
		return IsHitBox(a.x, a.y, a.w, a.h, b.x, b.y, b.w, b.h);
	}
	if (m_type == ColliderType::Circle && other.m_type == ColliderType::Circle)
	{
		//’†S“_‹——£
		float distance = Vector2D::Distance(m_position, other.m_position);
		//”¼Œa‡Œv
		float totalRadius = m_radius + other.m_radius;

		return distance <= totalRadius;
	}
	return false;
}
