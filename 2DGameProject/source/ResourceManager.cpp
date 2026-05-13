#include "ResourceManager.h"
#include <fstream>

std::unordered_map<std::string, json>ResourceManager::m_jsonCache;

json& ResourceManager::LoadJSON(const std::string& path)
{
    //既に読み込み済みか確認
    auto it = m_jsonCache.find(path);
    //見つかった場合、キャッシュを返却
    if (it != m_jsonCache.end())
    {
        return it->second;
    }

    //未ロードならファイルから読み込み
    std::ifstream file(path);
    //読めなかった場合、空jsonをキャッシュ
    if (!file.is_open())
    {
        m_jsonCache[path] = json();
        return  m_jsonCache[path];
    }

    //JSON読み込み
    json data;
    file >> data;
    //キャッシュへ保存
    m_jsonCache[path] = data;

    //保存したものを返す
    return m_jsonCache[path];
}

void ResourceManager::Clear()
{
    m_jsonCache.clear();
}
