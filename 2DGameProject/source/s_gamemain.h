//----------------------------------------------------------------------
// @filename s_gamemain.h
// @author: Fukuma Kyohei
// @explanation
// ゲーム中のキャラクター制御などを行うクラス
//----------------------------------------------------------------------

#pragma once
#include "motiondata.h"
#include "MapData.h"
#include "Camera.h"
#include "scene.h"
#include "UIItem.h"

class SceneGameMain : public Scene {
public:
	SceneGameMain();			// コンストラクタ
	virtual ~SceneGameMain();	// デストラクタ

	void	Input() override;	// 入力
	void	Process() override;	// 計算
	void	Draw() override;	// 描画

public:
	// キャラ１体分の情報
	struct CHARA {
		int		type;		// キャラタイプ。 CHARA_TYPE_xxxx
		int		group;		// キャラグループ。CHARA_GROUP_xxxx
		int		x, y;		// 配置座標
		int		hx, hy, hw, hh;		// 地形/キャラ用当たり判定(配置座標からの差分)
		int		hp, maxhp;	// 体力/最大体力
		// ここから下はプログラム内で使用
		int		arrow;		// 向き。左 = -1, 右 = 1
		int		motId;		// モーションID。 MOTION_xxxx_xxxxx
		int		motcnt;		// モーションカウンタ。0～
		int		animcnt;	// アニメーションカウンタ。0～
		int		useGravity;	// 重力処理をするなら1, 落ちないなら0
		int		gravity;	// 重力による加速値
		int		stand;		// 床フラグ。着地していたら1
		int		livecnt;	// 所持数
		int		layer;		// レイヤー
		int		clear;		// 状態保持に使う
		int		drawuse;		// 1で描画 初期値1

		int		Hierarchy;			//プレイヤーがステージ3のとき、一階なら1,二階なら2

		int		respawn;	// リスポーンフラグ。リスポーンするなら1
		int		respawn_x, respawn_y;	// リスポーン座標
	};

	int		_cgBg;		// 背景画像
	int		_cgLightBg; //靄
	int		_cgWaterSurface[3];	//水面
	int		_cgEventAlert[8];	//アラート
	
	int		_bgm;
	int		bgm_volume;
	// 開発用
	int	_debugViewCollision = 0;		// コリジョン表示の有無
	
	UIItem _uiitem;

	int cgKey[3];			//鍵描画用
	int cgKnife[3];			//ナイフ描画用
	
	int bgcnt;				// 水面の描写
	int bganimcnt;			// 水面の描写 
	//ギミック用
	int _EvPcBar1;			
	int _EvPcBar2;			
	int _EvPcBar3;			
	int _Evcnt1;			
	int _Evcnt2;
	int _Evcnt3;
	int _cgPosBar;			// pcのギミックで使うバー(外)
	int _cgBar;				// pcのギミックで使うバー(中)
	int _EvPcFlag;			// pcロック解除した際に+1
	int KeyDoor;			// すべてのロックを解除した際に1にする(キールームのロック解除)
	int PcClear1;			// pcのロックを解除した際、マップチェンジで初期化されても状態を保つ
	int PcClear2;			// pcのロックを解除した際、マップチェンジで初期化されても状態を保つ
	int PcClear3;			// pcのロックを解除した際、マップチェンジで初期化されても状態を保つ
	int EscapePcClear;		// pcのロックを解除した際、マップチェンジで初期化されても状態を保つ

	int AlertCnt;			// アラームが鳴るイベントの間アニメーションするためのカウント

	int SceneEv;			// イベントフラグ　イベントはほぼすべてこれで制御

