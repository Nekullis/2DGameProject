#pragma once
#include <memory>
#include "Texture.h"

class Sprite
{
public:
	Sprite(std::shared_ptr<Texture> texture);
	void SetPosition(float x, float y) { m_x = x; m_y = y; }
	void Draw();

private:
	std::shared_ptr<Texture> m_Texture;
	float m_x;
	float m_y;
};

