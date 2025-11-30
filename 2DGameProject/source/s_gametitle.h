//----------------------------------------------------------------------
// @filename s_gameclear.h
// @author: Fukuma Kyohei
// @explanation
// ゲームタイトル時の画像クラス
//----------------------------------------------------------------------
#pragma once
#include "scene.h"

class SceneGameTitle : public Scene {
public:
	SceneGameTitle();			// コンストラクタ
	virtual ~SceneGameTitle();	// デストラクタ

	void	Input() override;		// 入力
	void	Process() override;		// 計算
	void	Draw() override;		// 描画

protected:

	int		_bgm;			// BGM
	int		bgm_volume;		// BGMのボリューム
	int		_step;			// フェードインアウト用ステップ
	int		_cgTitleBg[153];// タイトル背景画像
	int		_cgLogo;		// 学校、背柵チームロゴ
	int		bgcnt;			// 背景画像に使うカウント
	int		bganicnt;		// カウントをアニメーション用に計算する変数

};