#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#include "winmain.h"
#include "gamemain.h"
#include "s_gametitle.h"
#include "s_gamemain.h"
#include"s_gameopening.h"
#include <stdio.h>

SceneGameTitle::SceneGameTitle() {
		// ゲームタイトル画像
	SetUseASyncLoadFlag(TRUE);
	char size[64];
	_step = 0;
	for(int i = 1; i <= 153; i++)
	{
		sprintf(size, "res/title/png_title/%d.png", i);
		_cgTitleBg[i-1] = LoadGraph(size);
	}
	_cgLogo = LoadGraph("res/title/AMG_logo.png");
	bgcnt = 0;
	bganicnt = 0;

	SetUseASyncLoadFlag(FALSE);
	_bgm = LoadSoundMem("res/bgm/title/BGM1.mp3");		// BGM音源
	bgm_volume = 128;		// BGMボリューム初期化
	ChangeVolumeSoundMem(bgm_volume, _bgm);
	ColorMask(0, 0, 0, 255);
	ColorFadeIn(60);
}

SceneGameTitle::~SceneGameTitle() {
	for(int i = 0; i < 153; i++)
	{
		DeleteGraph(_cgTitleBg[i]);
	}
	// ゲームタイトル画像をメモリから削除
	DeleteSoundMem(_bgm);		// BGMをメモリから削除

}

void SceneGameTitle::Input() {
	// 何もしない
}

void SceneGameTitle::Process() {

	
	switch(_step) {

	case 0:
		_step++;
		break;
	case 1:
		//AMGロゴ描画中
		if(IsColorFade() == 0) {
			WaitTimer(3000);
			_step++;
		}
		break;
	case 2:
		//フェードアウト
		ColorFadeOut(0, 0, 0, 60);
		_step++;
		break;
	case 3:
		//裏画面で画像切り替え
		if (IsColorFade() == 0) {
			_cgLogo = LoadGraph("res/title/logo.png");
			_step++;
		}
		break;
	case 4:
		// フェードイン開始
		ColorFadeIn(60);

		_step++;
		break;
	case 5:
		//製作チームロゴ描画中
		if (IsColorFade() == 0)
		{
			// フェードイン終了
			WaitTimer(3000);
			_step++;
		}
		break;
	case 6:
		//フェードアウト
		ColorFadeOut(0, 0, 0, 60);
		_step++;
		break;
	case 7:
		//フェードアウト終了後画像を削除
		if (IsColorFade() == 0) 
		{
			DeleteGraph(_cgLogo);
			_step++;
		}
		break;
	case 8:
		//先に音楽のみ再生してフェードイン
		PlaySoundMem(_bgm, DX_PLAYTYPE_BACK, TRUE);
		ColorFadeIn(120);
		_step++;
		break;
	case 9:
		//タイトル画像描画中
		if (IsColorFade() == 0)
		{
			// フェードイン終了
			_step++;
		}
		break;
	case 10:
		// 通常処理
		
		if(gPad._trg & PAD_INPUT_4) 
		{
			// フェードアウト開始
			ColorFadeOut(0, 0, 0, 30);
			_step++;
		}
		break;
	case 11:
		if(IsColorFade() == 0) 
		{
			// フェードアウト終了、シーン切り替え
			Scene* scene = new SceneGameOpening();
			ChangeScene(scene);
		}
		break;
	}
	//アニメーションカウント
	bgcnt++;
	bganicnt = bgcnt/6 % 153;
}

void SceneGameTitle::Draw() 
{
	//ロゴ描画
	DrawGraph(0, 0, _cgLogo, TRUE);
	//タイトル画面描画
	if (_step > 7)
	{
		DrawGraph(0, 0, _cgTitleBg[bganicnt], TRUE);
	}

}