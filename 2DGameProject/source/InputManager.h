#pragma once

class InputManager
{
public:
	//初期化
	static void Initialize();
	//更新
	static void Update();
	//キー押下中判定
	static bool Press(int key);
	//キー押下の瞬間
	static bool Trigger(int key);
	//キーを離した瞬間
	static bool Release(int key);

private:
	//今のフレームのキー状態
	static char m_now[256];
	//前フレームのキー状態
	static char m_old[256];
};

