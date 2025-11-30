#include "SceneGameStage3.h"

SceneGameStage3::SceneGameStage3()
{	
	// 画像の読み出し
	_s_GameMain._cgLightBg = LoadGraph("res/bg/fogimage_one_side.png");
	_s_GameMain._cgPosBar = LoadGraph("res/ui/gauge/gauge1.png");
	_s_GameMain._cgBar = LoadGraph("res/ui/gauge/gauge2-1.png");
	//変数初期化
	_s_GameMain._Map3 = 0;
	_s_GameMain.MapChange3(_s_GameMain._Map3);
	_s_GameMain.AddChara(CHARA_TYPE_PLAYER1, 1300, 2100, 1, 0);
	_s_GameMain._gamePause = 0;
	_s_GameMain._StageNo = 3;
	_s_GameMain._moveFlag = 0;
	_s_GameMain.PcClear1 = 0;
	_s_GameMain.PcClear2 = 0;
	_s_GameMain.PcClear3 = 0;
	_s_GameMain.ChangeLockerFlag = 0;
	_s_GameMain.SentenceCnt = 0;
	_s_GameMain._bgm = LoadSoundMem("res/bgm/stage3/BGM_STAGE3.wav");
	_s_GameMain.bgm_volume = 100;		// BGMボリューム初期化
	ChangeVolumeSoundMem(_s_GameMain.bgm_volume, _s_GameMain._bgm);
	PlaySoundMem(_s_GameMain._bgm, DX_PLAYTYPE_BACK, TRUE);
	ColorFadeIn(60);		// フェードインに変更
}

SceneGameStage3::~SceneGameStage3()
{
	DeleteGraph(_s_GameMain._cgBg);
	for (int i = 0; i < _PT_CHARA_ALLNUM_; i++) {
		if (_cgChara[i] != -1) {
			DeleteGraph(_cgChara[i]);
		}
	}
	DeleteSoundMem(_s_GameMain._bgm);
}



void SceneGameStage3::Input()
{

}

void SceneGameStage3::Process()
{
	_s_GameMain.Process();
}

void SceneGameStage3::Draw()
{
	_s_GameMain.Draw();
}

