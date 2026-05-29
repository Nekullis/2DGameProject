//----------------------------------------------------------------------
// @filename Physics.h
// @author: Fukuma Kyohei
// @explanation
// オブジェクトの当たり判定、押し戻しに関するクラス
//----------------------------------------------------------------------
#pragma once
#include "mymath.h"

class Physics
{
public:
	//Box同士の衝突解決
	static bool ResolveBoxCollision(MYRECT& moving, const MYRECT& wall);
};

