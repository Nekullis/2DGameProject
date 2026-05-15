#include "DxLib.h"
#include "winmain.h"
#include "gamemain.h"
#include "mymath.h"
#include "scene.h"
#include "FpsControll.h"
#include "Time.h"

GamePad gPad;

Scene* gScene;		// newするまで実体は無い

Scene* gNewScene;		// NULL以外のセットで、シーンの切り替え

void ChangeScene(Scene* scene) 
{
	gNewScene = scene;		// 次のシーンのセット
}

// カラーマスク用
int gColorMaskR = 0, gColorMaskG = 0, gColorMaskB = 0, gColorMaskA = 0;

// 指定の色をカラーマスク
void ColorMask(int colorR, int colorG, int colorB, int colorA) {
	gColorMaskR = colorR;
	gColorMaskG = colorG;
	gColorMaskB = colorB;
	gColorMaskA = colorA;
}

// フェードインアウト用
int gColorFadeStR, gColorFadeStG, gColorFadeStB, gColorFadeStA;
int gColorFadeEdR, gColorFadeEdG, gColorFadeEdB, gColorFadeEdA;
int gFadeFrames = 0, gFadeCnt = 0;

// 指定の色にフェードアウト（カラーマスク使用, alpha=255にする）
void ColorFadeOut(int colorR, int colorG, int colorB, int frames) {
	// フェード開始値
	gColorFadeStR = gColorMaskR;
	gColorFadeStG = gColorMaskG;
	gColorFadeStB = gColorMaskB;
	gColorFadeStA = gColorMaskA;
	// フェード到達値
	gColorFadeEdR = colorR;
	gColorFadeEdG = colorG;
	gColorFadeEdB = colorB;
	gColorFadeEdA = 255;
	// フェードカウンタ
	gFadeFrames = frames;
	gFadeCnt = 0;
}

// 現在のカラーマスクからフェードイン（カラーマスク使用, alpha=0にする）
void ColorFadeIn(int frames) {
	// フェード開始値
	gColorFadeStR = gColorMaskR;
	gColorFadeStG = gColorMaskG;
	gColorFadeStB = gColorMaskB;
	gColorFadeStA = gColorMaskA;
	// フェード到達値
	gColorFadeEdR = gColorMaskR;
	gColorFadeEdG = gColorMaskG;
	gColorFadeEdB = gColorMaskB;
	gColorFadeEdA = 0;
	// フェードカウンタ
	gFadeFrames = frames;
	gFadeCnt = 0;
}

// フェードインアウトは終了したか？
// 戻り値: 1 = フェード中, 0 = フェード終了(もしくは開始前)
int IsColorFade () {
	if(gFadeCnt < gFadeFrames) {
		return 1;
	}
	return 0;
}

void AppInit() 
{
	gNewScene = NULL;		// 次のシーンの初期化
	gScene = new Scene();		// Sceneの実体
}

void AppRelease() 
{
	delete gScene;		// Sceneを削除
}


void FrameInput() {

	//gScene->Input();		// Sceneの入力呼び出し
	gPad.Input();
}

void FrameProcess() {
	gScene->Process();		// Sceneの計算呼び出し

	if(IsColorFade() != 0) {
		gFadeCnt++;
		gColorMaskR = static_cast<int>(EasingLinear(static_cast<float>(gFadeCnt), static_cast<float>(gColorFadeStR), static_cast<float>(gColorFadeEdR), static_cast<float>(gFadeFrames)));
		gColorMaskG = static_cast<int>(EasingLinear(static_cast<float>(gFadeCnt), static_cast<float>(gColorFadeStG), static_cast<float>(gColorFadeEdG), static_cast<float>(gFadeFrames)));
		gColorMaskB = static_cast<int>(EasingLinear(static_cast<float>(gFadeCnt), static_cast<float>(gColorFadeStB), static_cast<float>(gColorFadeEdB), static_cast<float>(gFadeFrames)));
		gColorMaskA = static_cast<int>(EasingLinear(static_cast<float>(gFadeCnt), static_cast<float>(gColorFadeStA), static_cast<float>(gColorFadeEdA), static_cast<float>(gFadeFrames)));
	}
}

void FrameDraw() {

	ClearDrawScreen();		// 画面を初期化

	gScene->Draw();		// Sceneの描画呼び出し

	if(gColorMaskA > 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, gColorMaskA);	// 半透明モード
		DrawBox(0, 0, SCREEN_W, SCREEN_H, GetColor(gColorMaskR, gColorMaskG, gColorMaskB), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, gColorMaskA);
	}
	ScreenFlip();		// 裏画面を表画面に反映
}

void GameMain() {
	
	AppInit();		// 初期化
	while (ProcessMessage() == 0 )
	{
		//フレームレート制御
		Time::Update();

		//シーンを切り替えるか?
		if (gNewScene != NULL) {
			delete gScene;			// 今のシーンの削除
			gScene = gNewScene;		// 受け取ったシーンのポインタセット
			gNewScene = NULL;		// 次のシーンの初期化
		}

		FrameInput();		// 入力
		FrameProcess();		// 計算
		FrameDraw();		// 描画

		//待機
		FpsControll_Wait();

		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)	// ESCAPEキーが押されたか
		break;		// メインループを抜ける
	}

	AppRelease();		// 解放
}