#define	_CRT_SECURE_NO_WARNINGS		// sprintf()を使うため
#include "DxLib.h"
#include "winmain.h"
#include "gamemain.h"
#include "mymath.h"
#include "mydraw.h"
#include "s_gameover.h"
#include "s_gamemain.h"

int		SceneGameMain::CharaProcessEnemys(int i) {
	
	int motChg = -1;
	if(_gChara[i].hp != 0)
	{
		switch(_gChara[i].type)
		{
		//	マグロ
		case CHARA_TYPE_ENEMY_1:
		{	// 向いている方向に少しずつ進む

			int mx = 0;

			int speed = 8;
			if (_StageNo == 1)
			{
				if (SceneEv >= 5)
				{
					speed = 0;
				}
			}
			mx = _gChara[i].arrow * speed;
			_gChara[i].x += mx;

			// 移動可能か？当たり判定。移動不可なら中で位置調整
			if(CheckCharaMove(i, mx, 0) == 1) {
				// 当たったので方向反転

				if(_gChara[i].arrow == 1)
				{
					motChg = MOTION_ENEMY1_R_TURN;
				}
				else
				{
					motChg = MOTION_ENEMY1_L_TURN;
				}
				_gChara[i].arrow *= -1;

			}

			break;
		}

		//イワシ
		case CHARA_TYPE_ENEMY_2:
		{	// 向いている方向に少しずつ進む
			int mx = 0;

			int speed = 9;
			
			
				mx = _gChara[i].arrow * speed;
			
			
			switch (_gChara[i].motId)
			{
			case MOTION_ENEMY2_R_RUN:
			case MOTION_ENEMY2_L_RUN:
			case MOTION_ENEMY2_R_ATTACK:
			case MOTION_ENEMY2_L_ATTACK:
			{
				_gChara[i].x += mx;
				// 移動可能か？当たり判定。移動不可なら中で位置調整
				if (CheckCharaMove(i, mx, 0) == 1)
				{
					// 当たったので方向反転
					if (_gChara[i].arrow < 0)
					{
						motChg = MOTION_ENEMY2_L_TURN;
					}
					else
					{
						motChg = MOTION_ENEMY2_R_TURN;
					}
					_gChara[i].arrow *= -1;
				}
				break;
			}
			}

			if (_StageNo == 2)
			{
				if (SceneEv == 9)
				{
					_gChara[i].motId = MOTION_ENEMY2_R_DEATH;

				}
			}
			break;
		}
		//ゾンビ
		case CHARA_TYPE_ENEMY_3:
		{
			// 向いている方向に少しずつ進む
			int mx = 0;
			int speed = 11;
			
			
			mx = _gChara[i].arrow * speed;
			switch (_gChara[i].motId)
			{
			case MOTION_ENEMY3_R_RUN:
			case MOTION_ENEMY3_L_RUN:
			case MOTION_ENEMY3_R_ATTACK:
			case MOTION_ENEMY3_L_ATTACK:
			{
				_gChara[i].x += mx;
				
				// 移動可能か？当たり判定。移動不可なら中で位置調整
				if (CheckCharaMove(i, mx, 0) == 1)
				{
					// 当たったので方向反転
					if (_gChara[i].arrow < 0) { motChg = MOTION_ENEMY3_L_TURN; }
					else { motChg = MOTION_ENEMY3_R_TURN; }
					_gChara[i].arrow *= -1;
				}
				break;
			}
			}
			break;
		}
		//ボス
		case CHARA_TYPE_ENEMY_4:
		{
			int mx = 0;
			int speed = 10;
			switch(_gChara[i].motId)
			{
			case MOTION_ENEMY4_R_UNDISCOVER_RUN:
			case MOTION_ENEMY4_L_UNDISCOVER_RUN:
			{
				_gChara[i].useGravity = 1;
				mx = _gChara[i].arrow * speed;
				_gChara[i].x += mx;
				if (_gChara[i].arrow < 0) { motChg = MOTION_ENEMY4_L_UNDISCOVER_RUN; }
				else { motChg = MOTION_ENEMY4_R_UNDISCOVER_RUN; }

				if (CheckCharaMove(i, mx, 0) == 1)
				{

					_gChara[i].arrow *= -1;
				}
				if (useEnHierarchy == 1) { motChg = MOTION_ENEMY4_STAIR_UP_BACK; }
				else if (useEnHierarchy == 2) { motChg = MOTION_ENEMY4_STAIR_DOWN_BACK; }
				break;
			}

			case MOTION_ENEMY4_R_RUN:
			case MOTION_ENEMY4_L_RUN:
			{
				StanCntFlag = 0;
				StanNom = 0;
				_gChara[i].useGravity = 1;
				mx = _gChara[i].arrow * speed;
				_gChara[i].x += mx;
				
				if (_gChara[i].arrow < 0) { motChg = MOTION_ENEMY4_L_RUN; }
				else { motChg = MOTION_ENEMY4_R_RUN; }
				if (CheckCharaMove(i, mx, 0) == 1) { _gChara[i].arrow *= -1; }
				if(useEnHierarchy == 1)
				{
					motChg = MOTION_ENEMY4_STAIR_UP_BACK;
					useEnHierarchy = 0;
				}
				else if(useEnHierarchy == 2)
				{
					motChg = MOTION_ENEMY4_STAIR_DOWN_BACK;
					useEnHierarchy = 0;
				}
				break;
			}

			case MOTION_ENEMY4_R_ATTACK:
			case MOTION_ENEMY4_L_ATTACK:
			{
				speed = 0;
				break;
			}

			case MOTION_ENEMY4_STAIR_DOWN_BACK:
			case MOTION_ENEMY4_STAIR_DOWN_FRONT:
			case MOTION_ENEMY4_STAIR_UP_BACK:
			case MOTION_ENEMY4_STAIR_UP_FRONT:
			{
				_gChara[i].useGravity = 0;
				useEnHierarchy = 0;
				break;
			}

			case MOTION_ENEMY4_R_STAN:
			case MOTION_ENEMY4_L_STAN:
			{
				StanCntFlag = 1;
				if (StanCnt== 0)
				{
					if (_gChara[i].arrow < 0) { motChg =  MOTION_ENEMY4_L_RECOVERY_STAN; }
					else { motChg = MOTION_ENEMY4_R_RECOVERY_STAN; }
				}
				break;
			}

			case MOTION_ENEMY4_L_RECOVERY_STAN:
			case MOTION_ENEMY4_R_RECOVERY_STAN:
			{
				break;
			}
			}
			break;
		}

		//魚群
		case CHARA_TYPE_ENEMY_5:
		{
			int mx = 0;
			int speed = 20;
			mx = _gChara[i].arrow * speed;
			_gChara[i].x += mx;
			if (_gChara[i].arrow < 0) { motChg = MOTION_ENEMY5_L_RUN; }
			else { motChg = MOTION_ENEMY5_R_RUN; }
		}
		}
	}
	
	return motChg;
}

