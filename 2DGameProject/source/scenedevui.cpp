//#include "DxLib.h"
//#include "winmain.h"
//#include "gamemain.h"
//#include "SceneDevUI.h"
//
//
//
//
////
//// UI開発用シーン
////
//
//SceneDevUI::SceneDevUI() {
//	_score = 0;
//	_uiScore.SetScore(_score);
//
//	_pos = 50;
//	_posMin = 0; _posMax = 100;		// 0～100の範囲を表現
//	_uiPosBar.SetRange(_posMin, _posMax);
//	_uiPosBar.Set(_pos);
//
//	_life = 10;
//	_uiLife.Set(_life);
//}
//
//SceneDevUI::~SceneDevUI() {
//}
//
//void SceneDevUI::Input() {
//	// 何もしない
//}
//
//void SceneDevUI::Process() {
//	// [z]ボタンを押したらランダムでスコアに点数追加
//	if (gPad._trg & PAD_INPUT_1) {
//		_score += ((rand() % 900) + 100);	// 100～1000点を
//		_uiScore.SetScore(_score);
//	}
//
//	// [左右]キーでposを変更
//	if (gPad._key & PAD_INPUT_LEFT) { _pos--; }
//	if (gPad._key & PAD_INPUT_RIGHT) { _pos++; }
//	_pos = Clamp(_posMin, _posMax, _pos);
//	// [x]ボタンを押すまでposバーに値をセットしない
//	if (gPad._trg & PAD_INPUT_2) {
//		_uiPosBar.Set(_pos);
//	}
//
//	// [上下]キーでlifeを変更
//	if (gPad._trg & PAD_INPUT_UP) { _life--; }
//	if (gPad._trg & PAD_INPUT_DOWN) { _life++; }
//	_life = Clamp(0, 20, _life);
//	// [c]ボタンを押すまでlifeに値をセットしない
//	if (gPad._trg & PAD_INPUT_3) {
//		_uiLife.Set(_life);
//	}
//
//	// [a]ボタンで各UIの位置を初期位置に
//	if (gPad._trg & PAD_INPUT_4) {
//		_uiScore.SetBasePos(8, 8);
//		_uiPosBar.SetBasePos(100, 150);
//		_uiLife.SetBasePos(50, 300);
//	}
//	// [s]ボタンで各UIの位置を別の位置に
//	if (gPad._trg & PAD_INPUT_5) {
//		_uiScore.SetBasePos(8 + 500, 8);
//		_uiPosBar.SetBasePos(100 + 500, 150);
//		_uiLife.SetBasePos(50 + 500, 300);
//	}
//
//
//
//	// Scene側でUI用のProcess()を呼んでもらう
//	//_uiScore.Process();
//	//_uiPosBar.Process();
//	//_uiLife.Process();
//}
//
//void SceneDevUI::Draw() {
////	DrawFormatString(100, 100, GetColor(255, 255, 255), "SceneDevUI.");
//
//	// Scene側でUI用のDraw()を呼んでもらう
//	//_uiScore.Draw();
//	//_uiPosBar.Draw();
//	//_uiLife.Draw();
//
//
//	// posバーセット開発用
//	//DrawFormatString(100, 135, GetColor(255, 255, 0), "pos: %d", _pos);
//
//	// lifeセット開発用
//	//DrawFormatString(50, 360, GetColor(255, 255, 0), "life: %d", _life);
//
//}
