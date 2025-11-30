#define	_CRT_SECURE_NO_WARNINGS		// sprintf()を使うため
#include "DxLib.h"
#include "winmain.h"
#include "gamemain.h"
#include "mymath.h"
#include "mydraw.h"
#include "s_gamemain.h"
#include "s_gameover.h"


int		SceneGameMain::CharaProcessPlayer(int i) {
	int motChg = -1;
	int useLRMove = 0;	// キーの左右移動をするなら1
	int moveSpeed = 0;	// プレイヤーの移動速度
	int useKNIFE = 0;	// ボタンによる投擲を許可するなら1
	int useSe = 0;		// 鼓動音をながすなら1

	//ステージ3以外なら初めのプレイヤーモーションを変える
	if (_StageNo != 3)
	{
		if (SceneEv == 0)
		{
			_gChara[i].motId = MOTION_START_STAIR_DOUN;
			SceneEv = 1;
		}
	}
	
	//ドア移動フラグが立った時プレイヤーのX座標を変更する
	if (_moveX == 1)
	{
		_gChara[i].x = 150;
		_moveX = 0;
	}

	if (_StageNo == 3)
	{	//ロッカーに入った際の当たり判定を変更する
		if (ChangeLockerFlag == 1)
		{
			_gChara[i].motId = MOTION_L_STAND;
			_gChara[i].drawuse = 0;
			_gChara[i].useGravity = 0;
			_gChara[i].hx = 0;
			_gChara[i].hy = 0;
			_gChara[i].hw = 0;
			_gChara[i].hh = 0;
			_gChara[i].x = 1700;

		}
		//ロッカーから出た際当たり判定を戻す
		else
		{
			_gChara[i].hx = -58;
			_gChara[i].hy = -400;
			_gChara[i].hw = 100;
			_gChara[i].hh = 400;
			_gChara[i].useGravity = 1;
			_gChara[i].drawuse = 1;
		}
	}
	
	//フェードイン、アウト中でなければ操作できる
	if (_moveFlag == 0 && IsColorFade() == 0)
	{
		// 現在のモーションによって操作を分ける
		switch (_gChara[i].motId) {
		case MOTION_R_STAND:
		case MOTION_L_STAND:
		case MOTION_R_RUN:
		case MOTION_L_RUN:
		case MOTION_R_WALK:
		case MOTION_L_WALK:
		{	
			_gChara[i].useGravity = 1;
			useKNIFE = 1;
			useSe = 1;
			// 立ち/歩き
			// 何も入力が無ければ立ち
			if (_gChara[i].arrow < 0) {
				motChg = MOTION_L_STAND;
			}
			else {
				motChg = MOTION_R_STAND;
			}

			// 入力によって操作
			useLRMove = 1;
			if (PlayerEscape != 1)
			{
				moveSpeed = 8;
				// 左右でモーションだけ切り替える
				if (gPad._key & PAD_INPUT_LEFT) {
					motChg = MOTION_L_WALK;
					_gChara[i].arrow = -1;
					PlArrow = -1;
				}
				if (gPad._key & PAD_INPUT_RIGHT) {
					motChg = MOTION_R_WALK;
					_gChara[i].arrow = 1;
					PlArrow = 1;
				}
			}
			else
			{
				//敵に見つかっていたら走るように
				moveSpeed = 9;
				if (gPad._key & PAD_INPUT_LEFT) {
					motChg = MOTION_L_RUN;
					_gChara[i].arrow = -1;

				}
				if (gPad._key & PAD_INPUT_RIGHT) {
					motChg = MOTION_R_RUN;
					_gChara[i].arrow = 1;

				}
			}

			if (gPad._trg & PAD_INPUT_1)
			{
				//しゃがむ
				if (_gChara[i].arrow < 0)
				{
					motChg = MOTION_L_SQUAT;
				}
				else
				{
					motChg = MOTION_R_SQUAT;
				}

			}

			if (useHierarchy == 1)
			{
				if (gPad._trg & PAD_INPUT_UP)
				{
					//階段を昇る
					motChg = MOTION_STAIR_UP_BACK;
					useHierarchy = 0;
					_gChara[i].Hierarchy = 1;
				}
			}
			else if (useHierarchy == 2)
			{
				if (gPad._trg & PAD_INPUT_DOWN)
				{
					//階段を降りる
					motChg = MOTION_STAIR_DOWN_BACK;
					useHierarchy = 0;
					_gChara[i].Hierarchy = 0;
				}
			}
			break;
		}

		//PC解除中に移動する際のモーション変更
		case MOTION_UNLOCK:
		{
			useSe = 1;
			useLRMove = 1;
			if (gPad._key & PAD_INPUT_LEFT) 
			{
				motChg = MOTION_L_WALK;
				_gChara[i].arrow = -1;
			}
			if (gPad._key & PAD_INPUT_RIGHT) 
			{
				motChg = MOTION_R_WALK;
				_gChara[i].arrow = 1;
			}
			break;
		}

		// ダメージ中
		case MOTION_L_DAMAGE:
		case MOTION_R_DAMAGE:
		{	
			// 特に何もしない
			break;
		}

		//しゃがんでいる
		case MOTION_L_LIEDOWN:
		case MOTION_R_LIEDOWN:
		{
			useSe = 1;
			if (gPad._trg & PAD_INPUT_1)
			{
				if (_gChara[i].arrow < 0)
				{
					motChg = MOTION_L_GETUP;
				}
				else
				{
					motChg = MOTION_R_GETUP;
				}
			}
			break;
		}

		//階段を昇降する一連のモーション
		case MOTION_STAIR_DOWN_BACK:
		case MOTION_STAIR_DOWN_FRONT:
		case MOTION_STAIR_UP_BACK:
		case MOTION_STAIR_UP_FRONT:
		{
			//重力をなくす
			_gChara[i].useGravity = 0;
		}
		}

		// 入力によって操作
		if (useLRMove != 0) {
			int mx = 0;
			if (gPad._key & PAD_INPUT_LEFT) {
				mx = -moveSpeed;
			}
			if (gPad._key & PAD_INPUT_RIGHT) {
				mx = moveSpeed;
			}
			if (IsColorFade() != 1)
			{
				_gChara[i].x += mx;
			}
			
			// 移動可能か？当たり判定。移動不可なら中で位置調整
			if (CheckCharaMove(i, mx, 0) == 1)
			{

			}

			//マップ移動フラグが立った場合の処理
			if (_MapMove == 1)
			{
				switch (_FadeStep)
				{
				case 0:
				{
					_FadeStep++;
					break;
				}
				//フェードイン、アウト中ではないことの確認
				case 1:
				{
					if (IsColorFade() == 0)
					{
						// フェードイン終了
						_FadeStep++;
					}
					break;
				}
				// フェードアウト開始
				case 2:
				{
					ColorFadeOut(0, 0, 0, 30);
					_FadeStep++;
					break;
				}
				// フェードアウト終了後、ステージ、マップ、場所によって移動先の変更
				case 3:
				{
					if (IsColorFade() == 0)
					{
						switch (_StageNo)
						{
						case 1:
						{
							if (_gChara[i].x >= 7450)
							{

								if (_Map == 0)
								{
									_gChara[i].x = 400;
									MapChange1(1);
								}
								else if (_Map == 1)
								{
									_gChara[i].x = 400;
									MapChange1(2);
								}

							}
							else if (_gChara[i].x <= 350)
							{
								if (_Map == 1)				//廊下2
								{
									_gChara[i].x = 7400;
									MapChange1(0);			//廊下1へ
								}
								else if (_Map == 2)			//廊下3
								{
									_gChara[i].x = 7400;
									MapChange1(1);			//廊下2へ
								}
								else if (_Map == 3)			//pcroom1
								{
									_gChara[i].x = 4500;
									if (PcClear1 == 1)
									{
										if (SceneEv == 1)
										{
											PlaySoundMem(_se[SE_EVENT_CLOSECAGE], DX_PLAYTYPE_BACK, TRUE);
											SceneEv = 2;
										}										
									}
									MapChange1(0);		//廊下1へ
								}
								else if (_Map == 4)			//pcroom2
								{
									if (KeyDoor == 2)
									{
										SceneEv = 3;
									}
									_gChara[i].x = 6000;
									MapChange1(1);				//廊下2へ
								}
								else if (_Map == 5)			//pcroom3
								{
									if (KeyDoor == 2)
									{										
										SceneEv = 3;
									}
									_gChara[i].x = 2100;
									MapChange1(2);				//廊下3へ
								}
								else if (_Map == 6)			//keyroom
								{									
									if (_KeyCnt == 2)
									{
										SceneEv = 4;
									}
									_gChara[i].x = 5700;
									MapChange1(2);				//廊下3へ
								}
								else if (_Map == 7)			//kniferoom
								{
									_gChara[i].x = 2380;
									MapChange1(1);				//廊下2へ
								}
							}
							break;
						}

						case 2:
						{
							if (_gChara[i].x >= 7550)
							{
								if (_Map2 == 0)				//廊下1
								{
									_gChara[i].x = 120;
									MapChange2(1);			//廊下2へ
								}
								else if (_Map2 == 1)		//廊下2
								{
									_gChara[i].x = 120;
									MapChange2(3);			//廊下4へ
								}
							}
							else if (_gChara[i].x <= 100)
							{

								if (_Map2 == 1)				//廊下2
								{
									_gChara[i].x = 7400;
									MapChange2(0);			//廊下1へ
								}
								else if (_Map2 == 2)		//廊下3
								{
									_gChara[i].x = 4790;
									MapChange2(1);			//廊下2へ
								}
								else if (_Map2 == 3)		//廊下4
								{
									_gChara[i].x = 7400;
									MapChange2(1);			//廊下3へ
								}
								else if (_Map2 == 4)		//pcroom1 pc3
								{
									if (PcClear3 == 1)
									{
										if (SceneEv == 8)
										{
											SceneEv = 9;
										}
									}
									_gChara[i].x = 5710;
									MapChange2(0);				//廊下1へ
								}
								else if (_Map2 == 5)		//pcroom2 pc1
								{
									if (PcClear1 == 1)
									{
										if (SceneEv == 1)
										{
											SceneEv = 2;
										}
									}
									_gChara[i].x = 2000;
									MapChange2(2);				//廊下3へ
								}
								else if (_Map2 == 6)		//pcroom3 pc2
								{
									if (PcClear2 == 1)
									{
										if (SceneEv == 4)
										{
											SceneEv = 5;
										}
									}
									_gChara[i].x = 6900;
									MapChange2(3);				//廊下4へ
								}
								else if (_Map2 == 7)		//keyroom
								{
									if (_KeyCnt == 2)
									{
										SceneEv = 11;
									}
									_gChara[i].x = 5800;
									MapChange2(2);				//廊下3へ
								}
							}
							break;
						}
						}
					}
					break;
				}
				}
			}
		}

		//投擲ができるモーション中であり、ナイフを持っていた場合Xボタンで投げれるように、
		if (useKNIFE != 0) {
			if (gPad._trg & PAD_INPUT_3) {
				if (_KnifeCnt != 2)
				{
					//ナイフを持っていない場合投げれないモーションに変更
					if (_gChara[i].arrow < 0)
					{
						motChg = MOTION_L_NO_THROW;
					}
					else
					{
						motChg = MOTION_R_NO_THROW;
					}
				}
				else
				{
					if (_gChara[i].arrow < 0)
					{
						motChg = MOTION_L_THROW;
					}
					else
					{
						motChg = MOTION_R_THROW;
					}
					_KnifeCnt = 1;
					cnt1Flag = 1;
				}
			}
		}

		//プレイヤーの体力によって鼓動音を変更
		if(useSe != 1)
		{
			switch(_gChara[i].hp)
			{
			case 0:
				StopSoundMem(_se[SE_PLAYER_HEARTBEAT + 2]);
			case 1:
				if(CheckSoundMem(_se[SE_PLAYER_HEARTBEAT + 2] == 0) || CheckSoundMem(_se[SE_PLAYER_HEARTBEAT + 1] == 0) || CheckSoundMem(_se[SE_PLAYER_HEARTBEAT + 0] == 0))
				{
					StopSoundMem(_se[SE_PLAYER_HEARTBEAT + 1]);
					StopSoundMem(_se[SE_PLAYER_HEARTBEAT + 0]);
					PlaySoundMem(_se[SE_PLAYER_HEARTBEAT + 2], DX_PLAYTYPE_LOOP, TRUE);
				}
				break;
			case 2:
				if(CheckSoundMem(_se[SE_PLAYER_HEARTBEAT + 2] == 0) || CheckSoundMem(_se[SE_PLAYER_HEARTBEAT + 1] == 0) || CheckSoundMem(_se[SE_PLAYER_HEARTBEAT + 0] == 0))
				{
					StopSoundMem(_se[SE_PLAYER_HEARTBEAT + 2]);
					StopSoundMem(_se[SE_PLAYER_HEARTBEAT + 0]);
					PlaySoundMem(_se[SE_PLAYER_HEARTBEAT + 1], DX_PLAYTYPE_LOOP, TRUE);
				}
				break;
			case 3:
				if(CheckSoundMem(_se[SE_PLAYER_HEARTBEAT + 2] == 0) || CheckSoundMem(_se[SE_PLAYER_HEARTBEAT + 1] == 0) || CheckSoundMem(_se[SE_PLAYER_HEARTBEAT + 0] == 0))
				{
					StopSoundMem(_se[SE_PLAYER_HEARTBEAT + 2]);
					StopSoundMem(_se[SE_PLAYER_HEARTBEAT + 1]);
					PlaySoundMem(_se[SE_PLAYER_HEARTBEAT + 0], DX_PLAYTYPE_LOOP, TRUE);
				}
				break;
			}
		}

		//PC操作中、解除できていなければ操作モーションに
		if (_EvPcBar1 != 0)
		{
			if (gPad._trg & PAD_INPUT_4)
			{
				motChg = MOTION_UNLOCK;
			}
		}
		if (_EvPcBar2 != 0)
		{
			if (gPad._trg & PAD_INPUT_4)
			{
				motChg = MOTION_UNLOCK;
			}
		}
		if (_EvPcBar3 != 0)
		{
			if (gPad._trg & PAD_INPUT_4)
			{
				motChg = MOTION_UNLOCK;
			}
		}
		if (_gChara[i].arrow < 0)
		{
			PlArrow = -1;
		}
		else
		{
			PlArrow = 1;
		}
	}
	return motChg;
}

