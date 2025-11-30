#include "DxLib.h"
#include "winmain.h"
#include "gamemain.h"
#include "mymath.h"
#include "mydraw.h"
#include "s_gamemain.h"
#include "s_gameover.h"
#include "SceneGameStage1.h"
#include "SceneGameStage2.h"
#include "SceneGameStage3.h"
#include "s_gameclear.h"
#include "framedata.h"




SceneGameMain::SceneGameMain() {
	// キャラ画像配列の初期化
	
	// 画像の読み出し
	_cgBg = 0;
	
	LoadDivGraph("res/bg/minamo1_sheet.png", 3, 3, 1, 7680, 2160, &_cgWaterSurface[0]);

	_cgSentence[1] = LoadGraph("res/sentence/sentence 1.png");
	_cgSentence[2] = LoadGraph("res/sentence/sentence 2.png");
	_cgSentence[3] = LoadGraph("res/sentence/sentence 3.png");
	_cgSentence[4] = LoadGraph("res/sentence/sentence 4.png");
	_cgSentence[5] = LoadGraph("res/sentence/sentence 5.png");
	_cgSentence[6] = LoadGraph("res/sentence/sentence 6.png");
	_cgSentence[7] = LoadGraph("res/sentence/sentence 7.png");
	_cgSentence[8] = LoadGraph("res/sentence/sentence 8.png");
	_cgSentence[9] = LoadGraph("res/sentence/sentence 9.png");

	_cgEventAlert[0] = LoadGraph("res/bg/stage2/event/buzzer1.png");
	_cgEventAlert[1] = LoadGraph("res/bg/stage2/event/buzzer2.png");
	_cgEventAlert[2] = LoadGraph("res/bg/stage2/event/buzzer3.png");
	_cgEventAlert[3] = LoadGraph("res/bg/stage2/event/buzzer4.png");
	_cgEventAlert[4] = LoadGraph("res/bg/stage2/event/buzzer5.png");
	_cgEventAlert[5] = LoadGraph("res/bg/stage2/event/buzzer6.png");
	_cgEventAlert[6] = LoadGraph("res/bg/stage2/event/buzzer7.png");
	_cgEventAlert[7] = LoadGraph("res/bg/stage2/event/buzzer8.png");


	LoadDivGraph("res/item/key.png", 3, 3, 1, 100, 100, &cgKey[0]);
	LoadDivGraph("res/item/knife.png", 3, 3, 1, 100, 100, &cgKnife[0]);

	// キャラデータの初期設定
	for(int i = 0; i < CHARA_MAX; i++) 
	{
		_gChara[i].type = CHARA_TYPE_NONE;		// いったん、全キャラをnoneに
	}
	

	// ゲーム情報の初期化
	_gameInfo.score = 0;

	// 特殊演出を「START」に
	_stagingProc = STAGING_START;
	_gamePause = 0;		// ゲームの処理をPAUSE状態に
	_stageclear = 0;
	
	//ステージの初期化
	_StageNo = 0;
	bgSize_w = 0;
	bgSize_h = 0;

	bgcnt = 0;
	bganimcnt = 0;

	//ギミックに関するグローバル変数の初期化
	_EvPcBar1 = 0;
	_Evcnt1 = 0;
	_EvPcBar2 = 0;
	_Evcnt2 = 0;
	_EvPcBar3 = 0;
	_Evcnt3 = 0;
	_EvPcFlag = 0;
	_KnifeCnt = 0;
	_KeyCnt = 0;
	_HealCnt = 0;
	KeyDoor = 0;
	PcClear1 = 0;
	PcClear2 = 0;
	PcClear3 = 0;
	EscapePcClear = 0;
	ItemCnt = 0;
	ItemCntFlag = 0;

	EnemyKnifeCnt = 0;
	_moveFlag = 0;
	_GameOverStep = 0;
	_GameOver = 0;
	_GameOverStage = _StageNo;
	_GameClearStep = 0;
	_GameClear = 0;
	
	PlayerEscape = 0;
	_Step = 0;
	
	// カウント
	cnt1Flag = 0;
	cnt1 = 0;
	StanCntFlag = 0;
	StanCnt = 0;
	StanNom = 0;
	_moveX = 0;

	//文章に関する初期化
	SentenceNo = 0;
	SentenceCnt = 0;
	SentenceFlag = 0;

	SceneEv = 0;
	PlArrow = 0;

	_Map = 0;
	_Map2 = 0;
	_Map3 = 0;
	_FadeStep = 0;
	_MapMove = 0;

	useHierarchy = 0;
	useEnHierarchy = 0;

	bgm_volume = 0;
	_bgm = 0;
	_cgBar = 0;
	_cgPosBar = 0;
	_cgLightBg = 0;

	AlertCnt = 0;

	ChangeLockerFlag = 0;
}

