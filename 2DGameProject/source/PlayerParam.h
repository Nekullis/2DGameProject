//----------------------------------------------------------------------
// @filename PlayerParam.h
// @author: Fukuma Kyohei
// @explanation
// プレイヤーのパラメータに関するデータクラス
//----------------------------------------------------------------------
#pragma once

class PlayerParam
{
public:
	//json読み込み用
	//初回のみロードする
	static void Load();

	//左右移動方向
	static float MoveSpeed;
	//重力
	static float Gravity;
	//初回ジャンプ力
	static float JumpPower;
	//長押し時間
	static float MaxJumpTime;
	//長押し上昇力
	static float AddJumpPower;

private:
	static bool m_loaded;
};

