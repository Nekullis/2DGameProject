//----------------------------------------------------------------------
// @filename UIItem.h
// @author: Fukuma Kyohei
// @explanation
// ƒAƒCƒeƒ€Œn‚ÌUI‚ğ•`‰æ‚·‚éÛ‚É‚Â‚©‚¤ŠÖ”
//----------------------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "gamemain.h"
#include "mymath.h"
#include "UIBase.h"

class UIItem : public UIBase {
public:
	UIItem();
	virtual ~UIItem();
	void	Draw(int cgKey, int cgKnife);

private:
	int cgKey;
	int cgKnife;
};
