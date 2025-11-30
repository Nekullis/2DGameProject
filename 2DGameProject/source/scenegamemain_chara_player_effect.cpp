#define	_CRT_SECURE_NO_WARNINGS		// sprintf()を使うため
#include "DxLib.h"
#include "winmain.h"
#include "gamemain.h"
#include "mymath.h"
#include "mydraw.h"
#include "s_gamemain.h"
#include "s_gameover.h"

int	SceneGameMain::CharaProcessPlayerEffect(int i) {
	int motChg = -1;

	switch (_gChara[i].type) {
	case CHARA_TYPE_PLEFFECT_KNIFE:
	{	// 向いている方向に少しずつ進む
		int mx = 0;
		int speed = 20;

		mx = _gChara[i].arrow * speed;

		_gChara[i].x += mx;

		// 移動可能か？当たり判定。移動不可なら中で位置調整
		if (CheckCharaMove(i, mx, 0) == 1) {
			// プレイヤーが持っていなければそこに落ちる
			if(_KnifeCnt != 2)
			{
				AddChara(CHARA_TYPE_ITEM_POINT_0, _gChara[i].x, _gChara[i].y, _gChara[i].arrow,1);
				DeleteChara(i);
			}
			else
			{
				DeleteChara(i);
			}
		}
		break;
	}
	}

	return motChg;
}

int	SceneGameMain::CharaDamagePlayerEffect(int i, int j) {
	int motChg = -1;

	return motChg;
}