	int _moveFlag;			// 1の時に出入りできる
	int _KnifeCnt;			// ナイフカウント　0なら表示しない,1なら持っていない,2なら持っている
	int _KeyCnt;			// 鍵カウント　　　0なら表示しない,1なら持っていない,2なら持っている
	int _HealCnt;			// 回復アイテムを拾った
	int _Step;				// ステージクリア関数内のフェードに必要なステップ			   
	int _GameOverStep;		// ゲームオーバー関数内のフェードに必要なステップ
	int _GameOver;			// ゲームオーバーフラグ
	int _FadeStep;			// フェードイン、アウト含むイベントの制御ステップ
	int EnemyKnifeCnt;		// 視認して一定時間たったらナイフをなげる
	int PlayerEscape;		// 敵に見つかったフラグ

	int _stageclear;		// ステージクリアフラグ

	int useHierarchy;		// プレイヤー用階段昇降フラグ
	int useEnHierarchy;		// ボス用階段昇降フラグ
	int cnt1Flag;			// カウントがいる処理に使う
	int cnt1;				// プロセスで増やす
	int StanCnt;			// ボスのスタンに用いるカウント
	int StanCntFlag;		// ボスのスタンに用いるフラグ
	int StanNom;			// スタンカウントを計算したもの
	int ItemCntFlag;		// ITEM_POINT_4用フラグ
	int ItemCnt;			// ITEM_POINT_4用カウント

	int PlArrow;			
	int ChangeLockerFlag;	//ロッカー用フラグ
	
							
	//マップ用
	int _StageNo;			//ステージ番号
	int _Map;				//ステージ1マップ番号
	int _Map2;				//ステージ1マップ番号
	int _Map3;				//ステージ1マップ番号
	int _MapMove;			//マップ間移動フラグ
	int _moveX;				//ドアを用いたマップ間移動フラグ

	int _GameClear;			// ゲームクリアフラグ
	int _GameClearStep;		// ゲームクリアシーンに移行するためのステップ

	//文章に関する変数,関数
	int _cgSentence[10];
	int SentenceNo;
	int SentenceCnt;
	int SentenceFlag;
	void	DrawSentence() const;
	void	ProcessSentence();

	//キャラクター追加、削除に関する関数
	int		AddChara(int type, int x, int y, int arrow, int useGravity);
	void	DeleteChara(int charaIndex);
	//マップ変更に使う関数
	void    MapChange1(int MapNom);
	void	MapChange2(int MapNom);
	void	MapChange3(int MapNom);
	//ステージクリア時の関数
	void    StageClear();
	//ゲームオーバー時の関数
	void	GameOver();
	//ゲームクリア時の関数
	void	GameClear();

	// ゲーム進行の停止をするなら1
	int		_gamePause = 0;

protected:
	void	ProcessCharacter();	// 計算：キャラクタ処理
	void	ProcessStaging();	// 計算：特殊演出

	MYRECT	GetHitRectFromChara(int charaIndex) const;
	MYRECT	GetHitRectFromFrame(int frameId, int hitrectIndex, int cx, int cy, int mirror_lr);
	int		CheckCharaMove(int charaIndex, int mx, int my);
	void	CharaChangeMotion(int charaIndex, int motion);
	int		SearchFrame(int frameId);
	int		IsCheckCharaExistCollision(int i, int j) const;	// 物理
	int		IsCheckCharaLogicCollision(int i, int j) const;	// 判定

