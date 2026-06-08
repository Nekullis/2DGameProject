#include "camera.h"
#include "winmain.h"
#include "Player.h"

Camera Camera::w_camera;
Camera::Camera() :m_target(nullptr), m_offsetX(0.0f)
{
	// 位置がリミットを超えないように（回転は加味せず）
	_pos = VGet(SCREEN_W / 2, SCREEN_H / 2, 0);
    _lookat = VGet(SCREEN_W / 2, SCREEN_H / 2, 0);
	_camControl = 0;
	_scale = 1.0f;
	_rotate = 0.0f;
	_mView = MGetIdent();
	_rcLimit = { 0 };
}

Camera::~Camera() 
{
	// 何もしない
}

void	Camera::Process() 
{
    //カメラがマップ外を写さないように
	float left, top, right, bottom;
    left = _rcLimit.x / _scale;
	right = (_rcLimit.x + _rcLimit.w) - SCREEN_W / _scale;
	top = _rcLimit.y / _scale;
	bottom = (_rcLimit.y + _rcLimit.h) - SCREEN_H / _scale;

    //オフセット値
    const float MAX_OFFSET = 300.0f;
    float targetOffsetX = 0.0f;
    if (m_target->GetVelocity().x > 0)
    {
        targetOffsetX = MAX_OFFSET;
    }
    else if (m_target->GetVelocity().x < 0)
    {
        targetOffsetX = -MAX_OFFSET;
    }
    m_offsetX += (targetOffsetX - m_offsetX) * 0.01f;

    float targetX = m_target->GetPosition().x - _lookat.x + m_offsetX;
    float targetY = m_target->GetPosition().y - _lookat.y;
	_pos.x = Clamp(left, right, targetX);
	_pos.y = Clamp(top, bottom, targetY);

	// View行列の生成
	MATRIX m = MGetTranslate(VScale(_pos, -1));				// カメラ位置を*-1する
	m = MMult(m, MGetScale(VGet(_scale, _scale, 1)));		// Z方向の倍率は1のまま
	m = MMult(m, MGetRotZ(DegToRad(_rotate)));				// 2Dでx,yを回転させるには、3DならZ軸回転になる
	m = MMult(m, MGetTranslate(_lookat));					// 注視点分ずらす
	_mView = m;
}

