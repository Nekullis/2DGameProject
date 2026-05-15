#include "Time.h"
#include <Dxlib.h>

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
	int elapsed = current - m_prevTime;
	//•b•ÏŠ·
	m_deltaTime = elapsed / 1000.0f;
	//FPS
	if (elapsed > 0)
	{
		m_fps = 1.0f / m_deltaTime;
	}
	m_prevTime = current;
}