int	SceneGameMain::CharaDamageEnemys(int i, int j) 
{
	int motChg = -1;
	//ダメージモーションに切り替え
	switch (_gChara[i].type) 
	{
	case CHARA_TYPE_ENEMY_1:
		if (_gChara[i].arrow < 0) { motChg = MOTION_ENEMY1_L_DAMAGE; }
		else { motChg = MOTION_ENEMY1_R_DAMAGE; }
		break;
	case CHARA_TYPE_ENEMY_2:
		if (_gChara[i].arrow < 0) { motChg = MOTION_ENEMY2_L_DAMAGE; }
		else { motChg = MOTION_ENEMY2_R_DAMAGE; }
		PlayerEscape = 0;
		break;
	case CHARA_TYPE_ENEMY_3:
		if (_gChara[i].arrow < 0) { motChg = MOTION_ENEMY3_L_DAMAGE; }
		else { motChg = MOTION_ENEMY3_R_DAMAGE; }
		break;
	case CHARA_TYPE_ENEMY_4:
		if (_gChara[i].arrow < 0) { motChg = MOTION_ENEMY4_L_DAMAGE; }
		else { motChg = MOTION_ENEMY4_R_DAMAGE; }
		//ナイフを投げて当たるまでの時間でスタン時間を変える
		if (cnt1Flag == 1)
		{
			StanNom = cnt1 / 30;
			if (StanNom <= 1) { StanCnt = 300; }
			else if (StanNom > 2 && StanNom <= 4)
			{
				StanCnt = 150;
			}
			else if (StanNom > 5 && 7 >= StanNom)
			{
				StanCnt = 60;
			}
			else if (StanNom > 8)
			{
				StanCnt = 30;
			}
			cnt1Flag = 0;
			cnt1 = 0;
		}
		break;
	}

	// ダメージSE
	switch (_gChara[i].type)
	{	
	case CHARA_TYPE_ENEMY_2:
		PlaySoundMem(_se[SE_ENEMY2_DEAD], DX_PLAYTYPE_BACK, TRUE);
		break;
	case CHARA_TYPE_ENEMY_3:
		PlaySoundMem(_se[SE_ENEMY3_DEAD], DX_PLAYTYPE_BACK, TRUE);
		break;
	case CHARA_TYPE_ENEMY_4:
		PlaySoundMem(_se[SE_ENEMY4_DAMAGE], DX_PLAYTYPE_BACK, TRUE);
		break;
	}
	
	// 相手がPLAYER_EFFECTなら相手を削除
	if(_gChara[j].group == CHARA_GROUP_PLAYER_EFFECT) 
	{
		DeleteChara(j);
	}

	// HPを減らす
	_gChara[i].hp--;
	return motChg;
}

