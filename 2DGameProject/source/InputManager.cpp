#include "InputManager.h"
#include <cstring>
#include <Dxlib.h>

//staticメンバの定義
char InputManager::m_now[256];
char InputManager::m_old[256];

void InputManager::Initialize()
{
	//配列を全部0にする
	memset(m_now, 0, sizeof(m_now));
	memset(m_old, 0, sizeof(m_old));
}

void InputManager::Update()
{
	//今回の情報を得る前に前フレームとして保存
	memcpy(m_old, m_now, sizeof(m_now));
	//全キー取得
	GetHitKeyStateAll(m_now);
}

bool InputManager::Press(int key)
{
	return m_now[key];
}

bool InputManager::Trigger(int key)
{
	return !m_old[key] && m_now[key];
}

bool InputManager::Release(int key)
{
	return m_old[key] && !m_now[key];;
}
