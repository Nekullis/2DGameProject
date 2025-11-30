//----------------------------------------------------------------------
// @filename mapdata.h
// @author: Fukuma Kyohei
// @explanation
// ゲームマップを制御するクラス
//----------------------------------------------------------------------
#pragma once
#include "DxLib.h"

	// マップチップ関連
#define	CHIPSIZE_W	(40)
#define	CHIPSIZE_H	(40)
// マップデータ
#define	MAPSIZE_W	(220)
#define	MAPSIZE_H	(60)
#define	MAPSIZE_W1	(192)
#define MAPSIZE_H1	(27)
#define	MAPSIZE_W2	(72)
#define MAPSIZE_H2	(27)
#define MAPSIZE_W3	(212)
#define MAPSIZE_H3	(54)

class MapData {
public:
	MapData();			// コンストラクタ
	virtual ~MapData();	// デストラクタ

	void	Draw(MATRIX mView) const;		// マップ描画

	// 当たり判定関連
	int		CheckHitMapChip(int x, int y);	// 指定位置のチップが当たり判定ありか？
	int		CheckHitChip(int chip_no);		// 指定のチップIDが当たり判定ありか？

	struct HITSLIDE {
		int	hit;				// 当たっていれば1、当たっていないければ0
		int	slide_x, slide_y;	// 当たっている場合、ずらすべき値
	};
	HITSLIDE IsHitBox(int box_x, int box_y, int box_w, int box_h, int move_x, int move_y);	// 指定のboxがmove_x,move_yに移動していた場合、マップチップに当たるか？

	// worldのサイズを取得(pixel単位)
	int	GetWorldSizeW1() { return MAPSIZE_W1 * CHIPSIZE_W; }
	int	GetWorldSizeH1() { return MAPSIZE_H1 * CHIPSIZE_H; }
	int	GetWorldSizeW2() { return MAPSIZE_W2 * CHIPSIZE_W; }
	int	GetWorldSizeH2() { return MAPSIZE_H2 * CHIPSIZE_H; }
	int	GetWorldSizeW3() { return MAPSIZE_W3 * CHIPSIZE_W; }
	int	GetWorldSizeH3() { return MAPSIZE_H3 * CHIPSIZE_H; }

	int _no;
	void InitMap(int No);

protected:
	int _gMapData[MAPSIZE_W * MAPSIZE_H];
	// チップ画像
	int	_cgChip[30];
};