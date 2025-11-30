#include "s_gamemain.h"


void SceneGameMain::ProcessSentence()
{
	//アイテムをとった際にフラグを立て、とったアイテムによって文章を変える
	
	if (SentenceFlag == 1)
	{
		if (_KeyCnt == 2)	//鍵入手
		{
			SentenceNo = 2;
		}
		if (_KnifeCnt == 2)	//ナイフ入手
		{
			SentenceNo = 5;
		}
		if (_HealCnt == 1)	//回復アイテム入手
		{
			SentenceNo = 9;
		}
		if (EscapePcClear == 1)	//ステージ3の特殊なPCを起動
		{
			SentenceNo = 7;
		}
		SentenceCnt++;			//3分間文章を表示するように
		if (SentenceCnt >= 180)
		{
			SentenceNo = 0;
			SentenceCnt = 0;
			SentenceFlag = 0;
			if (_HealCnt == 1)
			{
				_HealCnt = 0;
			}			
		}
	}
	if (SentenceFlag == 2)
	{
		if (_KeyCnt != 2)
		{
			SentenceNo = 1;
		}
	}

	//PC3つ解除した際に文章が表示されるように
	if(_EvPcFlag == 3)
	{
		SentenceNo = 4;
		KeyDoor = 1;
		SentenceCnt++;
		if (SentenceCnt >= 180)
		{
			_EvPcFlag = 0;
			SentenceNo = 0;
			SentenceCnt = 0;
		}	
	}	
}

void SceneGameMain::DrawSentence() const
{
	//文章の表示
	if(SentenceNo != 0)
	{
		DrawGraph(0, 0, _cgSentence[SentenceNo], TRUE);
	}
}