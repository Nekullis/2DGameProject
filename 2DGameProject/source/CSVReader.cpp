#include "CSVReader.h"
#include <fstream>
#include <sstream>

int CSVReader::csv_width = 0;
int CSVReader::csv_height = 0;

std::vector<std::vector<std::string>> CSVReader::ReadCSV(const std::string& path)
{
	//csv全体を保存する2次元配列
	std::vector<std::vector<std::string>> data;
	//CSVファイルを開く
	std::ifstream file(path);
	//開けなかった場合、空データを返す
	if (!file.is_open())
	{
		return data;
	}

	//CSVの1行を保存する変数
	std::string line;
	//ファイルから1行ずつ読む
	while (std::getline(file, line))
	{
		//1行分のデータを保存する配列
		std::vector<std::string> row;
		std::stringstream ss(line);
		//カンマで区切られた1要素
		std::string cell;
		//カンマ区切りで文字列取得
		while (std::getline(ss, cell, ','))
		{
			//配列の末尾に追加
			row.push_back(cell);
		}
		//1行分をdataに追加
		data.push_back(row);
	}
    csv_width = data.empty() ? 0 : static_cast<int>(data[0].size());
    csv_height = static_cast<int>(data.size());
	return data;
}
