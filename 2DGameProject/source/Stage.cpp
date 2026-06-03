#include "Stage.h"
#include "TileMap.h"
#include "JSONManager.h"

Stage::Stage() :m_playerSpawnX(0), m_playerSpawnY(0), m_GoalX(0), m_GoalY(0)
{
	m_tileMap = std::make_shared<TileMap>();
}

bool Stage::Load(const std::string& path)
{
	//json読み込み
	json data = JSONManager::Read(path);
	if (data.empty())
	{
        printf("Stage json load failed : %s\n", path.c_str());
		return false;
	}

	//マップ読み込み
	std::string mapPath = data["map"];

	//プレイヤー開始位置読み込み
	m_playerSpawnX = data["playerSpawn"]["x"];
	m_playerSpawnY = data["playerSpawn"]["y"];

	//ゴール
	m_GoalX = data["goal"]["x"];
	m_GoalY = data["goal"]["y"];

	//BGM
	m_bgmPath = data["bgm"];

	//マップロード
	m_tileMap = std::make_shared<TileMap>();
	m_tileMap->LoadCSV(mapPath);

	return true;
}

void Stage::Update()
{
}

void Stage::Draw()
{
	m_tileMap->Draw();
}
