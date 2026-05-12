#include "FileManager.h"
#include <fstream>
#include <sstream>

std::string FileManager::ReadText(const std::string& path)
{
    //ファイルを読み込みモードで開く
    std::ifstream file(path);
    //ファイルが読み込めなかった場合、空文字を返す
    if (!file.is_open())
    {
        return "";
    }
    std::stringstream buffer;
    //ファイル内容を全部bufferに流し込む
    buffer << file.rdbuf();

    return buffer.str();
}

bool FileManager::WriteText(const std::string& path, const std::string& text)
{
    //ファイルを書き込みモードで開く
    std::ofstream file(path);
    //ファイルが開けなかった場合
    if (!file.is_open())
    {
        return false;
    }
    //文字列を書き込む
    file << text;

    return true;
}

std::vector<std::string> FileManager::ReadLines(const std::string& path)
{
    //行データを保存する配列
    std::vector<std::string> lines;
    //ファイルを開く
    std::ifstream file(path);
    //開けなかった場合、空配列を返す
    if (!file.is_open())
    {
        return lines;
    }

    //1行目を保存する配列
    std::string line;
    //1行ずつ行列末尾へ追加する
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }
    return lines;
}