SceneGameMain::~SceneGameMain()
{
	DeleteGraph(_cgBg);
	for(int i = 0; i < _PT_CHARA_ALLNUM_; i++) {
		if(_cgChara[i] != -1) {
			DeleteGraph(_cgChara[i]);
		}
	}
	for (int i = 0; i < _SE_ALL_; i++) {
		if (_se[i] != -1) {
			DeleteSoundMem(_se[i]);
		}
	}

}

void SceneGameMain::Input() 
{
	// 何もしない
}

int SceneGameMain::AddChara(int type, int x, int y, int arrow, int useGravity) {
	// 追加できる配列を検索
	for(int i = 0; i < CHARA_MAX; i++) {
		if(_gChara[i].type == CHARA_TYPE_NONE) {
			// キャラを[i]に追加。キャラタイプによって初期化情報が変わる
			_gChara[i].type = type;
			_gChara[i].x = x;
			_gChara[i].y = y;
			_gChara[i].arrow = arrow;
			_gChara[i].hx = 0;
			_gChara[i].hy = 0;
			_gChara[i].hw = 0;
			_gChara[i].hh = 0;
			_gChara[i].useGravity = 0;
			_gChara[i].clear = 0;
			_gChara[i].layer = 0;
			_gChara[i].Hierarchy = 0;
			_gChara[i].drawuse = 1;
			switch(type) {
			case CHARA_TYPE_PLAYER1:
				_gChara[i].group = CHARA_GROUP_PLAYER;
				_gChara[i].hx = -58;
				_gChara[i].hy = -400;
				_gChara[i].hw = 100;
				_gChara[i].hh = 400;
				_gChara[i].motId = MOTION_R_STAND;
				_gChara[i].hp = 3;
				_gChara[i].maxhp = _gChara[i].hp;
				_gChara[i].layer = 1;
				_gChara[i].Hierarchy = 0;
				_gChara[i].useGravity = useGravity;
				break;
			case CHARA_TYPE_PLEFFECT_KNIFE:
				_gChara[i].group = CHARA_GROUP_PLAYER_EFFECT;
				_gChara[i].hx = -48;
				_gChara[i].hy = -48;
				_gChara[i].hw = 96;
				_gChara[i].hh = 96;
				if(arrow < 0) {
					_gChara[i].motId = MOTION_EFFECT_KNIFE_L_RUN;
				}
				else {
					_gChara[i].motId = MOTION_EFFECT_KNIFE_R_RUN;
				}
				_gChara[i].hp = 1;
				_gChara[i].maxhp = _gChara[i].hp;
				_gChara[i].useGravity = useGravity;
				_gChara[i].layer = 2;
				break;
			case CHARA_TYPE_ITEM_POINT_0:
			case CHARA_TYPE_ITEM_POINT_1:
			case CHARA_TYPE_ITEM_POINT_2:
			case CHARA_TYPE_ITEM_POINT_3:
			case CHARA_TYPE_ITEM_POINT_4:
			{
				_gChara[i].group = CHARA_GROUP_ITEM;
				switch(type) {
				case CHARA_TYPE_ITEM_POINT_0:
					_gChara[i].motId = MOTION_ITEM_POINT_0_NORMAL;
					break;
				case CHARA_TYPE_ITEM_POINT_1:
					_gChara[i].motId = MOTION_ITEM_POINT_1_NORMAL;
					break;
				case CHARA_TYPE_ITEM_POINT_2:
					_gChara[i].motId = MOTION_ITEM_POINT_2_NORMAL;
					break;
				case CHARA_TYPE_ITEM_POINT_3:
					_gChara[i].motId = MOTION_ITEM_POINT_3_NORMAL;
					break;
				case CHARA_TYPE_ITEM_POINT_4:
					_gChara[i].motId = MOTION_ITEM_POINT_4_NORMAL;
					break;
				}
				_gChara[i].useGravity = useGravity;
				_gChara[i].layer = 1;
				break;
			}
			case CHARA_TYPE_ENEMY_1:
			{
				_gChara[i].group = CHARA_GROUP_ENEMY;
				_gChara[i].hx = -650;
				_gChara[i].hy = -700;
				_gChara[i].hw = 0;
				_gChara[i].hh = 0;
				_gChara[i].motId = MOTION_ENEMY1_L_RUN;
				_gChara[i].hp = 999;
				_gChara[i].maxhp = _gChara[i].hp;
				_gChara[i].layer = 1;
				_gChara[i].useGravity = useGravity;
				break;
			}
			case CHARA_TYPE_ENEMY_2:
			{
				_gChara[i].group = CHARA_GROUP_ENEMY;
				_gChara[i].hx = -300;
				_gChara[i].hy = -300;
				_gChara[i].hw = 0;
				_gChara[i].hh = 0;
				_gChara[i].motId = MOTION_ENEMY2_L_RUN;
				_gChara[i].hp = 1;
				_gChara[i].maxhp = _gChara[i].hp;
				_gChara[i].layer = 1;
				_gChara[i].useGravity = useGravity;
				break;
			}
			case CHARA_TYPE_ENEMY_3:
			{
				_gChara[i].group = CHARA_GROUP_ENEMY;
				_gChara[i].hx = -550;
				_gChara[i].hy = -900;
				_gChara[i].hw = 0;
				_gChara[i].hh = 0;
				_gChara[i].motId = MOTION_ENEMY3_L_RUN;
				_gChara[i].hp = 1;
				_gChara[i].maxhp = _gChara[i].hp;
				_gChara[i].layer = 1;
				_gChara[i].useGravity = useGravity;
				break;
			}
			case CHARA_TYPE_ENEMY_4:
			{
				_gChara[i].group = CHARA_GROUP_ENEMY;
				_gChara[i].hx = -100;
				_gChara[i].hy = -245;
				_gChara[i].hw = 200;
				_gChara[i].hh = 210;
				if (_StageNo == 2)
				{
					_gChara[i].motId = MOTION_ENEMY4_L_UNDISCOVER_RUN;
				}
				else
				{
					_gChara[i].motId = MOTION_ENEMY4_R_RUN;
				}
				_gChara[i].hp = 999;
				_gChara[i].layer = 1;
				_gChara[i].useGravity = useGravity;
				_gChara[i].Hierarchy = 1;
				break;
			}
			case CHARA_TYPE_ENEMY_5:
			{
				_gChara[i].group = CHARA_GROUP_ENEMY;
				_gChara[i].hx = -400;
				_gChara[i].hy = -450;
				_gChara[i].motId = MOTION_ENEMY5_L_RUN;
				_gChara[i].hp = 1;
				_gChara[i].layer = 1;
				break;
			}
			
			case CHARA_TYPE_GIMMICK_DOOR_1:
			case CHARA_TYPE_GIMMICK_DOOR_2:
			case CHARA_TYPE_GIMMICK_DOOR_3:
			case CHARA_TYPE_GIMMICK_DOOR_4:
			case CHARA_TYPE_GIMMICK_DOOR_5:
			{
				_gChara[i].group = CHARA_GROUP_GIMMICK;
				_gChara[i].motId = MOTION_GIMMICK_DOOR;
				_gChara[i].layer = 3;
				break;
			}
			
			case CHARA_TYPE_GIMMICK_PC_1:
			{
				_gChara[i].group = CHARA_GROUP_GIMMICK;
				_gChara[i].motId = MOTION_GIMMICK_PC;
				_gChara[i].useGravity = useGravity;
				_gChara[i].clear = PcClear1;
				_gChara[i].layer = 3;
				break;
			}

			case CHARA_TYPE_GIMMICK_PC_2:
			{
				_gChara[i].group = CHARA_GROUP_GIMMICK;
				_gChara[i].motId = MOTION_GIMMICK_PC;
				_gChara[i].useGravity = useGravity;
				_gChara[i].clear = PcClear2;
				_gChara[i].layer = 3;
				break;
			}

			case CHARA_TYPE_GIMMICK_PC_3:
			{
				_gChara[i].group = CHARA_GROUP_GIMMICK;
				_gChara[i].motId = MOTION_GIMMICK_PC;
				_gChara[i].useGravity = useGravity;
				_gChara[i].clear = PcClear3;
				_gChara[i].layer = 3;
				break;
			}
			case CHARA_TYPE_GIMMICK_ESCAPE_PC:
			{
				_gChara[i].group = CHARA_GROUP_GIMMICK;
				_gChara[i].motId = MOTION_GIMMICK_ESCAPE_PC;
				_gChara[i].useGravity = useGravity;
				_gChara[i].clear = EscapePcClear;
				_gChara[i].layer = 3;
				break;
			}

			case CHARA_TYPE_GIMMICK_CAGE:
			{
				_gChara[i].group = CHARA_GROUP_GIMMICK;
				_gChara[i].motId = MOTION_GIMMICK_CAGE;
				_gChara[i].useGravity = useGravity;
				_gChara[i].layer = 3;
				break;
			}

			case CHARA_TYPE_GIMMICK_STAIR:
			{
				_gChara[i].group = CHARA_GROUP_GIMMICK;
				_gChara[i].motId = MOTION_GIMMICK_STAIR;
				_gChara[i].useGravity = useGravity;
				_gChara[i].layer = 3;
				break;
			}
			case CHARA_TYPE_GIMMICK_LOCKER:
			{
				_gChara[i].group = CHARA_GROUP_GIMMICK;
				_gChara[i].motId = MOTION_GIMMICK_LOCKER;
				_gChara[i].useGravity = useGravity;
				_gChara[i].layer = 3;
				break;
			}
			case CHARA_TYPE_GIMMICK_ELEVATOR:
			{
				_gChara[i].group = CHARA_GROUP_GIMMICK;
				_gChara[i].motId = MOTION_GIMMICK_ELEVATOR;
				_gChara[i].useGravity = useGravity;
				_gChara[i].layer = 3;
				break;
			}
			case CHARA_TYPE_GIMMICK_EVENT_HITRECT:
			{
				_gChara[i].hx = -20;
				_gChara[i].hy = -600;
				_gChara[i].hw = 40;
				_gChara[i].hh = 600;
				_gChara[i].group = CHARA_GROUP_GIMMICK;
				_gChara[i].motId = MOTION_GIMMICK_EVENT_HITRECT;
				_gChara[i].useGravity = useGravity;
				_gChara[i].layer = 3;
				break;
			}
			case CHARA_TYPE_GIMMICK_MOVE_HITRECT:
			{
				
				_gChara[i].group = CHARA_GROUP_GIMMICK;
				_gChara[i].motId = MOTION_GIMMICK_MOVE_HITRECT;
				_gChara[i].useGravity = useGravity;
				_gChara[i].layer = 3;
				break;
			}
			}
			_gChara[i].motcnt = 0;		// モーションカウンタ。0～
			_gChara[i].animcnt = 0;	// アニメーションカウンタ。0～
			_gChara[i].gravity = 0;	// 重力による加速値
			_gChara[i].stand = 0;		// 床フラグ。着地していたら1

			_gChara[i].respawn = 0;	// リスポーンフラグ。リスポーンするなら1
			_gChara[i].respawn_x = _gChara[i].x;	// リスポーン座標
			_gChara[i].respawn_y = _gChara[i].y;	// リスポーン座標

			// 追加できた配列番号を返す
			return i;
		}
	}
	// 追加できなかった
	return -1;
}


