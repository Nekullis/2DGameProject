//----------------------------------------------------------------------
// @filename scene.h
// @author: Fukuma Kyohei
// @explanation
// ゲームのシーン変移のクラス
//----------------------------------------------------------------------
#pragma once

class Scene {
public:
	// コンストラクタ
	Scene();
	// デストラクタ
	virtual ~Scene();	

	// 入力
	virtual void Input() = 0;
	// 計算
	virtual void Process() = 0;
	// 描画
	virtual void Draw() = 0;
};