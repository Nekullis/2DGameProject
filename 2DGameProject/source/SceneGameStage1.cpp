#include "SceneGameStage1.h"

SceneGameStage1::SceneGameStage1() 
{
	// キャラ画像配列の初期化
	// 画像の読み出し
	//プレイヤー
	_s_GameMain._cgLightBg = LoadGraph("res/bg/fogimage_one_side.png");
	_s_GameMain._cgPosBar = LoadGraph("res/ui/gauge/gauge1.png");
	_s_GameMain._cgBar = LoadGraph("res/ui/gauge/gauge2-1.png");
	_s_GameMain._Map = 0;
	_s_GameMain.MapChange1(_s_GameMain._Map);
	_s_GameMain._StageNo = 1;
	_s_GameMain._moveFlag = 0;
	_s_GameMain.PcClear1 = 0;
	_s_GameMain.PcClear2 = 0;
	_s_GameMain.PcClear3 = 0;
	_s_GameMain.SentenceCnt = 0;
	_s_GameMain.AddChara(CHARA_TYPE_PLAYER1, 1300, 530, 1, 0);
	_s_GameMain._bgm = LoadSoundMem("res/bgm/stage1/BGM_STAGE1.wav");
	_s_GameMain.bgm_volume = 128;		// BGMボリューム初期化
	ChangeVolumeSoundMem(_s_GameMain.bgm_volume, _s_GameMain._bgm);
	PlaySoundMem(_s_GameMain._bgm, DX_PLAYTYPE_BACK, TRUE);
	ColorFadeIn(60);		// フェードインに変更

}

SceneGameStage1::~SceneGameStage1() 
{
	DeleteGraph(_s_GameMain._cgBg);
	for(int i = 0; i < _PT_CHARA_ALLNUM_; i++) {
		if(_s_GameMain._cgChara[i] != -1) {
			DeleteGraph(_s_GameMain._cgChara[i]);
		}
	}
	DeleteSoundMem(_s_GameMain._bgm);		// BGMをメモリから削除
}

void SceneGameStage1::Input()
{
	// 何もしない
}

void SceneGameStage1::Process()
{
	_s_GameMain.Process();
}

void SceneGameStage1::Draw()
{
	_s_GameMain.Draw();
}