	// キャラごとの処理(scenegamemain_chara_xxx.cpp)
	int		CharaProcessPlayer(int i);
	int		CharaDamagePlayer(int i, int j);
	int		CharaProcessEnemys(int i);			
	int		CharaProcessPlayerEffect(int i);
	int		CharaDamagePlayerEffect(int i, int j);
	int		CharaDamageEnemys(int i, int j);
	int		CharaProcessItems(int i);
	int		CharaDamageItems(int i, int j);
	int		CharaSearchEnemys(int i) const;
	int		CharaProcessGimmick(int i);
	int		CharaChangeGimmick(int i, int j);
	int     CharaChangeOpen(int i, int j);
	int		EnemyThrowKnife(int i, int j) const;
	int		CharaRunEnemy(int i, int j) const;

protected:
	// キャラタイプ
#define	CHARA_TYPE_NONE		0	// キャラ無し（use=0的に使用）
#define	CHARA_TYPE_PLAYER1	1	// プレイヤー1
#define	CHARA_TYPE_PLAYER2	2	// プレイヤー2
#define	CHARA_TYPE_PLEFFECT_KNIFE	3	// プレイヤーのファイアーボール

#define	CHARA_TYPE_ITEM_POINT_0		10	// アイテム：光0
#define	CHARA_TYPE_ITEM_POINT_1		11	// アイテム：光1
#define	CHARA_TYPE_ITEM_POINT_2		12	// アイテム：光2
#define	CHARA_TYPE_ITEM_POINT_3		13	// アイテム：光3
#define CHARA_TYPE_ITEM_POINT_4		14	// エネミー用アイテム

#define	CHARA_TYPE_ENEMY_1			20	// 敵：タイプ1
#define	CHARA_TYPE_ENEMY_2			21	// 敵：タイプ2
#define	CHARA_TYPE_ENEMY_3			22	// 敵：タイプ3
#define	CHARA_TYPE_ENEMY_4			23	// 敵：タイプ4
#define	CHARA_TYPE_ENEMY_5			24	// 敵：タイプ5
#define	CHARA_TYPE_ENEMY_6			25	// 敵：タイプ6

#define CHARA_TYPE_GIMMICK_DOOR_1   30  // ギミック:ドア1
#define CHARA_TYPE_GIMMICK_DOOR_2   31  // ギミック:ドア2
#define CHARA_TYPE_GIMMICK_DOOR_3   32  // ギミック:ドア3
#define CHARA_TYPE_GIMMICK_DOOR_4   33  // ギミック:ドア4
#define CHARA_TYPE_GIMMICK_DOOR_5   34  // ギミック:ドア5
#define CHARA_TYPE_GIMMICK_PC_1		40	// ギミック:PC1
#define CHARA_TYPE_GIMMICK_PC_2		41  // ギミック:PC2
#define CHARA_TYPE_GIMMICK_PC_3		42	// ギミック:PC3
#define CHARA_TYPE_GIMMICK_ESCAPE_PC 43 // ギミック:脱出PC
#define CHARA_TYPE_GIMMICK_CAGE		50  // ギミック:檻
#define CHARA_TYPE_GIMMICK_STAIR	60	// ギミック:階段
#define CHARA_TYPE_GIMMICK_LOCKER	61	// ギミック:ロッカー
#define CHARA_TYPE_GIMMICK_ELEVATOR 70  // ギミック:エレベーター
#define CHARA_TYPE_GIMMICK_EVENT_HITRECT 80	// ギミック:壁
#define CHARA_TYPE_GIMMICK_EVENT_OPEN_HITRECT 81	// ギミック:壁
#define CHARA_TYPE_GIMMICK_MOVE_HITRECT		82		// ギミック:移動用当たり判定
#define CHARA_TYPE_GIMMICK_MOVE_OPEN_HITRECT	83	// ギミック:移動用当たり判定
	
// キャラグループ
#define	CHARA_GROUP_PLAYER			1	// プレイヤー
#define	CHARA_GROUP_PLAYER_EFFECT	2	// プレイヤーのエフェクト
#define	CHARA_GROUP_ENEMY			3	// 敵
#define	CHARA_GROUP_ITEM			4	// アイテム
#define CHARA_GROUP_GIMMICK			5   // ギミック

#define	CHARA_MAX		100				// キャラ数
	struct CHARA _gChara[CHARA_MAX];	// キャラ実体

	// ゲーム向け情報
	struct GAMEINFO {
		int score;		// スコア
	};
	struct GAMEINFO	_gameInfo;

	// マップデータ
	MapData _mapData;

	int bgSize_w;
	int bgSize_h;

	// カメラ
	Camera _cam;

	int _GameOverStage;

	// 特殊演出
#define STAGING_NONE	0	// なし
#define STAGING_START	1	// start
#define STAGING_MISS	2	// miss
	int _stagingProc = STAGING_NONE;

};
