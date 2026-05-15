#pragma once
#include<vector>

class Sprite;

struct Frame
{
	int x;
	int y;
	int width;
	int height;
};

class Animation
{
public:
	Animation();
	//フレーム追加
	void AddFrame(int x,int y,int width, int height);
	//FPS設定
	void SetFPS(float fps);
	//更新
	void Update();
	//Spriteへ反映
	void Apply(Sprite& sprite);

private:
	std::vector<Frame> m_frames;
	int m_currentFrame;
	float m_timer;
	float m_interval;
};