void SceneGameMain::DeleteChara(int charaIndex) {
	_gChara[charaIndex].type = CHARA_TYPE_NONE;
	_gChara[charaIndex].group = CHARA_TYPE_NONE;
}

void SceneGameMain::StageClear()
{
	if (_stageclear == 1)
	{

		switch (_Step)
		{
		case 0:
			_Step++;
			break;
		case 1:
			if (IsColorFade() == 0)
			{
				// フェードイン終了
				_Step++;
			}
			break;
		case 2:
			// 通常処理
				// フェードアウト開始
			ColorFadeOut(0, 0, 0, 60);
			_Step++;
			break;
		case 3:
			if (IsColorFade() == 0)
			{
				if (_StageNo == 1)
				{
					Scene* scene = new SceneGameStage2();
					ChangeScene(scene);
				}
				else if (_StageNo == 2)
				{
					Scene* scene = new SceneGameStage3();
					ChangeScene(scene);
				}
				// フェードアウト終了
				break;
			}
			break;
		}
	}
}

void SceneGameMain::GameOver()
{
	if(_GameOver == 1)
	{
		switch(_GameOverStep)
		{
		case 0:
		{
			_GameOverStep++;
			break;
		}

		case 1:
		{
			if(IsColorFade() == 0)
			{
				// フェードイン終了
				_GameOverStep++;
			}
			break;
		}

		case 2:
		{
			// 通常処理
												// フェードアウト開始
			ColorFadeOut(0, 0, 0, 60);
			_GameOverStep++;
			break;
		}

		case 3:
		{
			if(IsColorFade() == 0)
			{

				_GameOverStage = _StageNo;

				// フェードアウト終了
				Scene* scene = new SceneGameOver(_GameOverStage);
				ChangeScene(scene);
			}
			break;
		}
		}
	}
}

