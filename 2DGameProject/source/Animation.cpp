#include "Animation.h"
#include "Sprite.h"

Animation::Animation() :m_currentFrame(0), m_timer(0), m_interval(10)
{
}

void Animation::AddFrame(int x, int y, int width, int height)
{
	//格納するためのFrame構造体を初期化
	Frame frame;
	frame.x = x;
	frame.y = y;
	frame.width = width;
	frame.height = height;

	//末尾に追加
	m_frames.push_back(frame);

}

void Animation::SetFPS(float fps)
{
	m_interval = 60.0 / fps;
}

void Animation::Update()
{
	//アニメーションが入ってない場合、この関数は動作しない
	if (m_frames.empty())
	{
		return;
	}
	//アニメーションタイマー加算
	m_timer++;
	//アニメーションタイマーが規定値を超えた場合、次のフレームに
	if (m_timer >= m_interval)
	{
		m_timer = 0;
		m_currentFrame++;
		if (m_currentFrame >= m_frames.size())
		{
			m_currentFrame = 0;
		}
	}
}

void Animation::Apply(Sprite& sprite)
{
	Frame& frame = m_frames[m_currentFrame];
	sprite.SetRect(frame.x, frame.y, frame.width, frame.height);
}
