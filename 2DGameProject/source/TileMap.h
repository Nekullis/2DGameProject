//----------------------------------------------------------------------
// @filename TileMap.h
// @author: Fukuma Kyohei
// @explanation
// マップデータ用クラス
//----------------------------------------------------------------------
#pragma once
#include <vector>
#include <memory>
#include <string>

class Texture;

class TileMap
{
public:
	TileMap();
	//csv読み込み
	bool LoadCSV(const std::string& path);
	//描画
	void Draw();
	//壁判定
	bool IsWall(int x, int y)const;

private:
	//マップデータ
	std::vector<std::vector<int>> m_mapData;
	//タイル画像
	std::shared_ptr<Texture> m_tileTexture;
	//タイルサイズ
	int m_tileSize;
};

