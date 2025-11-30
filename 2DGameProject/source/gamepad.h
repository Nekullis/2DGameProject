//----------------------------------------------------------------------
// @filename gamepad.h
// @author: Fukuma Kyohei
// @explanation
// ゲームパッドクラス
//----------------------------------------------------------------------

#pragma once	

class GamePad {
public:
	GamePad();			// コンストラクタ
	virtual ~GamePad();	// デストラクタ

	virtual void Input();		// 入力更新

public:
	// キーボード＆ゲームパッド1のどちらでも使える場合
	int _key;			// キー入力の情報
	int _trg;			// トリガ入力の情報
	int _rel;			// リリース入力の情報

	// 複数ゲームパッド用の場合
	struct MULTIPAD {
		int _key;			// キー入力の情報
		int _trg;			// トリガ入力の情報
		int _rel;			// リリース入力の情報
	};
#define	MUTIPAD_MAX		(17)	// 最大で、パッド16個＋キーボードの17個
	MULTIPAD	_m[MUTIPAD_MAX];

};


