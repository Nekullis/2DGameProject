#include "Texture.h"
#include <Dxlib.h>

Texture::Texture(const std::string& path) :m_path(path), m_handle(-1), m_loaded(false)
{
	m_handle = LoadGraph(path.c_str());
	m_loaded = (m_handle != -1);
}

Texture::~Texture()
{
	//—LŒø‚Èƒnƒ“ƒhƒ‹‚È‚çíœ
	if (m_handle != -1)
	{
		DeleteGraph(m_handle);
	}
}
