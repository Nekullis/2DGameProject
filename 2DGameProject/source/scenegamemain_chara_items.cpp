#define	_CRT_SECURE_NO_WARNINGS		// sprintf()を使うため
#include "DxLib.h"
#include "winmain.h"
#include "gamemain.h"
#include "mymath.h"
#include "mydraw.h"
#include "s_gamemain.h"
#include "s_gameover.h"


int		SceneGameMain::CharaProcessItems(int i) {
	int motChg = -1;
	return motChg;
}

int		SceneGameMain::CharaDamageItems(int i, int j) {
	int motChg = -1;
	// アイテムによって効果を変える
	if(SentenceNo != 0)
	{
		SentenceCnt = 180;
	}
	switch (_gChara[i].type) {
	case CHARA_TYPE_ITEM_POINT_0:	//	ナイフを拾う
		if (_gChara[j].type == CHARA_TYPE_PLAYER1)
		{
			if(_KnifeCnt != 2)
			{
				PlaySoundMem(_se[SE_ITEM_KNIFE], DX_PLAYTYPE_BACK);
				SentenceFlag = 1;
				_KnifeCnt = 2;
			}
		}
		break;

	case CHARA_TYPE_ITEM_POINT_1:	// 鍵を拾う
		if (_gChara[j].type == CHARA_TYPE_PLAYER1)
		{
			PlaySoundMem(_se[SE_ITEM_KEY], DX_PLAYTYPE_BACK);
			SentenceFlag = 1;
			_KeyCnt = 2;
		}
		break;

	case CHARA_TYPE_ITEM_POINT_2:	//ライフを増やす
		if (_gChara[j].type == CHARA_TYPE_PLAYER1)
		{
			PlaySoundMem(_se[SE_ITEM_HEAL], DX_PLAYTYPE_BACK);
			SentenceFlag = 1;
			_HealCnt = 1;
			_gChara[j].hp = 3;
		}
		break;

	case CHARA_TYPE_ITEM_POINT_4:	// イベント用 ステージとイベントフラグで操作
		switch (_StageNo)
		{
		case 2:
			if (_gChara[j].type == CHARA_TYPE_PLAYER1)
			{
				if (SceneEv == 5)
				{
					//魚たちが出現する
					AddChara(CHARA_TYPE_ENEMY_3, 1000, 900, -1, 0);
					AddChara(CHARA_TYPE_ENEMY_3, 900, 1100, -1, 0);
					AddChara(CHARA_TYPE_ENEMY_3, 1100, 1300, -1, 0);
					AddChara(CHARA_TYPE_ENEMY_1, 800, 1300, -1, 0);
					AddChara(CHARA_TYPE_ENEMY_5, 2550, 1000, 1, 0);
					AddChara(CHARA_TYPE_ENEMY_5, 2500, 1100, 1, 0);
					AddChara(CHARA_TYPE_ENEMY_5, 2400, 900, 1, 0);
					PlaySoundMem(_se[SE_EVENT_ALERT], DX_PLAYTYPE_LOOP, TRUE);
					SceneEv = 6;
				}
				else if (SceneEv >= 11)
				{	
					AddChara(CHARA_TYPE_ENEMY_4, 7000, 1000, _gChara[j].arrow, 0);
				}
			}
			break;

		case 3:
			if (_gChara[j].type == CHARA_TYPE_ENEMY_4)
			{
				if (_gChara[j].y < 1500)
				{
					//ボスの昇るフラグが立つ
					useEnHierarchy = 2;
				}
				else
				{	//ボスの降りるフラグが立つ
					useEnHierarchy = 1;
				}
				//カウントでもう一度ITEM_POINT_4を出すフラグ
				ItemCntFlag = 1;
			}
			else if (_gChara[j].type == CHARA_TYPE_PLAYER1)
			{
				//ITEM_POINT_4をとったのがボス以外ならばもう一度出現させる
				AddChara(CHARA_TYPE_ITEM_POINT_4, _gChara[i].x, _gChara[i].y, _gChara[i].arrow, 0);
			}
			break;
		}
		break;
	}
	DeleteChara(i);
	return motChg;
}
