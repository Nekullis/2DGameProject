#pragma once
#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class ResourceManager
{
public:
	//Json取得
	static json& LoadJSON(const std::string& path);
	static void Clear();

private:
	//キャッシュ用
	static std::unordered_map<std::string, json> m_jsonCache;
};

