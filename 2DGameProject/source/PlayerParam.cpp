#include "PlayerParam.h"
#include "JSONManager.h"

//static実体
float PlayerParam::MoveSpeed;
float PlayerParam::Gravity;
float PlayerParam::JumpPower;
float PlayerParam::MaxJumpTime;
float PlayerParam::AddJumpPower;

//初回ロード判定
bool PlayerParam::m_loaded = false;

void PlayerParam::Load()
{
	//既に読んでいたら終了
	if (m_loaded)
	{
		return;
	}

	//jsonファイル読み込み
	auto json = JSONManager::Read("data/json/PlayerParam.json");

	//各パラメータに代入
	MoveSpeed = json["Player"]["MoveSpeed"];
	Gravity = json["Player"]["Gravity"];
	JumpPower = json["Player"]["JumpPower"];
	MaxJumpTime = json["Player"]["MaxJumpTime"];
	AddJumpPower = json["Player"]["AddJumpPower"];

	//読み込み済みに
	m_loaded = true;
}
