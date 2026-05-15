#pragma once
#include <memory>
#include "Texture.h"

class Sprite
{
public:
	Sprite(std::shared_ptr<Texture> texture);
	void SetPosition(float x, float y) { m_x = x; m_y = y; }
	void SetScale(float x, float y) { m_scaleX = x; m_scaleY = y;}
	void SetRotation(float angle) { m_angle = angle; }
	void SetCenter(float x, float y) { m_centerX = x; m_centerY = y; }
	void Draw();

private:
	//g—p‰æ‘œ
	std::shared_ptr<Texture> m_Texture;
	//À•W
	float m_x;
	float m_y;
	//Šg‘å—¦
	float m_scaleX;
	float m_scaleY;
	//‰ñ“]Šp
	float m_angle;
	//‰ñ“]’†S
	float m_centerX;
	float m_centerY;
};

