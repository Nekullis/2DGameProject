#include "SceneGameStage2.h"

SceneGameStage2::SceneGameStage2()
{
	
	// 画像の読み出し
	_s_GameMain._cgLightBg = LoadGraph("res/bg/fogimage_one_side.png");
	_s_GameMain._cgPosBar = LoadGraph("res/ui/gauge/gauge1.png");
	_s_GameMain._cgBar = LoadGraph("res/ui/gauge/gauge2-1.png");
	_s_GameMain._cgEventAlert[0] = LoadGraph("res/bg/stage2/event/buzzer1.png");
	_s_GameMain._cgEventAlert[1] = LoadGraph("res/bg/stage2/event/buzzer2.png");
	_s_GameMain._cgEventAlert[2] = LoadGraph("res/bg/stage2/event/buzzer3.png");
	_s_GameMain._cgEventAlert[3] = LoadGraph("res/bg/stage2/event/buzzer4.png");
	_s_GameMain._cgEventAlert[4] = LoadGraph("res/bg/stage2/event/buzzer5.png");
	_s_GameMain._cgEventAlert[5] = LoadGraph("res/bg/stage2/event/buzzer6.png");
	_s_GameMain._cgEventAlert[6] = LoadGraph("res/bg/stage2/event/buzzer7.png");
	_s_GameMain._cgEventAlert[7] = LoadGraph("res/bg/stage2/event/buzzer8.png");
	LoadDivGraph("res/gimmick/stage2/door2_1.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_DOOR]);
	LoadDivGraph("res/gimmick/stage2/dooropen2.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR]);
	LoadDivGraph("res/gimmick/stage2/door2_5.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR + 5]);
	LoadDivGraph("res/gimmick/stage2/doorclose2.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_CLOSE_DOOR]);
	_s_GameMain._Map2 = 0;
	_s_GameMain.MapChange2(_s_GameMain._Map2);
	_s_GameMain.AddChara(CHARA_TYPE_PLAYER1, 1300, 530, 1,0);
	_s_GameMain._gamePause = 0;
	_s_GameMain._StageNo = 2;
	_s_GameMain._moveFlag = 0;
	_s_GameMain.PcClear1 = 0;
	_s_GameMain.PcClear2 = 0;
	_s_GameMain.PcClear3 = 0;
	_s_GameMain.SentenceCnt = 0;

	_s_GameMain._bgm = LoadSoundMem("res/bgm/stage2/BGM8.wav");
	
	PlaySoundMem(_s_GameMain._bgm, DX_PLAYTYPE_BACK, TRUE);
	ColorFadeIn(60);		// フェードインに変更
	
}

SceneGameStage2::~SceneGameStage2()
{
	DeleteGraph(_s_GameMain._cgBg);
	for(int i = 0; i < _PT_CHARA_ALLNUM_; i++) {
		if(_s_GameMain._cgChara[i] != -1) {
			DeleteGraph(_s_GameMain._cgChara[i]);
		}
	}
	DeleteSoundMem(_s_GameMain._bgm);
}

void SceneGameStage2::Input()
{

}

void SceneGameStage2::Process()
{
	_s_GameMain.Process();
}

void SceneGameStage2::Draw()
{
	_s_GameMain.Draw();	
}
