#include "Sprite.h"
#include <Dxlib.h>

Sprite::Sprite(std::shared_ptr<Texture> texture)
	:m_Texture(texture), m_x(0), m_y(0), m_scaleX(1.0f), m_scaleY(1.0f), m_angle(0), m_centerX(0), m_centerY(0),
	m_rectX(0), m_rectY(0), m_width(64), m_height(64)
{
}

void Sprite::Draw()
{
	if (!m_Texture)
	{
		return;
	}

	DrawRectRotaGraph2((int)m_x, (int)m_y, m_rectX, m_rectY, m_width, m_height, (int)m_centerX, (int)m_centerY, m_scaleX, m_angle, m_Texture->GetHandle(), TRUE);
}
