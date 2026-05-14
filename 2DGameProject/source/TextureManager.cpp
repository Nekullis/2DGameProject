#include "TextureManager.h"

//staticメンバ変数定義
std::unordered_map<std::string, std::shared_ptr<Texture>> TextureManager::m_texture;

std::shared_ptr<Texture> TextureManager::Load(const std::string& path)
{
    //既にロード済みか確認
    auto it = m_texture.find(path);
    //キャッシュに存在する場合、それを返す
    if (it != m_texture.end())
    {
        return it->second;
    }

    //新規ロード
    auto texture = std::make_shared<Texture>(path);
    //読み込みが失敗した場合、nullを返す
    if (!texture->IsLoaded())
    {
        return nullptr;
    }

    //キャッシュへ保存
    m_texture[path] = texture;

    return texture;
}

void TextureManager::Clear()
{
    m_texture.clear();
}
