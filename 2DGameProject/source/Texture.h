#pragma once
#include <string>

class Texture
{
public:
	Texture(const std::string& path);
	~Texture();
	//読み込み確認
	bool IsLoaded() const { return m_loaded; }
	//画像ハンドル取得
	int GetHandle() const { return m_handle; }

private:
	//ファイルパス
	std::string m_path;
	//画像ハンドル
	int m_handle;
	//読み込み成功グラフ
	bool m_loaded;
};
