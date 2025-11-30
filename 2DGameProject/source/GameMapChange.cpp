#include "s_gamemain.h"

void SceneGameMain::MapChange1(int MapNo)
{	//ステージ1のマップ限定
	for(int i = 0; i < CHARA_MAX; i++)
	{	//一度プレイヤー以外のすべてを初期化
		if(_gChara[i].type != CHARA_TYPE_PLAYER1)
		{
			DeleteChara(i);
		}
	}
	_Evcnt1 = 0;
	_Evcnt2 = 0;
	_Evcnt3 = 0;
	_cam._rcLimit.x = 0;
	_cam._rcLimit.y = 0;
	PlayerEscape = 0;
	
	switch(MapNo)
	{	//マップにあわせてキャラの出現、背景、背景サイズ変更
	case 0:
		_Map = 0;
		_mapData.InitMap(0);
		bgSize_w = 7680;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW1();
		_cam._rcLimit.h = _mapData.GetWorldSizeH1();
		AddChara(CHARA_TYPE_GIMMICK_CAGE, 526, 903, 1, 0);
		
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 7650, 900, 0, 0);

		if (SceneEv <= 1)
		{
			AddChara(CHARA_TYPE_GIMMICK_DOOR_1, 4450, 920, 1, 0);
			
		}
		else if (SceneEv > 1)
		{
			LoadDivGraph("res/gimmick/stage1/door_off1_1.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_DOOR]);
			LoadDivGraph("res/gimmick/stage1/dooropen_off1.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR]);
			LoadDivGraph("res/gimmick/stage1/door_off1_5.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR + 5]);
			LoadDivGraph("res/gimmick/stage1/doorclose_off1.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_CLOSE_DOOR]);
			AddChara(CHARA_TYPE_GIMMICK_DOOR_1, 4462, 920, 1, 0);
			
		}
		if (SceneEv <= 1)
		{
			_cgBg = LoadGraph("res/bg/stage1/廊下/stage1_1.png");
		}
		else if (SceneEv > 1)
		{
			_cgBg = LoadGraph("res/bg/stage1/廊下/stage off 1_1.png");
		}
		
		break;

	case 1:
		_Map = 1;
		_mapData.InitMap(0);
		bgSize_w = 7680;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW1();
		_cam._rcLimit.h = _mapData.GetWorldSizeH1();
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 7650, 900, 0, 0);
		if (SceneEv <= 1)
		{
			AddChara(CHARA_TYPE_GIMMICK_DOOR_5, 2379, 920, 1, 0);  //kniferoomドア
			AddChara(CHARA_TYPE_GIMMICK_DOOR_2, 6000, 920, -1, 0); //pcroom2ドア

		}
		else if (SceneEv > 1)
		{
			LoadDivGraph("res/gimmick/stage1/door_off1_1.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_DOOR]);
			LoadDivGraph("res/gimmick/stage1/dooropen_off1.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR]);
			LoadDivGraph("res/gimmick/stage1/door_off1_5.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR + 5]);
			LoadDivGraph("res/gimmick/stage1/doorclose_off1.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_CLOSE_DOOR]);
			AddChara(CHARA_TYPE_GIMMICK_DOOR_5, 2391, 920, 1, 0);  //kniferoomドア
			AddChara(CHARA_TYPE_GIMMICK_DOOR_2, 6012, 920, -1, 0); //pcroom2ドア

		}
		if (SceneEv > 1 && SceneEv < 4)
		{
			AddChara(CHARA_TYPE_ENEMY_2, 7000, 800, -1, 0);
		}
		
		if (SceneEv <= 1)
		{
			_cgBg = LoadGraph("res/bg/stage1/廊下/stage1_2.png");
		}
		else if (SceneEv > 1)
		{
			_cgBg = LoadGraph("res/bg/stage1/廊下/stage off 1_2.png");
		}
		break;

	case 2:
		_Map = 2;
		_mapData.InitMap(0);
		bgSize_w = 7680;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW1();
		_cam._rcLimit.h = _mapData.GetWorldSizeH1();
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		if (SceneEv <= 1)
		{
			AddChara(CHARA_TYPE_GIMMICK_DOOR_3, 2012, 920, 1, 0);  //pcroom3ドア
			AddChara(CHARA_TYPE_GIMMICK_DOOR_4, 5637, 920, -1, 0); //keyroomドア

		}
		else if (SceneEv > 1)
		{
			LoadDivGraph("res/gimmick/stage1/door_off1_1.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_DOOR]);
			LoadDivGraph("res/gimmick/stage1/dooropen_off1.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR]);
			LoadDivGraph("res/gimmick/stage1/door_off1_5.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR + 5]);
			LoadDivGraph("res/gimmick/stage1/doorclose_off1.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_CLOSE_DOOR]);
			AddChara(CHARA_TYPE_GIMMICK_DOOR_3, 2030, 920, 1, 0);  //pcroom3ドア
			AddChara(CHARA_TYPE_GIMMICK_DOOR_4, 5630, 920, -1, 0); //keyroomドア

		}
		
		if (SceneEv > 1 && SceneEv < 4)
		{
			AddChara(CHARA_TYPE_ENEMY_2, 3500, 800, -1, 0);
		}

		if (SceneEv == 4)
		{
			PlaySoundMem(_se[SE_ENEMY1_EVENT1], DX_PLAYTYPE_BACK, TRUE);
			AddChara(CHARA_TYPE_ENEMY_1, 6500, 1000, -1, 0);
			SceneEv = 5;
		}
		
		if (SceneEv <= 1)
		{
			_cgBg = LoadGraph("res/bg/stage1/廊下/stage1_3.png");
		}
		else if (SceneEv > 1)
		{
			_cgBg = LoadGraph("res/bg/stage1/廊下/stage off 1_3.png");
		}
		break;

	case 3:
		_Map = 3;
		_mapData.InitMap(1);
		bgSize_w = 2880;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW2();
		_cam._rcLimit.h = _mapData.GetWorldSizeH2();
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		AddChara(CHARA_TYPE_GIMMICK_PC_1, 1800, 970, 1,0);
		_cgBg = LoadGraph("res/bg/stage1/pcroom1/pcroom1_1.png");
		break;

	case 4:
		_Map = 4;
		_mapData.InitMap(1);
		bgSize_w = 2880;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW2();
		_cam._rcLimit.h = _mapData.GetWorldSizeH2();
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		AddChara(CHARA_TYPE_GIMMICK_PC_2, 1800, 970, 1,0);
		_cgBg = LoadGraph("res/bg/stage1/pcroom1/pcroom1_2.png");
		break;

	case 5:
		_Map = 5;
		_mapData.InitMap(1);
		bgSize_w = 2880;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW2();
		_cam._rcLimit.h = _mapData.GetWorldSizeH2();
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		AddChara(CHARA_TYPE_GIMMICK_PC_3, 1800, 970, 1,0);
		if (SceneEv == 2)
		{
			AddChara(CHARA_TYPE_ENEMY_2, 2000, 800, -1, 0);
		}
		_cgBg = LoadGraph("res/bg/stage1/pcroom1/pcroom1_3.png");
		break;
	case 6:
		_Map = 6;
		
		_mapData.InitMap(1);
		bgSize_w = 2880;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW2();
		_cam._rcLimit.h = _mapData.GetWorldSizeH2();
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		if (_KeyCnt != 2)
		{
			AddChara(CHARA_TYPE_ITEM_POINT_2, 2000, 700, 1, 0);
			AddChara(CHARA_TYPE_ITEM_POINT_1, 2500, 700, 1, 0);
		}
		_cgBg = LoadGraph("res/bg/keyroom.png");
		break;
	case 7:
		_Map = 7;
		_mapData.InitMap(1);
		bgSize_w = 2880;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW2();
		_cam._rcLimit.h = _mapData.GetWorldSizeH2();
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		AddChara(CHARA_TYPE_ITEM_POINT_0, 2500, 700, 1,0);
		_cgBg = LoadGraph("res/bg/kitchin.png");
		break;
	}
	if (IsColorFade() == 0)
	{
		ColorFadeIn(10);
	}
	_FadeStep = 0;
	_MapMove = 0;
	_moveFlag = 0;
}

void SceneGameMain::MapChange2(int MapNom)
{
	//ステージ2のマップ限定
	for(int i = 0; i < CHARA_MAX; i++)
	{	//一度プレイヤー以外のすべてを初期化
		if(_gChara[i].type != CHARA_TYPE_PLAYER1)
		{
			DeleteChara(i);
		}

	}

	_Evcnt1 = 0;
	_Evcnt2= 0;
	_Evcnt3 = 0;
	_cam._rcLimit.x = 0;
	_cam._rcLimit.y = 0;
	PlayerEscape = 0;
	switch(MapNom)
	{
	case 0:
		_Map2 = 0;
		bgSize_w = 7680;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW1();
		_cam._rcLimit.h = _mapData.GetWorldSizeH1();
		_mapData.InitMap(0);
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 7650, 900, 0, 0);
		AddChara(CHARA_TYPE_GIMMICK_DOOR_1, 5710, 930, 1,0);
		AddChara(CHARA_TYPE_GIMMICK_CAGE, 508, 903, 1,0);
		if (SceneEv  < 11)
		{
			AddChara(CHARA_TYPE_ENEMY_2, 5000, 800, -1, 0);
			
		}
		if (SceneEv == 11)
		{
			AddChara(CHARA_TYPE_ITEM_POINT_4, 6000, 900, 1, 0);
		}
		_cgBg = LoadGraph("res/bg/stage2/廊下/stage2_1.png");
		LoadDivGraph("res/gimmick/stage2/door2_1.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_DOOR]);
		LoadDivGraph("res/gimmick/stage2/dooropen2.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR]);
		LoadDivGraph("res/gimmick/stage2/door2_5.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR + 5]);
		LoadDivGraph("res/gimmick/stage2/doorclose2.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_CLOSE_DOOR]);
		break;

	case 1:
		_Map2 = 1;
		bgSize_w = 7680;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW1();
		_cam._rcLimit.h = _mapData.GetWorldSizeH1();
		_mapData.InitMap(0);
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 7650, 900, 0, 0);
		AddChara(CHARA_TYPE_GIMMICK_DOOR_2, 4777, 915, 1,0);
		if (SceneEv >= 3 && SceneEv <= 5)
		{
			AddChara(CHARA_TYPE_ENEMY_4, 3000, 1080, 1, 1);
			SceneEv = 4;
		}
		if (SceneEv >= 6 && SceneEv <= 8)
		{
			AddChara(CHARA_TYPE_ENEMY_1, 4200, 1000, -1, 0);
			
		}
		if (SceneEv == 9)
		{
			AddChara(CHARA_TYPE_ENEMY_2, 3000, 700, 1, 0);
			SceneEv = 10;
		}
		if (SceneEv == 11)
		{
			AddChara(CHARA_TYPE_ITEM_POINT_4, 4500, 900, 1, 0);
		}
		_cgBg = LoadGraph("res/bg/stage2/廊下/stage2_2.png");
		LoadDivGraph("res/gimmick/stage2/door2_1.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_DOOR]);
		LoadDivGraph("res/gimmick/stage2/dooropen2.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR]);
		LoadDivGraph("res/gimmick/stage2/door2_5.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR + 5]);
		LoadDivGraph("res/gimmick/stage2/doorclose2.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_CLOSE_DOOR]);
		break;
	case 2:
		_Map2 = 2;
		bgSize_w = 7680;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW1();
		_cam._rcLimit.h = _mapData.GetWorldSizeH1();
		_mapData.InitMap(0);
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		AddChara(CHARA_TYPE_GIMMICK_DOOR_3, 2010, 915, 1,0);
		AddChara(CHARA_TYPE_GIMMICK_DOOR_4, 5643, 915, 1,0);
		if (SceneEv >= 0 && SceneEv < 2)
		{
			AddChara(CHARA_TYPE_ENEMY_2, 5000, 800, -1, 0);
		}
		if (SceneEv == 2)
		{
			PlaySoundMem(_se[SE_EVENT_ZOMBIE], DX_PLAYTYPE_BACK, TRUE);
			AddChara(CHARA_TYPE_ENEMY_3, 5300, 1100, -1, 0);
			SceneEv = 3;
		}
		if (SceneEv >= 10)
		{
			AddChara(CHARA_TYPE_ENEMY_1, 5000, 1000, -1, 0);
		}
		_cgBg = LoadGraph("res/bg/stage2/廊下/stage2_3.png");
		LoadDivGraph("res/gimmick/stage2/door2_1.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_DOOR]);
		LoadDivGraph("res/gimmick/stage2/dooropen2.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR]);
		LoadDivGraph("res/gimmick/stage2/door2_5.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR + 5]);
		LoadDivGraph("res/gimmick/stage2/doorclose2.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_CLOSE_DOOR]);
		break;
	case 3:
		_Map2 = 3;
		bgSize_w = 7680;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW1();
		_cam._rcLimit.h = _mapData.GetWorldSizeH1();
		_mapData.InitMap(0);
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		AddChara(CHARA_TYPE_GIMMICK_DOOR_5, 6810, 915, 1,0);
		if (SceneEv >= 0 && SceneEv < 5)
		{
			AddChara(CHARA_TYPE_ENEMY_2, 5000, 800, -1, 0);
		}
		if (SceneEv == 5)
		{
			AddChara(CHARA_TYPE_ITEM_POINT_4, 3000, 900, 1, 0);
			
		}
		_cgBg = LoadGraph("res/bg/stage2/廊下/stage2_4.png");
		LoadDivGraph("res/gimmick/stage2/door2_1.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_DOOR]);
		LoadDivGraph("res/gimmick/stage2/dooropen2.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR]);
		LoadDivGraph("res/gimmick/stage2/door2_5.png", 1, 1, 1, 365, 615, &_cgChara[PT_GIMMICK_OPEN_DOOR + 5]);
		LoadDivGraph("res/gimmick/stage2/doorclose2.png", 5, 5, 1, 365, 615, &_cgChara[PT_GIMMICK_CLOSE_DOOR]);
		break;
	case 4:
		_Map2 = 4;
		bgSize_w = 2880;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW2();
		_cam._rcLimit.h = _mapData.GetWorldSizeH2();
		_mapData.InitMap(1);
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		AddChara(CHARA_TYPE_GIMMICK_PC_3, 1800, 970, 1, 0);
		if (SceneEv >= 7)
		{
			AddChara(CHARA_TYPE_ENEMY_2, 2800, 800, -1, 0);
			SceneEv = 8;
		}
		
		_cgBg = LoadGraph("res/bg/stage2/pcroom2/pcroom2_1.png");
		break;
	case 5:
		_Map2 = 5;
		bgSize_w = 2880;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW2();
		_cam._rcLimit.h = _mapData.GetWorldSizeH2();
		_mapData.InitMap(1);
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		AddChara(CHARA_TYPE_GIMMICK_PC_1, 1700, 970, 1, 0);
		_cgBg = LoadGraph("res/bg/stage2/pcroom2/pcroom2_2.png");
		break;
	case 6:
		_Map2 = 6;
		bgSize_w = 2880;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW2();
		_cam._rcLimit.h = _mapData.GetWorldSizeH2();
		_mapData.InitMap(1);
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		AddChara(CHARA_TYPE_GIMMICK_PC_2, 1700, 970, 1, 0);
		_cgBg = LoadGraph("res/bg/stage2/pcroom2/pcroom2_3.png");

		break;
	case 7:
		_Map2 = 7;
		bgSize_w = 2880;
		bgSize_h = 1080;
		_cam._rcLimit.w = _mapData.GetWorldSizeW2();
		_cam._rcLimit.h = _mapData.GetWorldSizeH2();
		_mapData.InitMap(1);
		AddChara(CHARA_TYPE_GIMMICK_MOVE_HITRECT, 50, 900, 0, 0);
		if (_KeyCnt != 2)
		{
			AddChara(CHARA_TYPE_ITEM_POINT_2, 2000, 700, 1, 0);
			AddChara(CHARA_TYPE_ITEM_POINT_1, 2500, 700, 1, 0);
		}
		_cgBg = LoadGraph("res/bg/keyroom.png");
		

		break;
	}
	if (IsColorFade() == 0)
	{
		ColorFadeIn(10);
	}
	_FadeStep = 0;
	_MapMove = 0;
	_moveFlag = 0;
}

void SceneGameMain::MapChange3(int MapNom)
{
	//ステージ3のマップ限定
	for (int i = 0; i < CHARA_MAX; i++)
	{	//一度プレイヤー以外のすべてを初期化
		if (_gChara[i].type != CHARA_TYPE_PLAYER1)
		{
			DeleteChara(i);
		}
	}

	_Evcnt1 = 0;
	_Evcnt2 = 0;
	_Evcnt3 = 0;
	_cam._rcLimit.x = 0;
	_cam._rcLimit.y = 0;
	switch (MapNom)
	{
	case 0:
		_Map2 = 0;
		bgSize_w = 8533;
		bgSize_h = 2160;
		_cam._rcLimit.w = _mapData.GetWorldSizeW3();
		_cam._rcLimit.h = _mapData.GetWorldSizeH3();
		_mapData.InitMap(2);
		AddChara(CHARA_TYPE_GIMMICK_STAIR, 1080, 2023, 1,0);
		AddChara(CHARA_TYPE_ENEMY_4, 6000, 2160, -1,1);
		AddChara(CHARA_TYPE_ITEM_POINT_4, 800, 2000, 1, 0);
		AddChara(CHARA_TYPE_GIMMICK_PC_2, 5200, 2040, 1, 0);
		AddChara(CHARA_TYPE_GIMMICK_PC_3, 2510, 1260, 1, 0);
		AddChara(CHARA_TYPE_GIMMICK_PC_1, 7100, 1260, 1, 0);
		AddChara(CHARA_TYPE_GIMMICK_ESCAPE_PC, 3230, 2040, 1, 0);
		AddChara(CHARA_TYPE_GIMMICK_EVENT_HITRECT, 7680, 2100, 1, 0);
		AddChara(CHARA_TYPE_GIMMICK_LOCKER, 1700, 2070, 0, 0);
		_cgBg = LoadGraph("res/bg/stage3/stage3.png");
		break;
	}
}

