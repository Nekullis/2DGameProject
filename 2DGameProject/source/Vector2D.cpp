#include "Vector2D.h"

Vector2D::Vector2D() :x(0), y(0)
{
}

Vector2D::Vector2D(float x, float y) :x(x), y(y)
{
}

Vector2D Vector2D::operator+(const Vector2D& other) const
{
	return { x + other.x, y + other.y };
}

Vector2D Vector2D::operator-(const Vector2D& other) const
{
	return { x - other.x, y - other.y };
}

Vector2D Vector2D::operator*(const float value) const
{
	return { x * value, y * value };
}

Vector2D Vector2D::operator+=(const Vector2D& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

float Vector2D::Length() const
{
	//O•½•û‚Ì’è—‚æ‚è
	return { sqrt(x * x + y * y) };
}

Vector2D Vector2D::Normalize() const
{
	float len = Length();
	//ƒ[ƒœZ–h~
	if (len == 0)
	{
		return {0,0};
	}

	return { x / len, y / len };
}

float Vector2D::Distance(const Vector2D& a, const Vector2D& b)
{
	return (b-a).Length();
}

float Vector2D::Dot(const Vector2D& a, const Vector2D& b)
{
	return a.x * b.x + a.y * b.y;
}
