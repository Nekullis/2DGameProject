#define	_CRT_SECURE_NO_WARNINGS		// sprintf()を使うため
#include "DxLib.h"
#include "winmain.h"
#include "gamemain.h"
#include "mymath.h"
#include "mydraw.h"
#include "s_gamemain.h"
#include "s_gameover.h"

int		SceneGameMain::CharaProcessGimmick(int i) 
{
	int motChg = -1;
	switch (_gChara[i].type)
	{
	case CHARA_TYPE_GIMMICK_DOOR_1:
	case CHARA_TYPE_GIMMICK_DOOR_2:
	case CHARA_TYPE_GIMMICK_DOOR_3:
	case CHARA_TYPE_GIMMICK_DOOR_4:
	case CHARA_TYPE_GIMMICK_DOOR_5:
	{	//	ギミック:ドア
		if (_gChara[i].motId == MOTION_GIMMICK_OPENED_DOOR)
		{	//開いている状態でBボタンを押すと移動フラグがたつ
			if (gPad._trg & PAD_INPUT_4)
			{
				_moveFlag = 1;
		
			}

			if (_moveFlag == 1)
			{
				switch (_FadeStep)
				{
				case 0:
				{
					_FadeStep++;
					break;
				}

				case 1:
				{	//フェードイン、アウト状態でなければステップ加算
					if (IsColorFade() == 0)
					{
						// フェードイン終了
						_FadeStep++;
					}
					break;
				}

				case 2:
				{
					// フェードアウト開始
					ColorFadeOut(0, 0, 0, 20);
					_FadeStep++;
					break;
				}

				case 3:
				{	//フェードアウト後にステージ番号とドアによって移動する先を変更
					if (IsColorFade() == 0)
					{
						_moveX = 1;
						switch (_StageNo)
						{
						case 1:	//ステージ1
							if (_gChara[i].type == CHARA_TYPE_GIMMICK_DOOR_1 )
							{
								MapChange1(3);	//PCルーム1へ
								break;
							}
							else if (_gChara[i].type == CHARA_TYPE_GIMMICK_DOOR_2 )
							{
								MapChange1(4);	//PCルーム2へ
								break;
							}
							else if (_gChara[i].type == CHARA_TYPE_GIMMICK_DOOR_3 )
							{
								MapChange1(5);	//PCルーム3へ
								break;
							}
							else if (_gChara[i].type == CHARA_TYPE_GIMMICK_DOOR_4 )
							{
								MapChange1(6);	//キールームへ
								break;
							}
							else if (_gChara[i].type == CHARA_TYPE_GIMMICK_DOOR_5 )
							{
								MapChange1(7);	//キッチンへ
								break;
							}
							
							break;
						case 2:	//ステージ2
							if (_gChara[i].type == CHARA_TYPE_GIMMICK_DOOR_1)
							{
								MapChange2(4);	//PCルーム1へ
								break;
							}
							if (_gChara[i].type == CHARA_TYPE_GIMMICK_DOOR_2)
							{
								MapChange2(2);	//廊下3へ
								break;
							}
							if (_gChara[i].type == CHARA_TYPE_GIMMICK_DOOR_3)
							{
								MapChange2(5);	//PCルーム2へ
								break;
							}
							if (_gChara[i].type == CHARA_TYPE_GIMMICK_DOOR_4)
							{
								MapChange2(7);	//キールームへ
								break;
							}
							if (_gChara[i].type == CHARA_TYPE_GIMMICK_DOOR_5)
							{
								if (SceneEv == 6)
								{
									SceneEv = 7;
								}
								MapChange2(6);	//PCルーム3へ
								break;
							}
							break;
						}
					}
					break;
				}
				}
			}
		}
		break;
	}

	//ギミック:PC
	case CHARA_TYPE_GIMMICK_PC_1:
	{

		if (_gChara[i].motId == MOTIOM_GIMMICK_OPEN_PC)
		{	//PC画面が赤い状態になっていればボタン連打できる

			if (gPad._trg & PAD_INPUT_4)
			{
				_EvPcBar1++;

				if (_EvPcBar1 >= 12)
				{	//成功するとフラグ(_EvPcFlag)を1つ増やす。3になるとキールームにはいれる
					_EvPcFlag += 1;
					PlaySoundMem(_se[SE_GIMMICK_COMPUTER], DX_PLAYTYPE_BACK, TRUE);
					_gChara[i].motId = MOTION_GIMMICK_CLOSE_PC;
					_EvPcBar1 = 0;
					PcClear1 = 1;
				}
			}

		}
		//初期化されないように立たせたフラグ(PcClear)でモーションを変えておく
		if (_gChara[i].clear == 1)
		{
			_gChara[i].motId = MOTION_GIMMICK_CLOSE_PC;
		}
		break;
	}

	case CHARA_TYPE_GIMMICK_PC_2:
	{
		if (_gChara[i].motId == MOTIOM_GIMMICK_OPEN_PC)
		{	
			//PC画面が赤い状態になっていればボタン連打できる
			if (gPad._trg & PAD_INPUT_4)
			{	//成功するとフラグ(_EvPcFlag)を1つ増やす。3になるとキールームにはいれる
				_EvPcBar2++;

				if (_EvPcBar2 >= 12)
				{
					_EvPcFlag += 1;
					PlaySoundMem(_se[SE_GIMMICK_COMPUTER], DX_PLAYTYPE_BACK, TRUE);
					_gChara[i].motId = MOTION_GIMMICK_CLOSE_PC;
					_EvPcBar2 = 0;
					PcClear2 = 1;
				}
			}
		}
		//初期化されないように立たせたフラグ(PcClear)でモーションを変えておく
		if (_gChara[i].clear == 1)
		{
			_gChara[i].motId = MOTION_GIMMICK_CLOSE_PC;
		}
		break;
	}

	case CHARA_TYPE_GIMMICK_PC_3:
	{	//PC画面が赤い状態になっていればボタン連打できる
		if (_gChara[i].motId == MOTIOM_GIMMICK_OPEN_PC)
		{
			if (gPad._trg & PAD_INPUT_4)
			{
				_EvPcBar3++;

				if (_EvPcBar3 >= 12)
				{	//成功するとフラグ(_EvPcFlag)を1つ増やす。3になるとキールームにはいれる
					_EvPcFlag += 1;
					PlaySoundMem(_se[SE_GIMMICK_COMPUTER], DX_PLAYTYPE_BACK, TRUE);
					_gChara[i].motId = MOTION_GIMMICK_CLOSE_PC;
					_EvPcBar3 = 0;
					PcClear3 = 1;
				}
			}
		}
		//初期化されないように立たせたフラグ(PcClear)でモーションを変えておく
		if (_gChara[i].clear == 1)
		{
			_gChara[i].motId = MOTION_GIMMICK_CLOSE_PC;
		}
		break;
	}

	//特殊なPC。ステージ3にしかない
	case CHARA_TYPE_GIMMICK_ESCAPE_PC:
	{
		if (_gChara[i].motId == MOTION_GIMMICK_ESCAPE_OPEN_PC)
		{
			if (gPad._trg & PAD_INPUT_4)
			{
				SentenceFlag = 1;
				PlaySoundMem(_se[SE_GIMMICK_ELEVATER], DX_PLAYTYPE_BACK, TRUE);
				_gChara[i].motId = MOTION_GIMMICK_ESCAPE_CLOSE_PC;
				EscapePcClear = 1;
				//脱出用エレベーターが出現
				AddChara(CHARA_TYPE_GIMMICK_ELEVATOR, 8120, 2160, 0, 0);
			}
		}
		//初期化されないように立たせたフラグ(PcClear)でモーションを変えておく
		if (_gChara[i].clear == 1)
		{
			_gChara[i].motId = MOTION_GIMMICK_ESCAPE_CLOSE_PC;
		}
		break;
	}

	//ギミック:檻
	//各ステージのゴールのようなもの。条件達成させてふれたあとBボタンを押すと次へ進める
	case CHARA_TYPE_GIMMICK_CAGE:
	{
		if (_gChara[i].motId == MOTION_GIMMICK_OPEN_CAGE)
		{
			if (IsColorFade() == 0)
			{
				if (gPad._trg & PAD_INPUT_4)
				{
					PlaySoundMem(_se[SE_GIMMICK_CAGE], DX_PLAYTYPE_BACK, TRUE);
					//ステージクリアフラグ(_stageclear)を立たせる
					switch (_StageNo)
					{
					case 1:
						
						AddChara(CHARA_TYPE_ENEMY_4, 2000, 1100, -1, 1);
						_stageclear = 1;
						break;

					case 2:
						_stageclear = 1;
						break;
					}
				}
			}
		}
		break;
	}

	//ギミック:階段
	//ステージ3のみのギミック、触れると昇降フラグが立つ
	//昇降フラグ(useHierarchy)が1だと降りることができ、2だと昇ることができる
	case CHARA_TYPE_GIMMICK_STAIR:
	{
		if (_gChara[i].motId == MOTION_GIMMICK_STAIR_UP)
		{
			useHierarchy = 1;
		}
		else if (_gChara[i].motId == MOTION_GIMMICK_STAIR_DOWN)
		{
			useHierarchy = 2;
		}
		break;
	}

	//ギミック:エレベーター
	//ステージ3のみのギミック。条件で出現し、入ったあとにBボタンを押すとゲームクリアフラグ(_GameClear)が立つ
	case CHARA_TYPE_GIMMICK_ELEVATOR:
	{
		if (_gChara[i].motId == MOTION_GIMMICK_OPEN_ELEVATOR)
		{
			if (gPad._trg & PAD_INPUT_4)
			{
				_GameClear = 1;
				_gChara[i].motId = MOTION_GIMMICK_EVENT_ELEVATOR;
			}
		}
		break;
	}

	//ギミック:ロッカー
	//ステージ3のみのギミック。ロッカーの目の前でBボタンを押すとボスをやり過ごせる
	case CHARA_TYPE_GIMMICK_LOCKER:
	{
		if (_gChara[i].motId == MOTION_GIMMICK_OPEN_LOCKER)
		{
			if (gPad._trg & PAD_INPUT_4)
			{
				_gChara[i].motId = MOTION_PLAYERGIMMICK_INLOCKER;
				ChangeLockerFlag = 1;
			}
			break;
		}
		if (ChangeLockerFlag == 1)
		{
			if (gPad._trg & PAD_INPUT_4)
			{
				_gChara[i].motId = MOTION_GIMMICK_OPEN_LOCKER;
				ChangeLockerFlag = 0;
			}
			break;
		}
		break;
	}

	//ギミック:透明な壁
	//ステージ3のみのギミック。条件達成で通れるようになる
	case CHARA_TYPE_GIMMICK_EVENT_HITRECT:
	{
		switch (_StageNo)
		{
		case 3:
			if (EscapePcClear == 1)
			{
				_gChara[i].motId = MOTION_GIMMICK_EVENT_OPEN_HITRECT;
			}
			break;
		}
		
	}

	//ギミック:移動用の透明な判定
	//マップ間の移動に使われている当たり判定。フラグ(_MapMove)を立たせる
	case CHARA_TYPE_GIMMICK_MOVE_HITRECT:
	{
		if (_gChara[i].motId == MOTION_GIMMICK_MOVE_OPEN_HITRECT)
		{
			_MapMove = 1;
		}
		break;
	}
	}
	return motChg;
}

