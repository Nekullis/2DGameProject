#include "Time.h"
#include <Dxlib.h>
#include <algorithm>

int Time::m_prevTime = 0;
float Time::m_deltaTime = 0;
float Time::m_fps = 0;

void Time::Initialize()
{
	m_prevTime = GetNowCount();
}

void Time::Update()
{
	int current = GetNowCount();
	//ms
	float elapsed = static_cast<float>(current - m_prevTime);
    elapsed = MIN(elapsed, (1000.0f / 60.0f) * 6);
	//•b•ÏŠ·
	m_deltaTime = elapsed / 1000.0f;

	//FPS
	if (elapsed > 0)
	{
		m_fps = 1.0f / m_deltaTime;
	}
	m_prevTime = current;
}
