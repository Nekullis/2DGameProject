//----------------------------------------------------------------------
// @filename mymaclo.h
// @author: Fukuma Kyohei
// @explanation
// 定数をまとめたヘッダー
//----------------------------------------------------------------------
#pragma once

// アニメーションパターン用定義
// 配列の番号は間を空けて余裕を持って設定しています
// ※キャラクタ関連の画像はすべて _cgChara[] に読み込むようにするので、このIDを重複しないように設定すること
// プレイヤー
#define	PT_PLAYER_STAND		0		//	96 
#define	PT_PLAYER_RUN		100		//	16 
#define	PT_PLAYER_ATTACK	120		//  16
#define	PT_PLAYER_DAMAGE	140		//  16
#define	PT_PLAYER_SQUAT		160		//  16
#define PT_PLAYER_LIEDOWN   180		//	16
#define PT_PLAYER_GETUP		200		//	16
#define PT_PLAYER_THROW     220		//  16
#define PT_PLAYER_NO_THROW  240		//	16
#define PT_PLAYER_DEATH		260		//	32
#define PT_PLAYER_WALK		300		//	32
#define PT_PLAYER_UNLOCK	340		//	8
#define PT_PLAYER_STAIR		350		//	45
#define PT_PLAYER_START_STAIR 400


// 光アイテム point.png
#define	PT_ITEM_POINT		500		// 100～ 3*4=12枚
// 敵1(tune)
#define	PT_ENEMY1_RUN		600		// 120～ 8枚
#define PT_ENEMY1_ATTACK	610
#define PT_ENEMY1_R_TURN	620
#define PT_ENEMY1_L_TURN	630
// 敵2(seadine)
#define	PT_ENEMY2_RUN		700		// 150～ 7枚
#define PT_ENEMY2_DAMAGE	710
#define PT_ENEMY2_ATTACK	720
#define PT_ENEMY2_R_TURN	730
#define PT_ENEMY2_L_TURN	735
#define PT_ENEMY2_DEATH		740

#define PT_ENEMY_CHANGE_ZOMBIE 750

// 敵3(z_seadine)
#define	PT_ENEMY3_RUN		800		// 180～ 7枚
#define PT_ENEMY3_DAMAGE	810
#define PT_ENEMY3_ATTACK	820
#define PT_ENEMY3_R_TURN	830
#define PT_ENEMY3_L_TURN	835

// 敵4(boss)
#define	PT_ENEMY4_UNDISCOVER_RUN		900		// 32
#define	PT_ENEMY4_RUN					940		// 32
#define PT_ENEMY4_DAMAGE				980		// 16
#define PT_ENEMY4_ATTACK				1000		// 32
#define PT_ENEMY4_THROW					1040		// 32
#define PT_ENEMY4_STAN					1080		// 2
#define PT_ENEMY4_RECOVERY_STAN			1090	//16
#define PT_ENEMY4_CUTLOCKER				1120	//16
#define PT_ENEMY4_STAIR					1140		//45	
// 敵5
#define PT_ENEMY5_RUN					1200

//ギミック
#define PT_GIMMICK_DOOR				1300	//1
#define PT_GIMMICK_OPEN_DOOR		1301	//6
#define PT_GIMMICK_CLOSE_DOOR		1310	//5

#define PT_GIMMICK_OFF_DOOR			1320	//1
#define PT_GIMMICK_OPEN_OFF_DOOR	1321	//6	
#define PT_GIMMICK_CLOSE_OFF_DOOR	1330	//5

#define PT_GIMMICK_PC				1340	//1
#define PT_GIMMICK_OPEN_PC			1341	//1
#define PT_GIMMICK_CLOSE_PC			1342	//1

#define PT_GIMMICK_ESCAPE_PC		1350	//1
#define PT_GIMMICK_ESCAPE_OPEN_PC	1351	//1
#define PT_GIMMICK_ESCAPE_CLOSE_PC	1352	//1

#define PT_GIMMICK_CAGE				1360	//1
#define PT_GIMMICK_OPEN_CAGE		1361	//1

#define PT_GIMMICK_STAIR			1370	//1
#define PT_GIMMICK_STAIR_UP			1371	//1
#define PT_GIMMICK_STAIR_DOWN		1372	//1

#define PT_GIMMICK_LOCKER			1380	//1
#define PT_GIMMICK_OPEN_LOCKER		1381	//1

#define PT_PLAYERGIMMICK_INLOCKER	1382	//1

#define PT_GIMMICK_ELEVATOR			1390	//1
#define PT_GIMMICK_OPEN_ELEVATOR	1391	//1
#define PT_GIMMICK_EVENT_ELEVATOR	1392	//1

#define PT_GIMMICK_EVENT_HITRECT	1400	//1
#define PT_GIMMICK_EVENT_OPEN_HITRECT 1401	//1

#define PT_GIMMICK_MOVE_HITRECT			1410	//1
#define PT_GIMMICK_MOVE_OPEN_HITRECT	1411	//1

// エフェクト：ファイアーボール
#define	PT_EFFECT_KNIFE	    1500		// 190～ 7枚

//総パターン数
#define	_PT_CHARA_ALLNUM_	1600		// 全パターン枚数

// 効果音用定義
// 配列の番号は0～
#define	SE_PLAYER_WALK		0		// 歩き
#define	SE_PLAYER_DAMAGE	10		// ダメージ
#define SE_PLAYER_THROW		13		// 投擲
#define SE_PLAYER_DEAD		14		// 死亡
#define SE_PLAYER_STAIR		15		// 昇降
#define SE_PLAYER_RUN		17		// 走り
#define SE_PLAYER_HEARTBEAT 18

#define SE_ENEMY1_WALK		30		// マグロ移動
#define SE_ENEMY1_ATTACK	31		// マグロ攻撃
#define SE_ENEMY1_EVENT1	32

#define SE_ENEMY2_ATTACK	40		// いわし攻撃
#define SE_ENEMY2_DEAD		41		// いわしダメージ
#define SE_ENEMY2_TO_ZOMBIE 42		// いわしゾンビに変化

#define SE_ENEMY3_ATTACK	50		// ゾンビ攻撃
#define SE_ENEMY3_DEAD		51		// ゾンビ死亡

#define SE_ENEMY4_WALK		60		// 店長歩き	
#define SE_ENEMY4_ATTACK	63		// 店長攻撃
#define SE_ENEMY4_DAMAGE	64		// 店長ダメージ
#define SE_ENEMY4_THROW		65		// 店長投擲
#define SE_ENEMY4_STAIR		66

#define SE_ENEMY5_WALK		70		// 魚群

#define SE_GIMMICK_COMPUTER	80		// コンピュータ
#define SE_GIMMICK_DOOR		90		// ドア
#define SE_GIMMICK_CAGE		100		// 檻
#define SE_GIMMICK_ELEVATER	110

#define SE_ITEM_HEAL		120		// 回復
#define SE_ITEM_KEY			130		// 鍵
#define SE_ITEM_KNIFE		140		// 包丁

#define SE_EVENT_ZOMBIE		150		// イベント1
#define SE_EVENT_ALERT		151		// イベント2
#define SE_EVENT_CLOSECAGE 152 // イベント3

#define	_SE_ALL_	200				// 全SE数