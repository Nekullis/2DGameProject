#pragma once
#define MIN(a, b) ((a) < (b) ? (a) : (b))

class Time
{
public:
	static void Initialize();
	static void Update();
	//前フレームから何秒経過したか
	static float DeltaTime() { return m_deltaTime; }
	//現在FPS
	static float FPS() { return m_fps; }

private:
	static int m_prevTime;
	static float m_deltaTime;
	static float m_fps;
};

