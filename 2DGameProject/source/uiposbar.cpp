//#include "UIPosBar.h"
//
//
//// UIbarクラス
//UIPosBar::UIPosBar() {
//	_cgBarBase = LoadGraph("res/uibar_base.png");
//	_cgBarR = LoadGraph("res/uibar_bar_R.png");
//	_cgBarG = LoadGraph("res/uibar_bar_G.png");
//	_cgBarB = LoadGraph("res/uibar_bar_B.png");
//	_cgBarW = LoadGraph("res/uibar_bar_W.png");
//	_cgBarEdge = LoadGraph("res/uibar_bar_edge.png");
//	SetColor(255, 0, 0);
//
//	// テスト用初期値
//	_rangeMin = 0;
//	_rangeMax = 100;
//	_data = 50;
//
//	_drawData = _data;
//	_easingStartData = 0;
//	_easingMax = 30;			// easing最大値
//	_easingCnt = _easingMax;	// easingカウンタ
//
//	SetBasePos(100, 150);
//}
//UIPosBar::~UIPosBar() {
//	DeleteGraph(_cgBarBase);
//	DeleteGraph(_cgBarR);
//	DeleteGraph(_cgBarG);
//	DeleteGraph(_cgBarB);
//	DeleteGraph(_cgBarW);
//	DeleteGraph(_cgBarEdge);
//}
//
//void	UIPosBar::SetRange(float rangeMin, float rangeMax) {
//	_rangeMin = rangeMin;
//	_rangeMax = rangeMax;
//}
//
//void	UIPosBar::Set(float data) {
//	if (_easingCnt == _easingMax) {
//		// easingがすでに終わっていたので、今のdataが表示開始data
//		_easingStartData = _data;
//	}
//	else {
//		// easingが途中のタイミングでdataが更新されたので、今表示されているdataが開始時data
//		_easingStartData = _drawData;
//	}
//	_easingCnt = 0;				// easingカウンタ
//	_data = data;
//}
//
//void	UIPosBar::SetColor(int r, int g, int b) {
//	_colorR = r;
//	_colorG = g;
//	_colorB = b;
//}
//
//
//// 毎フレーム呼ばれる前提
//void	UIPosBar::Process() {
//	UIBase::Process();
//	if (_easingCnt < _easingMax) {
//		// easing処理中。カウンタを進めて、数値を近づける
//		_easingCnt++;
//		//_drawData = EasingLinear(_easingCnt, _easingStartData, _data, _easingMax);		// easing関数は好きなモノを使える
//		_drawData = EasingOutQuad(_easingCnt, _easingStartData, _data, _easingMax);		// easing関数は好きなモノを使える
//	}
//}
//
//
//void	UIPosBar::DrawBar(int x, int y, int bar_w, int bar_h, int colorR, int colorG, int colorB, int drawEdge) {
//	// 一度バーの位置を黒で塗りつぶす
//	DrawFillBox(x, y, x + bar_w, y + bar_h, GetColor(0, 0, 0));
//	// 色を、RGB3色を割合計算して重ねて描画
//	SetDrawBlendMode(DX_BLENDMODE_ADD, colorR);
//	DrawExtendGraph(x, y, x + bar_w, y + bar_h, _cgBarR, TRUE);
//	SetDrawBlendMode(DX_BLENDMODE_ADD, colorG);
//	DrawExtendGraph(x, y, x + bar_w, y + bar_h, _cgBarG, TRUE);
//	SetDrawBlendMode(DX_BLENDMODE_ADD, colorB);
//	DrawExtendGraph(x, y, x + bar_w, y + bar_h, _cgBarB, TRUE);
//
//	if (drawEdge != 0) {
//		SetDrawBlendMode(DX_BLENDMODE_ADD, 192);
//		DrawGraph(x + bar_w - 1, y - 6, _cgBarEdge, TRUE);
//	}
//
//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
//}
//
//// 描画
//void	UIPosBar::Draw() {
//	UIBase::Draw();
//	int base_x = _base_x, base_y = _base_y;
//
//	DrawGraph(base_x + 0, base_y + 0, _cgBarBase, TRUE);
//
//	// 画像内のバー部分情報
//	int bar_x = 23, bar_y = 9, bar_max_w = 462, bar_h = 12;
//
//	// バーを拡大を使って描画
//	int x, y;
//	x = base_x + bar_x;
//	y = base_y + bar_y;
//	// バーの動きが減って行くときと、増えていく時で動作を変える
//	if (_easingStartData > _data) {
//		// バーが減って行く。元の長さを白で表示して動かし、実際の長さを実体色で表示
//
//		// バーの長さを計算
//		// rangeMin～rangeMaxの中で、表示する値dataは、バーの画像幅bar_wの中でどの位置になるか
//		float n = Clamp(_rangeMin, _rangeMax, _drawData);	// 範囲幅を超えないようにClamp
//		int bar_w = EasingLinear(n - _rangeMin, 0, bar_max_w, _rangeMax - _rangeMin);		// linearなら等間隔表現になる
//
//		// 最小/最大値でなければ光を出す
//		int drawEdge = 0;
//		if (_rangeMin < n && n < _rangeMax) { drawEdge = 1; }
//		DrawBar(x, y, bar_w, bar_h, 255, 255, 255, drawEdge);		// 白
//
//		// 実体の長さのバー
//		n = Clamp(_rangeMin, _rangeMax, _data);	// 範囲幅を超えないようにClamp
//		bar_w = EasingLinear(n - _rangeMin, 0, bar_max_w, _rangeMax - _rangeMin);		// linearなら等間隔表現になる
//		DrawBar(x, y, bar_w, bar_h, _colorR, _colorG, _colorB, 0);
//	}
//	else {
//		// バーが増えていく。実際の長さを白で表示し、増えていくバーを実体色で動かす
//
//		// バーの長さを計算
//		// rangeMin～rangeMaxの中で、表示する値dataは、バーの画像幅bar_wの中でどの位置になるか
//		float n = Clamp(_rangeMin, _rangeMax, _data);	// 範囲幅を超えないようにClamp
//		int bar_w = EasingLinear(n - _rangeMin, 0, bar_max_w, _rangeMax - _rangeMin);		// linearなら等間隔表現になる
//		DrawBar(x, y, bar_w, bar_h, 255, 255, 255, 0);		// 白
//
//		// 増えていくバー
//		n = Clamp(_rangeMin, _rangeMax, _drawData);	// 範囲幅を超えないようにClamp
//		bar_w = EasingLinear(n - _rangeMin, 0, bar_max_w, _rangeMax - _rangeMin);		// linearなら等間隔表現になる
//		// 最小/最大値でなければ光を出す
//		int drawEdge = 0;
//		if (_rangeMin < n && n < _rangeMax) { drawEdge = 1; }
//		DrawBar(x, y, bar_w, bar_h, _colorR, _colorG, _colorB, drawEdge);
//	}
//
//
//	
//}

