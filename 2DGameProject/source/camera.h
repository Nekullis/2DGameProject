//----------------------------------------------------------------------
// @filename camera.h
// @author: Fukuma Kyohei
// @explanation
// ゲーム中の追尾カメラを制御するクラス
//----------------------------------------------------------------------
#pragma once
#include "DxLib.h"		
#include "mymath.h"

class Player;

class Camera {
public:
	Camera();
	~Camera();

    //カメラ
    static Camera w_camera;

	void	Process();

	//ゲッター
	const MATRIX*	GetViewMatrix() const { return &_mView; }
	void  SetTarget(Player* target) { m_target = target; }

public:
	int _camControl;	// カメラ操作するなら1
	MATRIX	_mView;		// View行列
	VECTOR	_pos;		// カメラの位置。world座標で
	VECTOR	_lookat;	// カメラの注視点。画面のここを中心に、拡大/回転をする
	float	_scale;		// カメラの拡大率
	float	_rotate;	// カメラの回転（degree)
	MYRECT	_rcLimit;	// world座標でリミット設定

private:
    Player* m_target;
    float m_offsetX;
};