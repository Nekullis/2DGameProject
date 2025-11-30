#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#include "gamemain.h"
#include "s_gameover.h"
#include "s_gametitle.h"
#include <stdio.h>
#include "SceneGameStage1.h"
#include "SceneGameStage2.h"
#include "SceneGameStage3.h"

SceneGameMain _s_GameMain;

SceneGameOver::SceneGameOver(int gameovernum) 
{
	_bgm = LoadSoundMem("res/bgm/gameover/BGMbadend.mp3");		// BGM音源
	PlaySoundMem(_bgm, DX_PLAYTYPE_LOOP, TRUE);		// BGMループ再生
	char size[64];
	for (int i = 1; i <= 53; i++)
	{
		sprintf(size, "res/gameover/go%d.png", i);
		_cgEndBg[i - 1] = LoadGraph(size);
	}
	bgEndcnt = 0;
	bgEndanicnt = 0;
	_Endstep = 0;

	StageNom = gameovernum;
	ColorFadeIn(60);
}

SceneGameOver::~SceneGameOver() 
{
	for (int i = 0; i < 53; i++)
	{
		DeleteGraph(_cgEndBg[i]);
	}
	// ゲームタイトル画像をメモリから削除
	DeleteSoundMem(_bgm);			// ゲームオーバー画像をメモリから削除	
}

void SceneGameOver::Input() 
{
	// 何もしない
}

void SceneGameOver::Process() 
{
	switch (_Endstep) {
	case 0:
		// フェードイン開始
		_Endstep++;
		break;
	case 1:
		if (IsColorFade() == 0) 
		{
			// フェードイン終了
			_Endstep++;
		}
		break;
	case 2:
		// 通常処理
		if (gPad._trg & PAD_INPUT_4) 
		{
			// フェードアウト開始
			ColorFadeOut(0, 0, 0, 60);
			_Endstep++;
		}
		break;
	case 3:
		if (IsColorFade() == 0) 
		{

			// フェードアウト終了
			// 死んだステージで最初から
			if (StageNom == 1)
			{
				Scene* scene = new SceneGameStage1();
				ChangeScene(scene);
			}
			if (StageNom == 2)
			{
				Scene* scene = new SceneGameStage2();
				ChangeScene(scene);
			}
			if (StageNom == 3)
			{
				Scene* scene = new SceneGameStage3();
				ChangeScene(scene);
			}
		}
		break;
	}

	//アニメーションカウント
	bgEndcnt++;
	bgEndanicnt= bgEndcnt / 6 % 53;
}

void SceneGameOver::Draw() 
{
	DrawGraph(0, 0, _cgEndBg[bgEndanicnt], FALSE);		// ゲームオーバー画像を描画
}