#pragma once
#include<vector>
#include <memory>

class Sprite;

struct Frame
{
	//使用画像名
	std::shared_ptr<class Texture> texture;
	//切り取り画像
	int x;
	int y;
	//サイズ
	int width;
	int height;
};

class Animation
{
public:
	Animation();
	//フレーム追加
	void AddFrame(std::shared_ptr<class Texture> texture, int x,int y,int width, int height);
	//FPS設定
	void SetFPS(float fps);
	//更新
	void Update();
	//Spriteへ反映
	void Apply(Sprite& sprite);
	//最初から
	void Reset();

private:
	std::vector<Frame> m_frames;
	int m_currentFrame;
	float m_timer;
	float m_interval;
};

