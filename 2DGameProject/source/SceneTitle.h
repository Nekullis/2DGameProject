//----------------------------------------------------------------------
// @filename SceneTitle.h
// @author: Fukuma Kyohei
// @explanation
// ゲームのタイトルクラス
//----------------------------------------------------------------------
#pragma once
#include "scene.h"

class SceneTitle : public Scene
{
public:
	// コンストラクタ
	SceneTitle();
	// デストラクタ
	virtual ~SceneTitle();

	// 入力
	void Input() override;
	// 計算
	void Process()override;
	// 描画
	void Draw() override;
};

