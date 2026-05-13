#pragma once
#include <nlohmann/json.hpp>

//json型の別名
using json = nlohmann::json;

class JSONManager
{
public:
	//JSONファイルを読む
	static json Read(const std::string& path);

	//JSONファイルへ書く
	static bool Write(const std::string& path, const json& data);
};

