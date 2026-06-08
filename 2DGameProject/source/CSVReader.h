#pragma once
#include <string>
#include <vector>

class CSVReader
{
public:
	static std::vector<std::vector<std::string>> ReadCSV(const std::string& path);
    static int csv_width;
    static int csv_height;
};

