#include "TileMap.h"
#include "CSVReader.h"
#include "Texture.h"
#include <Dxlib.h>

TileMap::TileMap() :m_tileSize(64)
{
	m_tileTexture = std::make_shared<Texture>("res/map/.png");
}

bool TileMap::LoadCSV(const std::string& path)
{
	CSVReader reader;
	//stringの2次元配列
	auto csv = reader.ReadCSV(path);
	//空なら失敗
	if (csv.empty())
	{
		return false;
	}
	
	//intへ変換
	for (auto& row : csv)
	{
		std::vector<int> mapRow;
		for (auto& cell : row)
		{
			mapRow.push_back(std::stoi(cell));
		}
		m_mapData.push_back(mapRow);
	}
	return true;
}

void TileMap::Draw()
{
	//y行
	for (int y = 0; y < m_mapData.size(); y++)
	{
		//x列
		for (int x = 0; x < m_mapData[y].size(); x++)
		{
			int tile = m_mapData[y][x];
			//0は空
			if (tile == 0)
			{
				continue;
			}
			//タイル描画
			DrawGraph(x * m_tileSize, y * m_tileSize, m_tileTexture->GetHandle(), TRUE);
		}
	}
}
