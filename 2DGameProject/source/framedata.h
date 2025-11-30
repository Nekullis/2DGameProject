//----------------------------------------------------------------------
// @filename framedata.h
// @author: Fukuma Kyohei
// @explanation
// ゲーム内で使うフレームクラス
//----------------------------------------------------------------------

// .hの先頭に記述。#includeでこのファイルを何度読み込みしても、1度しか読み込まない
#pragma once

// 当たり判定種類
#define	CHARA_HITRECT_TYPE_NONE		0
#define	CHARA_HITRECT_TYPE_ATTACK	1
#define	CHARA_HITRECT_TYPE_DAMAGE	2
#define	CHARA_HITRECT_TYPE_GET		3
#define CHARA_HITRECT_TYPE_SEARCH   4
#define CHARA_HITRECT_TYPE_GIMMICK  5
#define CHARA_HITRECT_TYPE_ESCAPE  6
#define CHARA_HITRECT_TYPE_THROWRANGE 7
#define CHARA_HITRECT_TYPE_UNDISCOVER 8
#define	CHARA_HITRECT_NUM	9				// 1フレーム内にある当たり判定の最大数


// 当たり判定構造体
struct CHARA_HITRECT {
	int		type;				// 当たり判定の種類
	int		hx, hy, hw, hh;		// 基点からの判定矩形
};

// キャラクタフレーム構造体
// 1枚のフレームに関する設定
struct CHARA_FRAME {
	int		frameId;	// フレームID。固有の番号を振る
	int		cgId;		// 使用画像番号 cgChara[]
	int		cx, cy;		// 画像の基点。足下を指定
	int		w, h;		// 画像サイズ
	CHARA_HITRECT	hit[CHARA_HITRECT_NUM];		// 当たり判定矩形
};

extern struct CHARA_FRAME tblFrame[];
