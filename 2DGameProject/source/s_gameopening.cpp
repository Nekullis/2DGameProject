#include "s_gameopening.h"
#include "DxLib.h"
#include "gamemain.h"
#include "SceneGameStage1.h"

SceneGameOpening::SceneGameOpening()
{
	OpeningStep = 0;

	_mvOpening = LoadGraph("res/opening/prologue.mp4");
	SetUseASyncLoadFlag(TRUE);
	_cgManual[0] = LoadGraph("res/title/manual/now loading1.png");
	_cgManual[1] = LoadGraph("res/title/manual/now loading2.png");
	_cgManual[2] = LoadGraph("res/title/manual/now loading3.png");
	_cgManual[3] = LoadGraph("res/title/manual/now loading4.png");
	_cgManual[4] = LoadGraph("res/title/manual/now loading5.png");
	_cgManual[5] = LoadGraph("res/title/manual/now loading6.png");
	_cgManual[6] = LoadGraph("res/title/manual/now loading7.png");
	_cgManual[7] = LoadGraph("res/title/manual/now loading8.png");
	SetUseASyncLoadFlag(FALSE);
	ManualCnt = 0;
	ManualAniCnt = 0;
	ColorFadeIn(60);
	
}
SceneGameOpening::~SceneGameOpening()
{
	if (_mvOpening != 0)
	{
		DeleteGraph(_mvOpening);
	}
	
	for (int i = 0; i < 8; i++)
	{
		DeleteGraph(_cgManual[i]);
	}
}

void SceneGameOpening::Process()
{
	switch (OpeningStep)
	{
	case 0:
		//フェードイン、アウト中でないのならステップ+1
		if (IsColorFade() == 0)
		{
			OpeningStep++;
		}
		break;
	case 1:
		//動画を再生する
		if (GetMovieStateToGraph(_mvOpening) == 0)
		{
			ChangeMovieVolumeToGraph(100, _mvOpening);
			SeekMovieToGraph(_mvOpening, 1);
			PlayMovieToGraph(_mvOpening);
			
			OpeningStep++;
		}
		break;
	case 2:
		//動画を再生中でなければフェードアウトする
		if (GetMovieStateToGraph(_mvOpening) == 0)
		{
			ColorFadeOut(0, 0, 0, 60);
			OpeningStep++;
		}
		break;
	case 3:
		//フェードアウトが終わったなら動画を削除
		if (IsColorFade() == 0)
		{
			DeleteGraph(_mvOpening);
			OpeningStep++;
		}
		break;
	case 4:
		//フェードインを行う
		ColorFadeIn(30);
		OpeningStep++;

		break;

	case 5:
		//フェードインが終わったならステップ+1
		if (IsColorFade() == 0)
		{
			OpeningStep++;
		}
		break;
	case 6:
		//画像をだして数秒待つ
		if (ManualCnt > 500)
		{	
			if (CheckHandleASyncLoad(_cgChara[_PT_CHARA_ALLNUM_-1]))
			{
				if (CheckHandleASyncLoad(_se[_SE_ALL_-1]))
				{
					{
						OpeningStep++;
					}	
				}
			}
		}
		break;
	case 7:
		//フェードアウト
		ColorFadeOut(0, 0, 0, 30);
		OpeningStep++;
		break;
	case 8:
		//シーン切り替え
		if (IsColorFade() == 0)
		{
			Scene* scene = new SceneGameStage1();
			ChangeScene(scene);
		}
		break;

	}

	if (OpeningStep >= 4)
	{
		//アニメーションできるようにカウントを増やす
		ManualAniCnt++;
		ManualCnt++;

	}
	if (gPad._trg & PAD_INPUT_4)
	{
		//ボタンを押すとポーズ、再生中ではなくなる
		PauseMovieToGraph(_mvOpening);
	}
	
}

void SceneGameOpening::Draw()
{
	//動画の再生
	if (GetMovieStateToGraph(_mvOpening) != 0)
	{
		DrawGraph(0, 0, _mvOpening, FALSE);
	}
	
	//説明画像の描画
	if (OpeningStep >= 4)
	{
		DrawGraph(0, 0, _cgManual[ManualAniCnt / 4 % 8], FALSE);
	}
}