void SceneGameMain::GameClear()
{
	if(_GameClear == 1)
	{
		switch(_GameClearStep)
		{
		case 0:
		{
			_GameClearStep++;
			break;
		}

		case 1:
		{
			if(IsColorFade() == 0)
			{
				// フェードイン終了
				_GameClearStep++;
			}
			break;
		}

		case 2:
		{
			// 通常処理									
			// フェードアウト開始
			ColorFadeOut(0, 0, 0, 60);
			_GameClearStep++;
			break;
		}

		case 3:
		{
			if(IsColorFade() == 0)
			{
				 //フェードアウト終了
				Scene* scene = new SceneGameClear();
				ChangeScene(scene);

			}
			break;
		}
		}
	}
}

// 特殊演出処理
void SceneGameMain::ProcessStaging() {
	switch(_stagingProc) {
	case STAGING_START:
		// [z]が押されるまで「START」表示
		if(gPad._trg & PAD_INPUT_1) {
			_stagingProc = STAGING_NONE;
			_gamePause = 0;
		}
		break;
	case STAGING_MISS:
		// [z]が押されるまで「MISS」表示
		if(gPad._trg & PAD_INPUT_1) {
			_stagingProc = STAGING_NONE;
			_gamePause = 0;
		}
		break;
	}
}

