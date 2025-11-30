//----------------------------------------------------------------------
// @filename motiondate.h
// @author: Fukuma Kyohei
// @explanation
// キャラクターなどのモーションに使うクラス
//----------------------------------------------------------------------
#pragma once

// キャラクタ動作テーブル
struct CHARA_MOTION_ITEM {
	int		frameId;	// 表示したいフレームID
	int		frameCnt;	// 何フレーム表示するか
	int		mx, my;		// 表示中、1フレームあたり移動する値
};

// １モーションあたり、モーションアイテムをいくつまで書けるか
#define	CHARA_MOTION_ITEM_MAX	100

// モーションアイテム用コマンド。frameId に指定して使う。frameIdと重複してはいけない
// コマンドはフレーム終了時に処理されるため、最初のフレームには指定できない仕様
#define	CHARA_MOTION_CMD_LOOP		1	// モーションをループする(frameCntにモーションindex指定)
#define	CHARA_MOTION_CMD_MOTION		2	// 別のモーションへ(frameCntにモーション番号指定)
#define	CHARA_MOTION_CMD_PLAYSE		3	// 効果音再生(frameCntにSE_xxxx)
#define	CHARA_MOTION_CMD_HPCHECK	4	// HPをチェックし0以下なら死亡
#define CHARA_MOTION_CMD_FIRE		5	// 投擲をする
#define CHARA_MOTION_CMD_LAYER		7	// 一時的にレイヤーを変える
#define CHARA_MOTION_CMD_END		8	// ゲームオーバー
#define CHARA_MOTION_CMD_GRAVITY	9	// 重力処理を行う
#define CHARA_MOTION_CMD_CHANGE		10	// ゾンビになる


struct CHARA_MOTION {
	int		mirror_lr;	// 左右反転するなら1, しないなら0
	CHARA_MOTION_ITEM	item[CHARA_MOTION_ITEM_MAX];
};

// モーション番号。0番からの通し番号であること
#define	MOTION_R_STAND			0
#define	MOTION_L_STAND			1
#define	MOTION_R_RUN			2
#define	MOTION_L_RUN			3
#define MOTION_R_WALK			4
#define MOTION_L_WALK			5
#define	MOTION_R_DAMAGE			6
#define	MOTION_L_DAMAGE			7
#define MOTION_R_SQUAT			8
#define	MOTION_L_SQUAT			9
#define MOTION_R_LIEDOWN		10
#define	MOTION_L_LIEDOWN		11
#define MOTION_R_GETUP			12
#define	MOTION_L_GETUP			13
#define MOTION_R_THROW			14
#define	MOTION_L_THROW			15
#define MOTION_R_NO_THROW		16
#define	MOTION_L_NO_THROW		17
#define MOTION_R_DEATH			18
#define MOTION_L_DEATH			19
#define MOTION_UNLOCK			20
#define MOTION_STAIR_DOWN_BACK	21
#define MOTION_STAIR_DOWN_FRONT	22
#define MOTION_STAIR_UP_BACK	23
#define MOTION_STAIR_UP_FRONT	24
#define MOTION_START_STAIR_DOUN	25

// アイテム用
#define	MOTION_ITEM_POINT_0_NORMAL	26	
#define	MOTION_ITEM_POINT_1_NORMAL	27	
#define	MOTION_ITEM_POINT_2_NORMAL	28	
#define	MOTION_ITEM_POINT_3_NORMAL	29	
#define MOTION_ITEM_POINT_4_NORMAL  30  

