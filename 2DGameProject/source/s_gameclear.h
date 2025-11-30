//----------------------------------------------------------------------
// @filename s_gameclear.h
// @author: Fukuma Kyohei
// @explanation
// ゲームクリアした後のストーリークラス
//----------------------------------------------------------------------
#pragma once
#include "scene.h"

class SceneGameClear : public Scene
{
public:
	SceneGameClear();
	virtual ~SceneGameClear();

	void Input() override;
	void Process()override;
	void Draw()override;

protected:
	//動画描画用
	int _EndMovie;	
};