void SceneGameMain::Process() {

	// カメラ位置をCHARA_TYPE_PLAYER1の位置にする
	for (int i = 0; i < CHARA_MAX; i++) {
		if (_gChara[i].type == CHARA_TYPE_PLAYER1) {
			_cam._pos = VGet(static_cast<float>(_gChara[i].x), static_cast<float>(_gChara[i].y) - 300.0f, 0.0f);
		}
	}
	
	// ゲームはPAUSE中ではないか？
	if (_gamePause == 0) {
		ProcessCharacter();		// キャラクタ処理
	}
	//ProcessStaging();		// 特殊演出処理
	
	//pcを連打した際、同時にカウントを増やし、0.5秒に1、バー数値を減らす
	_Evcnt1++;
	if(_Evcnt1 % 30 == 0)
	{
		_EvPcBar1--;
		if(_EvPcBar1 < 0)
		{
			_EvPcBar1 = 0;
		}
	}
	_Evcnt2++;
	if(_Evcnt2 % 30 == 0)
	{
		_EvPcBar2--;
		if(_EvPcBar2 < 0)
		{
			_EvPcBar2 = 0;
		}
	}
	_Evcnt3++;
	if(_Evcnt3 % 30 == 0)
	{
		_EvPcBar3--;
		if(_EvPcBar3 < 0)
		{
			_EvPcBar3 = 0;
		}
	}

	bgcnt++;
	bganimcnt = bgcnt / 12 % 3;
	EnemyKnifeCnt++;

	if (cnt1Flag ==1)
	{
		cnt1++;
		if(cnt1 == 600)
		{	
			cnt1 = 0;
		}
	}
	
	if (StanCntFlag == 1)
	{
		StanCnt--;
		if (StanCnt <= 0)
		{
			StanCnt = 0;
		}
	}

	if (ItemCntFlag == 1)
	{
		ItemCnt++;
		if (ItemCnt != 0 && ItemCnt % 600 == 0)
		{
			
			AddChara(CHARA_TYPE_ITEM_POINT_4, 1200, 1200, 1, 0);
			AddChara(CHARA_TYPE_ITEM_POINT_4, 800, 2000, 1, 0);
			ItemCntFlag = 0;
			ItemCnt = 0;
		}
	}

	if(_StageNo==2)
	{
		if(SceneEv == 6)
		{
			
			AlertCnt++;
		}
		if(SceneEv == 7)
		{
			DeleteSoundMem(_se[SE_EVENT_ALERT]);
		}
	}
	
	//文章に関する処理
	ProcessSentence();

	// カメラ処理を呼ぶ
	_cam.Process();

	//ステージクリア
	StageClear();

	//ゲームオーバー
	GameOver();

	//ゲームクリア
	GameClear();
}

