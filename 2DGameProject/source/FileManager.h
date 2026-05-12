#pragma once
#include <string>
#include <vector>

class FileManager
{
public:
	//テキストファイルを全部読む
	static std::string ReadText(const std::string& path);

	//テキストファイルへ記載
	static bool WriteText(const std::string& path, const std::string& text);

	//行単位で読む
	static std::vector<std::string> ReadLines(const std::string& path);
};

