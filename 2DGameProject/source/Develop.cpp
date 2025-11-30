#include"s_gamemain.h"
#include "SceneGameStage2.h"
#include "SceneGameStage3.h"


void SceneGameMain::Develop()
{
	// 開発用
	if (gPad._trg & PAD_INPUT_7) {	// [a]キーでコリジョン表示切替
		_debugViewCollision = 1 - _debugViewCollision;	// 0と1を入れ替える
	}
	if (gPad._key & PAD_INPUT_5) {	// [s]キーを押しながら上下左右でカメラ位置移動
		int speed = 8;
		if (gPad._key & PAD_INPUT_LEFT) { _cam._pos.x -= speed; }
		if (gPad._key & PAD_INPUT_RIGHT) { _cam._pos.x += speed; }
		if (gPad._key & PAD_INPUT_UP) { _cam._pos.y -= speed; }
		if (gPad._key & PAD_INPUT_DOWN) { _cam._pos.y += speed; }
	}
	if (gPad._key & PAD_INPUT_6) {	// [d]キーを押しながら左右で回転、上下で拡大縮小
		if (gPad._key & PAD_INPUT_UP) { _cam._scale -= 0.01f; }
		if (gPad._key & PAD_INPUT_DOWN) { _cam._scale += 0.01f; }
	}

	if (_debugViewCollision != 0)
	{
		if (gPad._trg & PAD_INPUT_8)
		{
			Scene* scene = new SceneGameStage2();
			ChangeScene(scene);
		}
		if (gPad._trg & PAD_INPUT_10)
		{
			Scene* scene = new SceneGameStage3();
			ChangeScene(scene);
		}
		if (gPad._trg & PAD_INPUT_2)
		{
			_KeyCnt = 2;
			SceneEv = 5;
		}
		if (gPad._trg & PAD_INPUT_5)
		{
			_KnifeCnt = 2;
		}
	}
}