void SceneGameMain::Draw() 
{
	int i, j;
	float x, y;

	// カメラのView行列で、画面上の座標を計算（View座標）
	MATRIX	mView = _cam.GetViewMatrix();
	// 背景
	{
		// 画像の中心位置が基底位置になるので、(0,0)が画像の左上になるように、ワールド座標を計算	
		VECTOR world = VGet(bgSize_w / 2.0f, bgSize_h / 2.0f, 0);
		MyDrawModiGraph(mView, world, 1.f, 0.f, bgSize_w, bgSize_h, _cgBg);
		if(_StageNo == 3)
		{
			MyDrawModiGraph(mView, world, 1.f, 0.f, bgSize_w, bgSize_h, _cgWaterSurface[bganimcnt]);
		}
	}

	// マップ＆キャラ描画
	// まずはlayerを参考に描画順を作る
	int drawCharaIndex[CHARA_MAX]{};
	for(i = 0; i < CHARA_MAX; i++) 
	{
		drawCharaIndex[i] = i;
	}
	// layer順に並び変え
	for(i = 0; i < CHARA_MAX; i++) 
	{
		for(j = i + 1; j < CHARA_MAX; j++)
		{
			if(_gChara[drawCharaIndex[i]].layer < _gChara[drawCharaIndex[j]].layer) 
			{
				int tmp = drawCharaIndex[i];
				drawCharaIndex[i] = drawCharaIndex[j];
				drawCharaIndex[j] = tmp;
			}
		}
	}

	// drawCharaIndex[] 順に描画
	for(j = 0; j < CHARA_MAX; j++)
	{
		i = drawCharaIndex[j];
		if(_gChara[i].type != CHARA_TYPE_NONE)
		{
			if (_gChara[i].drawuse == 1)
			{
				// キャラ描画

			// キャラのモーションフレームから情報を得る
				int frameId = SearchFrame(tblMotion[_gChara[i].motId].item[_gChara[i].motcnt].frameId);
				int cgId = tblFrame[frameId].cgId;
				// 左右反転するか？
				if (tblMotion[_gChara[i].motId].mirror_lr == 0)
				{
					// しない
					// 描画位置は、基点分ずらした場所
					x = _gChara[i].x - static_cast<float>(tblFrame[frameId].cx);
					y = _gChara[i].y - static_cast<float>(tblFrame[frameId].cy);
					// ※このx,yはDrawGraph()用に画像の左上なので、MyDrawModiGraph()の中心位置には合わない

					VECTOR world = VGet(x, y, 0.0f);
					// 画像の中心をworld座標とするので、サイズ/2だけずらす
					world.x += tblFrame[frameId].w / 2.0f;
					world.y += tblFrame[frameId].h / 2.0f;
					MyDrawModiGraph(mView, world, 1.f, 0.f, tblFrame[frameId].w, tblFrame[frameId].h, _cgChara[cgId]);


				}
				else
				{
					// する
					// 描画位置は、左右反転してから基点分ずらした場所
					x = _gChara[i].x - static_cast<float>((tblFrame[frameId].w - tblFrame[frameId].cx));
					y = _gChara[i].y - static_cast<float>(tblFrame[frameId].cy);
					// ※このx,yはDrawGraph()用に画像の左上なので、MyDrawModiGraph()の中心位置には合わない

					VECTOR world = VGet(x, y, 0.0f);
					// 画像の中心をworld座標とするので、サイズ/2だけずらす
					world.x += tblFrame[frameId].w / 2.0f;
					world.y += tblFrame[frameId].h / 2.0f;
					MyDrawTurnModiGraph(mView, world, 1.f, 0.f, tblFrame[frameId].w, tblFrame[frameId].h, _cgChara[cgId]);
				}
			}

		}
	}

	{
		// 画像の中心位置が基底位置になるので、(0,0)が画像の左上になるように、ワールド座標を計算
		VECTOR world = VGet(bgSize_w / 2.0f, bgSize_h / 2.0f, 0.0f);
		if (_StageNo == 2)
		{
			if (SceneEv == 6)
			{
				MyDrawModiGraph(mView, world, 1.f, 0.f, bgSize_w, bgSize_h, _cgEventAlert[AlertCnt / 6 % 8]);
			}
		}
	}


	switch (_StageNo)
	{
	case 1:
	{
		if (SceneEv > 1)
		{
			if (PlArrow == 1)
			{
				DrawGraph(0, 0, _cgLightBg, TRUE);
			}
			else
			{
				DrawTurnGraph(0, 0, _cgLightBg, TRUE);
			}
		}
		break;
	}
	case 2:
	case 3:
	{
		if (PlArrow == 1)
		{
			DrawGraph(0, 0, _cgLightBg, TRUE);
		}
		else
		{
			DrawTurnGraph(0, 0, _cgLightBg, TRUE);
		}
		break;
	}
	}
	

	//特殊ui表示
	if(_EvPcBar1 >= 1)
	{
		DrawGraph(850, 300, _cgPosBar, TRUE);
		for(int i = 0; i < _EvPcBar1; i++)
		{
			DrawGraph(i * 23 + 867, 310,_cgBar, TRUE);
		}
	}

	//特殊ui表示
	if(_EvPcBar2 >= 1)
	{
		DrawGraph(850, 300, _cgPosBar, TRUE);
		for(int i = 0; i < _EvPcBar2; i++)
		{
			DrawGraph(i * 23 + 867, 310, _cgBar, TRUE);
		}
	}

	//特殊ui表示
	if(_EvPcBar3 >= 1)
	{
		DrawGraph(850, 300, _cgPosBar, TRUE);
		for(int i = 0; i < _EvPcBar3; i++)
		{
			DrawGraph(i * 23 + 867, 310, _cgBar, TRUE);
		}
	}

	// マップ描画											   
	_uiitem.Draw(cgKey[_KeyCnt], cgKnife[_KnifeCnt]);
	DrawSentence();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
}