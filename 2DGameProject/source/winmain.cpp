#include "DxLib.h"
#include "gamemain.h"
#include "winmain.h"
#include <time.h>


int WINAPI WinMain(
	HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	SetGraphMode(SCREEN_W, SCREEN_H, SCREEN_DEPTH);	// 画面の解像度 1920*1080 1ドットあたり32bitに指定
	ChangeWindowMode(true);
	
	//垂直同期を切る
	//SetWaitVSyncFlag(0);

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);		// 描画先画面を裏画面にセット
	SetMouseDispFlag(false);			// マウスポインタの有無 true→有 false→無
	srand((unsigned)time(NULL));		// 乱数初期化

	GameMain();

	//フレームレート表示
	//FpsControll_Draw();

	DxLib_End();		// DXライブラリ使用の終了処理


	return 0;
}