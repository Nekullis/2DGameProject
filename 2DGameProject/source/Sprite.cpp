#include "Sprite.h"
#include <Dxlib.h>
#include "camera.h"

Sprite::Sprite(std::shared_ptr<Texture> texture)
	:m_Texture(texture), m_x(0), m_y(0), m_scaleX(1.0f), m_scaleY(1.0f), m_angle(0), m_centerX(0), m_centerY(0),
	m_rectX(0), m_rectY(0), m_width(64), m_height(64), m_flipX(true)
{
}

void Sprite::Draw()
{
	if (!m_Texture)
	{
		return;
	}
    DrawRectRotaGraph3F(
        m_x + m_centerX - Camera::w_camera._pos.x, m_y + m_centerY - Camera::w_camera._pos.y,
        m_rectX, m_rectY, m_width, m_height, m_centerX, m_centerY, 
        m_scaleX, m_scaleY, m_angle, m_Texture->GetHandle(), TRUE);

}

void Sprite::SetFlipX(bool flip)
{
    m_scaleX = flip ? -1.0f : 1.0f;
}
