//----------------------------------------------------------------------
// @filename scene.h
// @author: Fukuma Kyohei
// @explanation
// ゲームのシーン変移のクラス
//----------------------------------------------------------------------
#pragma once

class Scene {
public:
	Scene();			// コンストラクタ
	virtual ~Scene();	// デストラクタ

	virtual void	Input();		// 入力
	virtual void	Process();		// 計算
	virtual void	Draw();			// 描画
};