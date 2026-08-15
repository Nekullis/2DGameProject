//----------------------------------------------------------------------
// @filename Stage.h
// @author: Fukuma Kyohei
// @explanation
// ステージの構成に関するクラス
//----------------------------------------------------------------------
#pragma once
#include <memory>
#include <string>
#include <vector>

class TileMap;
class CaveBackground;

struct EnemySpawnData
{
    std::string type;
    float x;
    float y;
};

class Stage
{
public:
	Stage();
	//ステージ読み込み
	bool Load(const std::string& path);
	//更新
	void Update();
	//描画
	void Draw();
	//ゲッター
	TileMap* GetTileMap()const { return m_tileMap.get(); }
	float GetPlayerSpawnX()const { return m_playerSpawnX; }
	float GetPlayerSpawnY()const { return m_playerSpawnY; }
    const std::vector<EnemySpawnData>& GetEnemySpawns() const { return m_enemySpawns; }

private:
	//ステージ名
	std::string m_stageName;
	//マップ
	std::shared_ptr<TileMap> m_tileMap;
    //背景
    std::shared_ptr<CaveBackground> m_backGround;
	//プレイヤー開始位置
	float m_playerSpawnX;
	float m_playerSpawnY;
    //敵出現位置
    std::vector<EnemySpawnData> m_enemySpawns;
	//BGM
	std::string m_bgmPath;
	//ゴール座標
	float m_GoalX;
	float m_GoalY;

};

