#pragma once	// .hの先頭に記述。#includeでこのファイルを何度読み込みしても、1度しか読み込まない
//----------------------------------------------------------------------
// @filename uibase.h
// @author: Fukuma Kyohei
// @explanation
// uiの描画に使うクラス
//----------------------------------------------------------------------
#include "DxLib.h"
#include "gamemain.h"
#include "mymath.h"

class UIBase {
public:
	UIBase();
	virtual ~UIBase();

	virtual void	Process();
	virtual void	Draw();
};

