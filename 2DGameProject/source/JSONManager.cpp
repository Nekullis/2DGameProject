#include "JSONManager.h"
#include <fstream>

json JSONManager::Read(const std::string& path)
{
    //ファイルを開く
    std::ifstream file(path);
    //開けなかった場合、空jsonを返す
    if (!file.is_open())
    {
        return json();
    }
    
    json data;
    //ファイル内容をJSONへ
    file >> data;

    return data;
}

bool JSONManager::Write(const std::string& path, const json& data)
{
    //ファイルを開く
    std::ofstream file(path);
    //開けなくなった場合
    if (!file.is_open())
    {
        return false;
    }
    file << data.dump(4);

    return true;
}
