#include "DxLib.h"
#include "gamemain.h"
#include "s_gameclear.h"

SceneGameClear::SceneGameClear()
{
	_EndMovie = LoadGraph("res/ending/ending.mp4");

	ColorFadeIn(60);
}

SceneGameClear::~SceneGameClear()
{
	DeleteGraph(_EndMovie);
}

void SceneGameClear::Input()
{

}

void SceneGameClear::Process()
{
	if(IsColorFade() == 0)
	{
		//Ä¶‚³‚ê‚Ä‚¢‚È‚¯‚ê‚Î“®‰æ‚ğÄ¶‚·‚é
		if(GetMovieStateToGraph(_EndMovie) == 0 && TellMovieToGraph(_EndMovie) == 0)
		{
			PlayMovieToGraph(_EndMovie);
			ChangeMovieVolumeToGraph(100, _EndMovie);
		}
	}
}

void SceneGameClear::Draw()
{
	DrawGraph(0, 0, _EndMovie, FALSE);
}