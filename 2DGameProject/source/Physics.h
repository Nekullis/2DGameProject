//----------------------------------------------------------------------
// @filename Physics.h
// @author: Fukuma Kyohei
// @explanation
// オブジェクトの当たり判定、押し戻しに関するクラス
//----------------------------------------------------------------------
#pragma once
#include "mymath.h"

enum class CollisionSide
{
    None,
    Left,
    Right,
    Top,
    Bottom,
};

class Physics
{
public:
	//Box同士の衝突解決
	static CollisionSide ResolveBoxCollision(MYRECT& moving, const MYRECT& wall);
};

