#include "Sprite.h"
#include <Dxlib.h>

Sprite::Sprite(std::shared_ptr<Texture> texture) :m_Texture(texture), m_x(0), m_y(0)
{
}

void Sprite::Draw()
{
	if (!m_Texture)
	{
		return;
	}

	DrawGraph(static_cast<int>(m_x), static_cast<int>(m_y), m_Texture->GetHandle(), TRUE);
}