int	SceneGameMain::CharaChangeGimmick(int i, int j)
{
	int motChg = -1;
	//ギミックに触れた際のギミックのモーションを変える
	switch (_StageNo)
	{
	case 1:
		switch (_gChara[i].type)
		{
		//ギミック:ドア
		case CHARA_TYPE_GIMMICK_DOOR_1:
			if (_gChara[i].motId == MOTION_GIMMICK_DOOR)
			{
				//プレーヤーの伏せの一連のモーション中は移動できないように
				if (_gChara[j].motId == MOTION_L_LIEDOWN || _gChara[j].motId == MOTION_R_LIEDOWN
					|| _gChara[j].motId == MOTION_L_SQUAT || _gChara[j].motId == MOTION_R_SQUAT
					|| _gChara[j].motId == MOTION_L_GETUP || _gChara[j].motId == MOTION_R_GETUP)
				{
					break;
				}
				else
				{
					PlaySoundMem(_se[SE_GIMMICK_DOOR], DX_PLAYTYPE_BACK, TRUE);
					_gChara[i].motId = MOTION_GIMMICK_OPEN_DOOR; 
					break;
				}
			}
			if (_gChara[i].motId == MOTION_GIMMICK_OPENED_DOOR)
			{
				//プレーヤーの伏せの一連のモーション中は移動できないように
				if (_gChara[j].motId == MOTION_L_LIEDOWN || _gChara[j].motId == MOTION_R_LIEDOWN
					|| _gChara[j].motId == MOTION_L_SQUAT || _gChara[j].motId == MOTION_R_SQUAT
					|| _gChara[j].motId == MOTION_L_GETUP || _gChara[j].motId == MOTION_R_GETUP)
				{
					_gChara[i].motId = MOTION_GIMMICK_CLOSE_DOOR;
					break;
				}
			}
			break;

		case CHARA_TYPE_GIMMICK_DOOR_2:
		case CHARA_TYPE_GIMMICK_DOOR_3:
		case CHARA_TYPE_GIMMICK_DOOR_5:
			if (SceneEv > 1)
			{	//ステージ1では最初の段階だと一部以外移動できないようにイベントフラグ(SceneEv)で制御
				if (_gChara[i].motId == MOTION_GIMMICK_DOOR)
				{
					if (_gChara[j].motId == MOTION_L_LIEDOWN || _gChara[j].motId == MOTION_R_LIEDOWN
						|| _gChara[j].motId == MOTION_L_SQUAT || _gChara[j].motId == MOTION_R_SQUAT
						|| _gChara[j].motId == MOTION_L_GETUP || _gChara[j].motId == MOTION_R_GETUP)
					{
						break;
					}
					else
					{
						PlaySoundMem(_se[SE_GIMMICK_DOOR], DX_PLAYTYPE_BACK, TRUE);
						_gChara[i].motId = MOTION_GIMMICK_OPEN_DOOR;
						break;
					}

				}
				//プレーヤーの伏せの一連のモーション中は移動できないように
				if (_gChara[i].motId == MOTION_GIMMICK_OPENED_DOOR)
				{
					if (_gChara[j].motId == MOTION_L_LIEDOWN || _gChara[j].motId == MOTION_R_LIEDOWN
						|| _gChara[j].motId == MOTION_L_SQUAT || _gChara[j].motId == MOTION_R_SQUAT
						|| _gChara[j].motId == MOTION_L_GETUP || _gChara[j].motId == MOTION_R_GETUP)
					{
						_gChara[i].motId = MOTION_GIMMICK_CLOSE_DOOR;
						break;
					}
				}
			}
			//入れない場合は文章を出す
			if (SceneEv == 1)
			{
				SentenceNo = 8;
			}
			break;

		case CHARA_TYPE_GIMMICK_DOOR_4:
			//PCを3つ解除しなければ入れないように
			if (KeyDoor == 1)
			{
				if (_gChara[i].motId == MOTION_GIMMICK_DOOR)
				{
					//プレーヤーの伏せの一連のモーション中は移動できないように
					if (_gChara[j].motId == MOTION_L_LIEDOWN || _gChara[j].motId == MOTION_R_LIEDOWN
						|| _gChara[j].motId == MOTION_L_SQUAT || _gChara[j].motId == MOTION_R_SQUAT
						|| _gChara[j].motId == MOTION_L_GETUP || _gChara[j].motId == MOTION_R_GETUP)
					{
						break;
					}
					else
					{
						PlaySoundMem(_se[SE_GIMMICK_DOOR], DX_PLAYTYPE_BACK, TRUE);
						_gChara[i].motId = MOTION_GIMMICK_OPEN_DOOR; 
						break;
					}



				}
				if (_gChara[i].motId == MOTION_GIMMICK_OPENED_DOOR)
				{
					//プレーヤーの伏せの一連のモーション中は移動できないように
					if (_gChara[j].motId == MOTION_L_LIEDOWN || _gChara[j].motId == MOTION_R_LIEDOWN
						|| _gChara[j].motId == MOTION_L_SQUAT || _gChara[j].motId == MOTION_R_SQUAT
						|| _gChara[j].motId == MOTION_L_GETUP || _gChara[j].motId == MOTION_R_GETUP)
					{
						_gChara[i].motId = MOTION_GIMMICK_CLOSE_DOOR;
						break;
					}
				}
				break;
			}
			else
			{
				SentenceNo = 3;
			}
			break;

		
		//ギミック:檻
		case CHARA_TYPE_GIMMICK_CAGE:
			if (_gChara[i].motId == MOTION_GIMMICK_CAGE)
			{
				//鍵を持っていないと開けないように
				if (_KeyCnt == 2)
				{
					motChg = MOTION_GIMMICK_OPEN_CAGE;
					break;
				}
				else
				{
					//鍵を持っていないと文章をだす
					SentenceFlag = 2;
					//SentenceNo = 1;
				}
			}
			
			break;
		//ギミック:PC
		case CHARA_TYPE_GIMMICK_PC_1:
		case CHARA_TYPE_GIMMICK_PC_2:
		case CHARA_TYPE_GIMMICK_PC_3:
			//触れるとPC画面が赤くなる
			motChg = MOTIOM_GIMMICK_OPEN_PC; 
			break;

		//ギミック:移動用当たり判定
		case CHARA_TYPE_GIMMICK_MOVE_HITRECT:
			//触れると移動できる
			motChg = MOTION_GIMMICK_MOVE_OPEN_HITRECT;
			break;
		}
		break;

	//ステージ2
	case 2:
		switch (_gChara[i].type)
		{
		//ギミック:ドア
		case CHARA_TYPE_GIMMICK_DOOR_1:
		case CHARA_TYPE_GIMMICK_DOOR_2:
		case CHARA_TYPE_GIMMICK_DOOR_3:
		case CHARA_TYPE_GIMMICK_DOOR_5:
			
			if (_gChara[i].motId == MOTION_GIMMICK_DOOR)
			{
				//プレーヤーの伏せの一連のモーション中は移動できないように
				if (_gChara[j].motId == MOTION_L_LIEDOWN || _gChara[j].motId == MOTION_R_LIEDOWN
					|| _gChara[j].motId == MOTION_L_SQUAT || _gChara[j].motId == MOTION_R_SQUAT
					|| _gChara[j].motId == MOTION_L_GETUP || _gChara[j].motId == MOTION_R_GETUP
					|| _gChara[j].motId == MOTION_L_DAMAGE|| _gChara[j].motId == MOTION_R_DAMAGE)
				{
					break;
				}
				else
				{
					PlaySoundMem(_se[SE_GIMMICK_DOOR], DX_PLAYTYPE_BACK, TRUE);
					 _gChara[i].motId = MOTION_GIMMICK_OPEN_DOOR; 
					break;
				}
			}
			if (_gChara[i].motId == MOTION_GIMMICK_OPENED_DOOR)
			{
				//プレーヤーの伏せの一連のモーション中は移動できないように
				if (_gChara[j].motId == MOTION_L_LIEDOWN || _gChara[j].motId == MOTION_R_LIEDOWN
					|| _gChara[j].motId == MOTION_L_SQUAT || _gChara[j].motId == MOTION_R_SQUAT
					|| _gChara[j].motId == MOTION_L_GETUP || _gChara[j].motId == MOTION_R_GETUP
					|| _gChara[j].motId == MOTION_L_DAMAGE || _gChara[j].motId == MOTION_R_DAMAGE)
				{
					_gChara[i].motId = MOTION_GIMMICK_CLOSE_DOOR;
					break;
				}
			}

			break;
		case CHARA_TYPE_GIMMICK_DOOR_4:
			if (KeyDoor == 1)
			{
				if (_gChara[i].motId == MOTION_GIMMICK_DOOR)
				{
					//プレーヤーの伏せの一連のモーション中は移動できないように
					if (_gChara[j].motId == MOTION_L_LIEDOWN || _gChara[j].motId == MOTION_R_LIEDOWN
						|| _gChara[j].motId == MOTION_L_SQUAT || _gChara[j].motId == MOTION_R_SQUAT
						|| _gChara[j].motId == MOTION_L_GETUP || _gChara[j].motId == MOTION_R_GETUP
						|| _gChara[j].motId == MOTION_L_DAMAGE || _gChara[j].motId == MOTION_R_DAMAGE)
					{
						break;
					}
					else
					{
						PlaySoundMem(_se[SE_GIMMICK_DOOR], DX_PLAYTYPE_BACK, TRUE);
						_gChara[i].motId = MOTION_GIMMICK_OPEN_DOOR; 
						break;
					}
				}
				if (_gChara[i].motId == MOTION_GIMMICK_OPENED_DOOR)
				{
					//プレーヤーの伏せの一連のモーション中は移動できないように
					if (_gChara[j].motId == MOTION_L_LIEDOWN || _gChara[j].motId == MOTION_R_LIEDOWN
						|| _gChara[j].motId == MOTION_L_SQUAT || _gChara[j].motId == MOTION_R_SQUAT
						|| _gChara[j].motId == MOTION_L_GETUP || _gChara[j].motId == MOTION_R_GETUP
						|| _gChara[j].motId == MOTION_L_DAMAGE || _gChara[j].motId == MOTION_R_DAMAGE)
					{
						_gChara[i].motId = MOTION_GIMMICK_CLOSE_DOOR;
						break;
					}
				}
				break;
			}
			else
			{
				SentenceNo = 3;
			}
			break;

		//ギミック:檻
		case CHARA_TYPE_GIMMICK_CAGE:

			if (_KeyCnt == 2)
			{
				motChg = MOTION_GIMMICK_OPEN_CAGE;
			}
			else
			{
				SentenceFlag = 2;
			}
			break;

		//ギミック:PC
		case CHARA_TYPE_GIMMICK_PC_1:
			motChg = MOTIOM_GIMMICK_OPEN_PC;
			break;

		case CHARA_TYPE_GIMMICK_PC_2:
			//PC1を解除していなければ解除できないように
			if (PcClear1 == 1)
			{
				motChg = MOTIOM_GIMMICK_OPEN_PC;
			}
			else
			{
				//条件未達成時は文章をだす
				SentenceNo = 6;
			}
			break;

		case CHARA_TYPE_GIMMICK_PC_3:
			//PC2を解除していなければ解除できないように
			if (PcClear2 == 1)
			{
				motChg = MOTIOM_GIMMICK_OPEN_PC;
			}
			else
			{
				//条件未達成時は文章をだす
				SentenceNo = 6;
			}
			break;
			
		//ギミック:移動用当たり判定
		case CHARA_TYPE_GIMMICK_MOVE_HITRECT:
			//触れると移動できる
			motChg = MOTION_GIMMICK_MOVE_OPEN_HITRECT;
			break;
		
		}
		break;

	//ステージ3
	case 3:
		switch (_gChara[i].type)
		{
		//ギミック:PC
		case CHARA_TYPE_GIMMICK_PC_1:
			motChg = MOTIOM_GIMMICK_OPEN_PC;
			break;

		case CHARA_TYPE_GIMMICK_PC_2:
			//PC1を解除していなければ解除できないように
			if (PcClear1 == 1)
			{
				motChg = MOTIOM_GIMMICK_OPEN_PC;
			}
			break;

		case CHARA_TYPE_GIMMICK_PC_3:
			//PC2を解除していなければ解除できないように
			if (PcClear2 == 1)
			{
				motChg = MOTIOM_GIMMICK_OPEN_PC;
			}
			break;
			
		case CHARA_TYPE_GIMMICK_ESCAPE_PC:
			//すべてのPCを解除していなければ解除できないように
			if (KeyDoor == 1)
			{
				if (_gChara[i].motId == MOTION_GIMMICK_ESCAPE_PC)
				{
					motChg = MOTION_GIMMICK_ESCAPE_OPEN_PC; 
					break;
				}
			}
			break;
		//ギミック:階段
		case CHARA_TYPE_GIMMICK_STAIR:
			if (_gChara[i].motId == MOTION_GIMMICK_STAIR)
			{
				if (_gChara[j].Hierarchy == 0)
				{
					//階段を昇れるように
					motChg = MOTION_GIMMICK_STAIR_UP;
				}
				else if (_gChara[j].Hierarchy == 1)
				{
					//階段を降りれるように
					motChg = MOTION_GIMMICK_STAIR_DOWN;
				}
				break;
			}
			break;

		//ギミック:エレベーター
		case CHARA_TYPE_GIMMICK_ELEVATOR:
			if (_gChara[i].motId == MOTION_GIMMICK_ELEVATOR)
			{
				motChg = MOTION_GIMMICK_OPEN_ELEVATOR;
			}
			break;

		//ギミック:ロッカー
		case CHARA_TYPE_GIMMICK_LOCKER:
			if (_gChara[i].motId == MOTION_GIMMICK_LOCKER)
			{
				motChg = MOTION_GIMMICK_OPEN_LOCKER;
			}
			break;
		}
		break;
	}
	
	return motChg;
}

