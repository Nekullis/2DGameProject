//----------------------------------------------------------------------
// @filename s_gameopening.h
// @author: Fukuma Kyohei
// @explanation
// ゲーム開始時の動画クラス
//----------------------------------------------------------------------
#pragma once
#include "scene.h"
#include"s_gamemain.h"

class SceneGameOpening : public Scene
{
public:
	SceneGameOpening();
	virtual ~SceneGameOpening();

	void	Process() override;		// 計算
	void	Draw() override;		// 描画

protected:
	int _mvOpening;					//動画用
	int OpeningStep;				//ステップ
	int _cgManual[8];				//説明画面描画用
	int ManualCnt;					//カウント
	int ManualAniCnt;				//アニメーションカウント
	SceneGameMain _s_GameMain;
};