int	SceneGameMain::CharaSearchEnemys(int i) const
{	//攻撃モーションに切り替え
	int motChg = -1;
	switch(_gChara[i].type) 
	{
	case CHARA_TYPE_ENEMY_1:
		if(_gChara[i].arrow < 0) 
		{ 
			motChg = MOTION_ENEMY1_L_ATTACK; 
		}
		else 
		{	
			motChg = MOTION_ENEMY1_R_ATTACK; 
		}
		break;

	case CHARA_TYPE_ENEMY_2:
		if(_gChara[i].arrow < 0)
		{
			motChg = MOTION_ENEMY2_L_ATTACK;
		}
		else 
		{
			motChg = MOTION_ENEMY2_R_ATTACK; 
		}
		break;

	case CHARA_TYPE_ENEMY_3:
		if(_gChara[i].arrow < 0) 
		{ 
			motChg = MOTION_ENEMY3_L_ATTACK; 
		}
		else 
		{ 
			motChg = MOTION_ENEMY3_R_ATTACK;
		}
		break;

	case CHARA_TYPE_ENEMY_4:
		if(_gChara[i].arrow < 0) 
		{ 
			motChg = MOTION_ENEMY4_L_ATTACK; 
		}
		else 
		{ 
			motChg = MOTION_ENEMY4_R_ATTACK;
		}
		break;
	
	}
	return motChg;
}

int	SceneGameMain::EnemyThrowKnife(int i, int j) const
{	//ボス:投擲モーションに切り替え
	int motChg = -1;
	if (_StageNo != 1)
	{
		if (EnemyKnifeCnt % 300 == 0)
		{
			if (_gChara[i].arrow < 0)
			{
				motChg = MOTION_ENEMY4_L_THROW;
			}
			else
			{
				motChg = MOTION_ENEMY4_R_THROW;
			}
		}
	}
	return motChg;
}

int SceneGameMain::CharaRunEnemy(int i, int j) const
{	//ボス未発見状態:発見時に投擲モーション移行後発見状態に
	int motChg = -1;

	if (_gChara[i].arrow < 0) { motChg = MOTION_ENEMY4_L_THROW; }
	else { motChg = MOTION_ENEMY4_R_THROW; }

	return motChg;
}

