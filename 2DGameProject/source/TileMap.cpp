#include "TileMap.h"
#include "CSVReader.h"
#include "Texture.h"
#include <Dxlib.h>
#include "camera.h"

TileMap::TileMap() :m_tileSize(64)
{
	m_tileTexture = std::make_shared<Texture>("res/map/MapChip.png");
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

    m_MapWidth = reader.csv_width;
    m_Mapheight = reader.csv_height;
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
            MATRIX m = MGetTranslate(VECTOR(Camera::w_camera._pos.x, 0, 0));
            VECTOR pos = VTransform(VECTOR(x, y, 0), m);
            DrawGraph(x * m_tileSize - Camera::w_camera._pos.x, y * m_tileSize - Camera::w_camera._pos.y, m_tileTexture->GetHandle(), TRUE);
		}
	}
}

bool TileMap::IsWall(int x, int y) const
{
	//範囲外チェック
	if (x < 0 || x >= m_mapData[0].size())
	{
		return false;
	}
	if (y < 0 || y >= m_mapData.size())
	{
		return false;
	}
	
	int tile = m_mapData[y][x];

	return tile == 1;
}

std::vector<MYRECT> TileMap::GetWallRects() const
{
	//戻り値
	std::vector<MYRECT> walls;

	//全タイル走査
	for (int y = 0; y < m_mapData.size(); y++)
	{
		for (int x = 0; x < m_mapData[y].size(); x++)
		{
			//壁じゃない場合
			if (m_mapData[y][x] != 1)
			{
				continue;
			}
			//Rect作成
            MYRECT rect{};
			rect.x = x * m_tileSize;
			rect.y = y * m_tileSize;
			rect.w = m_tileSize;
			rect.h = m_tileSize;
			//追加
			walls.push_back(rect);
		}
	}

	return walls;
}
