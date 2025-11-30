#pragma once
#include "scene.h"

class SceneStory :public Scene {
public:
	SceneStory();		// コンストラクタ
	virtual ~SceneStory();		// デストラクタ

	void	Input() override;		// 入力
	void	Process() override;		// 計算
	void	Draw() override;		// 描画

public:

	

protected:
	int		_cgStory;		// ストーリー画像
};