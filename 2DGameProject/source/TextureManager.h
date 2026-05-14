#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include "Texture.h"

class TextureManager
{
public:
	static std::shared_ptr<Texture> Load(const std::string& path);
	static void Clear();

private:
	static std::unordered_map<std::string, std::shared_ptr<Texture>> m_texture;
};

