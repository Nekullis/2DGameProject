#include "Animation.h"
#include "Sprite.h"
#include "Time.h"

Animation::Animation() :m_currentFrame(0), m_timer(0), m_interval(1.0f / 8.0f), m_isLoop(true), m_isFinished(false)
{
}

void Animation::AddFrame(std::shared_ptr<Texture> texture, int x, int y, int width, int height)
{
	//格納するためのFrame構造体を初期化
	Frame frame;
	frame.texture = texture;
	frame.x = x;
	frame.y = y;
	frame.width = width;
	frame.height = height;

	//末尾に追加
	m_frames.push_back(frame);

}

void Animation::SetFPS(float fps)
{
	m_interval = 1.0f / fps;
}

void Animation::Update()
{
	//アニメーションが入ってない場合、この関数は動作しない
	if (m_frames.empty())
	{
		return;
	}
	//終了済みなら止める
	if (m_isFinished)
	{
		return;
	}
	//アニメーションタイマー加算
	m_timer += Time::DeltaTime();
	//アニメーションタイマーが規定値を超えた場合、次のフレームに
	if (m_timer >= m_interval)
	{
		m_timer = 0;
		m_currentFrame++;
		//最後まで行った場合
		if (m_currentFrame >= m_frames.size())
		{
			if (m_isLoop)
			{
				m_currentFrame = 0;
			}
			else
			{
				//最後固定
				m_currentFrame = static_cast<int>(m_frames.size() - 1);
				m_isFinished = true;
			}
		}
	}
}

void Animation::Apply(Sprite& sprite)
{
	Frame& frame = m_frames[m_currentFrame];
	//使用画像変更
	sprite.SetTexture(frame.texture);
	sprite.SetRect(frame.x, frame.y, frame.width, frame.height);
}

void Animation::Reset()
{
	m_currentFrame = 0;
	m_timer = 0;
	m_isFinished = false;
}

