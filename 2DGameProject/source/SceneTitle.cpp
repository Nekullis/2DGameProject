#include "SceneTitle.h"
#include <Dxlib.h>

SceneTitle::SceneTitle()
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Input()
{
}

void SceneTitle::Process()
{
}

void SceneTitle::Draw()
{
	DrawString(300, 100, "Title", GetColor(255, 255, 255));
}