// 敵1用
#define	MOTION_ENEMY1_R_RUN		31
#define	MOTION_ENEMY1_L_RUN		32
#define	MOTION_ENEMY1_R_DAMAGE	33
#define	MOTION_ENEMY1_L_DAMAGE	34
#define MOTION_ENEMY1_R_ATTACK	35
#define MOTION_ENEMY1_L_ATTACK	36
#define MOTION_ENEMY1_R_TURN	37
#define MOTION_ENEMY1_L_TURN	38
// 敵2用
#define	MOTION_ENEMY2_R_RUN		39
#define	MOTION_ENEMY2_L_RUN		40
#define	MOTION_ENEMY2_R_DAMAGE	41
#define	MOTION_ENEMY2_L_DAMAGE	42
#define MOTION_ENEMY2_R_ATTACK	43
#define MOTION_ENEMY2_L_ATTACK	44
#define MOTION_ENEMY2_R_TURN	45
#define MOTION_ENEMY2_L_TURN	46
#define MOTION_ENEMY2_R_DEATH	47
#define MOTION_ENEMY2_L_DEATH	48
#define MOTION_CHANGE_ZOMBIE	49
// 敵3用
#define	MOTION_ENEMY3_R_RUN		50
#define	MOTION_ENEMY3_L_RUN		51
#define	MOTION_ENEMY3_R_DAMAGE	52
#define	MOTION_ENEMY3_L_DAMAGE	53
#define MOTION_ENEMY3_R_ATTACK	54
#define MOTION_ENEMY3_L_ATTACK	55
#define MOTION_ENEMY3_R_TURN	56
#define MOTION_ENEMY3_L_TURN	57
// 敵4用
#define	MOTION_ENEMY4_R_UNDISCOVER_RUN	58
#define	MOTION_ENEMY4_L_UNDISCOVER_RUN	59
#define	MOTION_ENEMY4_R_RUN				60
#define	MOTION_ENEMY4_L_RUN				61
#define	MOTION_ENEMY4_R_DAMAGE			62
#define	MOTION_ENEMY4_L_DAMAGE			63
#define MOTION_ENEMY4_R_ATTACK			64
#define MOTION_ENEMY4_L_ATTACK			65
#define MOTION_ENEMY4_R_THROW			66
#define MOTION_ENEMY4_L_THROW			67
#define MOTION_ENEMY4_R_STAN			68
#define MOTION_ENEMY4_L_STAN			69
#define MOTION_ENEMY4_R_RECOVERY_STAN	70
#define MOTION_ENEMY4_L_RECOVERY_STAN	71
#define MOTION_ENEMY_CUTLOCKER	        72
#define MOTION_ENEMY4_STAIR_DOWN_BACK	73
#define MOTION_ENEMY4_STAIR_DOWN_FRONT	74
#define MOTION_ENEMY4_STAIR_UP_BACK		75
#define MOTION_ENEMY4_STAIR_UP_FRONT	76
// 敵5用
#define MOTION_ENEMY5_R_RUN				77
#define MOTION_ENEMY5_L_RUN				78
// ギミック用
#define MOTION_GIMMICK_DOOR				79
#define MOTION_GIMMICK_OPEN_DOOR		80
#define MOTION_GIMMICK_OPENED_DOOR		81
#define MOTION_GIMMICK_CLOSE_DOOR		82
#define MOTION_GIMMICK_PC				83
#define MOTIOM_GIMMICK_OPEN_PC			84
#define MOTION_GIMMICK_CLOSE_PC			85
#define MOTION_GIMMICK_ESCAPE_PC		86
#define MOTION_GIMMICK_ESCAPE_OPEN_PC	87
#define MOTION_GIMMICK_ESCAPE_CLOSE_PC	88
#define MOTION_GIMMICK_CAGE				89
#define MOTION_GIMMICK_OPEN_CAGE		90
#define MOTION_GIMMICK_STAIR			91
#define MOTION_GIMMICK_STAIR_UP			92
#define MOTION_GIMMICK_STAIR_DOWN		93
#define MOTION_GIMMICK_LOCKER			94
#define MOTION_GIMMICK_OPEN_LOCKER		95
#define MOTION_PLAYERGIMMICK_INLOCKER	96
#define MOTION_GIMMICK_ELEVATOR			97
#define MOTION_GIMMICK_OPEN_ELEVATOR	98
#define MOTION_GIMMICK_EVENT_ELEVATOR   99
#define MOTION_GIMMICK_EVENT_HITRECT	100
#define MOTION_GIMMICK_EVENT_OPEN_HITRECT	101
#define MOTION_GIMMICK_MOVE_HITRECT		102
#define MOTION_GIMMICK_MOVE_OPEN_HITRECT	103

// エフェクト：ファイアーボール
#define	MOTION_EFFECT_KNIFE_R_RUN		104
#define	MOTION_EFFECT_KNIFE_L_RUN		105

extern struct CHARA_MOTION tblMotion[];
