//----------------------------------------------------------------------
// @filename s_gameclear.h
// @author: Fukuma Kyohei
// @explanation
// ゲームオーバー時の画像クラス
//----------------------------------------------------------------------
#pragma once
#include "scene.h"
#include "s_gamemain.h"

class SceneGameOver : public Scene {

public:
	SceneGameOver(int gameovernum);			// コンストラクタ
	virtual ~SceneGameOver();	// デストラクタ

	void	Input() override;		// 入力
	void	Process() override;		// 計算
	void	Draw() override;		// 描画

protected:

	int		_cgEndBg[53];	// 背景画像
	int		_bgm;			// BGM
	int		bgEndcnt;		// 背景画像に使うカウント
	int		bgEndanicnt;	// カウントをアニメーション用に計算する変数
	int		_Endstep;		// ゲームオーバー画面を制御するカウント
	int		StageNom;		// どのステージに戻るか決める変数
};