int	SceneGameMain::CharaDamagePlayer(int i, int j) 
{
	//ダメージモーション
	int motChg = -1;
	if (IsColorFade() == 0)
	{
		if (_gChara[i].arrow < 0) { motChg = MOTION_L_DAMAGE; }
		else { motChg = MOTION_R_DAMAGE; }
	}
	
	 //ダメージSE
	 //敵によってSEを変える
	if (_gChara[j].type == CHARA_TYPE_ENEMY_4 )
	{
		PlaySoundMem(_se[SE_PLAYER_DAMAGE + 2], DX_PLAYTYPE_BACK, TRUE);
	}
	else if(_gChara[j].type == CHARA_TYPE_PLEFFECT_KNIFE)
	{
		PlaySoundMem(_se[SE_PLAYER_DAMAGE + 1], DX_PLAYTYPE_BACK, TRUE);
	}
	else 
	{
		PlaySoundMem(_se[SE_PLAYER_DAMAGE + 0], DX_PLAYTYPE_BACK, TRUE);
	}
	
	//敵によって減少する体力の量を変える
	switch(_gChara[j].type)
	{
	case CHARA_TYPE_ENEMY_1:
	{
		_gChara[i].hp = 0;
		break;
	}
		
	case CHARA_TYPE_ENEMY_2:
	case CHARA_TYPE_ENEMY_3:
	{
		_gChara[i].hp--;
		break;
	}

	case CHARA_TYPE_ENEMY_4:
	{
		if(_gChara[j].motId == MOTION_ENEMY4_L_ATTACK || _gChara[j].motId == MOTION_ENEMY4_R_ATTACK)
		{
			_gChara[i].hp = 0;
			
		}
		break;
	}

	case CHARA_TYPE_PLEFFECT_KNIFE:
		_gChara[i].hp--;
		break;

	}

	//ナイフで攻撃された場合、ナイフを消す
	if(_gChara[j].group == CHARA_GROUP_PLAYER_EFFECT) 
	{
		DeleteChara(j);
	}
	return motChg;
}