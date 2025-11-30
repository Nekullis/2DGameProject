//----------------------------------------------------------------------
// @filename scene.h
// @author: Fukuma Kyohei
// @explanation
// ゲームのシーン変移のクラス
//----------------------------------------------------------------------
#pragma once
#include"mymaclo.h"

class Scene {
public:
	Scene();			// コンストラクタ
	virtual ~Scene();	// デストラクタ

	virtual void	Input();		// 入力
	virtual void	Process();		// 計算
	virtual void	Draw();			// 描画
public:
	int		_cgChara[_PT_CHARA_ALLNUM_];	// キャラ画像
	int		_se[_SE_ALL_];					// 効果音セット
};