int		SceneGameMain::CharaChangeOpen(int i, int j)
{	//ギミックから離れた際のモーション変更
	int motChg = -1;
	switch(_gChara[i].type)
	{
	//ギミック:ドア
	case CHARA_TYPE_GIMMICK_DOOR_1:
	case CHARA_TYPE_GIMMICK_DOOR_2:
	case CHARA_TYPE_GIMMICK_DOOR_3:
	case CHARA_TYPE_GIMMICK_DOOR_4:
	case CHARA_TYPE_GIMMICK_DOOR_5:
		if(_gChara[i].motId == MOTION_GIMMICK_OPENED_DOOR)
		{
			PlaySoundMem(_se[SE_GIMMICK_DOOR+1], DX_PLAYTYPE_BACK, TRUE);
			motChg = MOTION_GIMMICK_CLOSE_DOOR; 
		}
		break;
	//ギミック:PC
	case CHARA_TYPE_GIMMICK_PC_1:
		motChg = MOTION_GIMMICK_PC; 
		_EvPcBar1 = 0;
		break;
	case CHARA_TYPE_GIMMICK_PC_2:
		motChg = MOTION_GIMMICK_PC; 
		_EvPcBar2 = 0;
		break;
	case CHARA_TYPE_GIMMICK_PC_3:
		motChg = MOTION_GIMMICK_PC; 
		_EvPcBar3 = 0;
		break;
	case CHARA_TYPE_GIMMICK_ESCAPE_PC:
		motChg = MOTION_GIMMICK_ESCAPE_PC; 
		break;
	//ギミック:檻
	case CHARA_TYPE_GIMMICK_CAGE:
		if (_gChara[i].motId == MOTION_GIMMICK_OPEN_CAGE)
		{
			motChg = MOTION_GIMMICK_CAGE;
		}
		SentenceFlag = 0;
		break;
	//ギミック:階段
	case CHARA_TYPE_GIMMICK_STAIR:
		motChg = MOTION_GIMMICK_STAIR;
		useHierarchy = 0;
		break;
	//ギミック:ロッカー
	case CHARA_TYPE_GIMMICK_LOCKER:
		motChg = MOTION_GIMMICK_LOCKER;
		break;
	//ギミック:エレベーター
	case CHARA_TYPE_GIMMICK_ELEVATOR:
		if (_gChara[i].motId == MOTION_GIMMICK_OPEN_ELEVATOR)
		{
			motChg = MOTION_GIMMICK_ELEVATOR;
		}
		break;
	}
	return motChg;
}


