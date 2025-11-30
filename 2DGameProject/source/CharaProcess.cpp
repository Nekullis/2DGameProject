#include"s_gamemain.h"
#include "framedata.h"


// キャラの地形/キャラ当たり判定を取り出す
MYRECT SceneGameMain::GetHitRectFromChara(int charaIndex) const 
{
	MYRECT rc = { 0, 0, 0, 0 };

	if (_gChara[charaIndex].type != CHARA_TYPE_NONE) 
	{	//　rcの配列内に代入
		rc.w = _gChara[charaIndex].hw;
		rc.h = _gChara[charaIndex].hh;
		rc.x = _gChara[charaIndex].x + _gChara[charaIndex].hx;
		rc.y = _gChara[charaIndex].y + _gChara[charaIndex].hy;
	}

	return rc;
}

// フレームIDと、hitrectIndexから、左右反転に応じた当たり判定RECTを得る
// (cx,cy)は基点座標
MYRECT SceneGameMain::GetHitRectFromFrame(int frameId, int hitrectIndex, int cx, int cy, int mirror_lr) {
	MYRECT rc = { 0, 0, 0, 0 };
	int type = tblFrame[frameId].hit[hitrectIndex].type;
	if (type != CHARA_HITRECT_TYPE_NONE) {
		// 矩形の大きさ
		int x, y, w, h;
		w = tblFrame[frameId].hit[hitrectIndex].hw;
		h = tblFrame[frameId].hit[hitrectIndex].hh;

		// 左右反転するか？
		if (mirror_lr == 0) {
			// しない
			// 描画位置は、基点分ずらした場所
			x = cx - tblFrame[frameId].cx;
			y = cy - tblFrame[frameId].cy;
			// (x,y)は描画する左上位置。矩形分ずらす
			x = x + tblFrame[frameId].hit[hitrectIndex].hx;
			y = y + tblFrame[frameId].hit[hitrectIndex].hy;

		}
		else {
			// する
			// 描画位置は、左右反転してから基点分ずらした場所
			x = cx - (tblFrame[frameId].w - tblFrame[frameId].cx);
			y = cy - tblFrame[frameId].cy;
			// (x,y)は描画する左上位置。矩形分ずらす
			x = x + (tblFrame[frameId].w - tblFrame[frameId].hit[hitrectIndex].hx) - w;
			y = y + tblFrame[frameId].hit[hitrectIndex].hy;
		}

		rc.x = x;
		rc.y = y;
		rc.w = w;
		rc.h = h;
	}

	return rc;
}
//グループ判定
int SceneGameMain::IsCheckCharaExistCollision(int i, int j) const {
	// 物理判定 
	if ((_gChara[i].group == CHARA_GROUP_ENEMY && _gChara[j].group == CHARA_GROUP_PLAYER)
		|| (_gChara[i].group == CHARA_GROUP_PLAYER && _gChara[j].group == CHARA_GROUP_ENEMY)
		|| (_gChara[i].group == CHARA_GROUP_PLAYER && _gChara[j].type == CHARA_TYPE_GIMMICK_EVENT_HITRECT)
		|| (_gChara[i].type == CHARA_TYPE_GIMMICK_EVENT_HITRECT && _gChara[i].group == CHARA_GROUP_PLAYER)
		|| (_gChara[i].group == CHARA_GROUP_ENEMY && _gChara[j].type == CHARA_TYPE_GIMMICK_EVENT_HITRECT)
		|| (_gChara[i].type == CHARA_TYPE_GIMMICK_EVENT_HITRECT && _gChara[j].group == CHARA_GROUP_ENEMY)
		|| (_gChara[i].type == CHARA_TYPE_GIMMICK_EVENT_HITRECT && _gChara[j].group == CHARA_GROUP_PLAYER_EFFECT)
		|| (_gChara[i].group == CHARA_GROUP_PLAYER_EFFECT && _gChara[j].type == CHARA_TYPE_GIMMICK_EVENT_HITRECT)
		|| (_gChara[i].group == CHARA_GROUP_ENEMY && _gChara[j].group == CHARA_GROUP_PLAYER_EFFECT)
		|| (_gChara[i].group == CHARA_GROUP_PLAYER_EFFECT && _gChara[j].group == CHARA_GROUP_ENEMY))

	{	//下のキャラモーションは物理判定にならない
		if ((_gChara[i].motId == MOTION_ENEMY4_L_STAN || _gChara[i].motId == MOTION_ENEMY4_R_STAN)
			|| (_gChara[j].motId == MOTION_ENEMY4_L_STAN || _gChara[j].motId == MOTION_ENEMY4_R_STAN)
			|| (_gChara[j].motId == MOTION_ENEMY4_STAIR_DOWN_BACK || _gChara[j].motId == MOTION_ENEMY4_STAIR_UP_BACK)
			|| (_gChara[j].motId == MOTION_ENEMY4_STAIR_DOWN_FRONT || _gChara[j].motId == MOTION_ENEMY4_STAIR_UP_FRONT)
			|| (_gChara[j].motId == MOTION_STAIR_DOWN_BACK || _gChara[j].motId == MOTION_STAIR_UP_BACK)
			|| (_gChara[j].motId == MOTION_STAIR_DOWN_FRONT || _gChara[j].motId == MOTION_STAIR_UP_FRONT)
			|| (_gChara[i].group == CHARA_GROUP_PLAYER && _gChara[j].motId == MOTION_GIMMICK_EVENT_OPEN_HITRECT)
			|| (_gChara[i].motId == MOTION_GIMMICK_EVENT_OPEN_HITRECT && _gChara[j].group == CHARA_GROUP_PLAYER))
		{
			return 0;
		}
		else
		{
			// 判定する
			return 1;
		}
	}
	// 判定しない
	return 0;
}
int SceneGameMain::IsCheckCharaLogicCollision(int i, int j) const
{
	//論理判定
	if ((_gChara[i].group == CHARA_GROUP_ENEMY && _gChara[j].group == CHARA_GROUP_PLAYER)
		|| (_gChara[i].group == CHARA_GROUP_ENEMY && _gChara[j].group == CHARA_GROUP_PLAYER_EFFECT)
		|| (_gChara[i].group == CHARA_GROUP_PLAYER_EFFECT && _gChara[j].group == CHARA_GROUP_ENEMY)
		|| (_gChara[i].group == CHARA_GROUP_PLAYER && _gChara[j].group == CHARA_GROUP_PLAYER_EFFECT)
		|| (_gChara[i].group == CHARA_GROUP_PLAYER && _gChara[j].group == CHARA_GROUP_ENEMY)
		|| (_gChara[i].group == CHARA_GROUP_ITEM && _gChara[j].group == CHARA_GROUP_PLAYER)
		|| (_gChara[i].group == CHARA_GROUP_ITEM && _gChara[j].group == CHARA_GROUP_ENEMY)
		|| (_gChara[i].group == CHARA_GROUP_GIMMICK && _gChara[j].group == CHARA_GROUP_PLAYER)
		|| (_gChara[i].group == CHARA_GROUP_GIMMICK && _gChara[j].group == CHARA_GROUP_ENEMY))
	{
		// 判定する
		return 1;
	}
	// 判定しない
	return 0;
}

// キャラが移動可能か、当たり判定
// mx, my はキャラの移動方向
// 当たり判定でヒットしたら1を、していなければ0を返す
int SceneGameMain::CheckCharaMove(int charaIndex, int mx, int my) {

	int hit = 0;
	int i = charaIndex;		// [i] を自キャラとする

	// マップチップとの当たり判定
	MapData::HITSLIDE hitSlide;
	MYRECT rc = GetHitRectFromChara(i);
	if (_gChara[i].motId == MOTION_STAIR_DOWN_BACK || _gChara[i].motId == MOTION_STAIR_DOWN_FRONT || _gChara[i].motId == MOTION_STAIR_UP_BACK || _gChara[i].motId == MOTION_STAIR_UP_FRONT
		|| _gChara[i].motId == MOTION_ENEMY4_STAIR_DOWN_BACK || _gChara[i].motId == MOTION_ENEMY4_STAIR_DOWN_FRONT || _gChara[i].motId == MOTION_ENEMY4_STAIR_UP_BACK || _gChara[i].motId == MOTION_ENEMY4_STAIR_UP_FRONT
		|| _gChara[i].motId == MOTION_START_STAIR_DOUN)
	{
		//これらのモーションはマップチップをすりぬける
		hit = 0;
	}
	else
	{
		hitSlide = _mapData.IsHitBox(rc.x, rc.y, rc.w, rc.h, mx, my);
		if (hitSlide.hit != 0)
		{
			// 当たったので、位置を動かす
			_gChara[i].x += hitSlide.slide_x;
			_gChara[i].y += hitSlide.slide_y;
			hit = 1;
		}
	}

	// 別キャラとの当たり判定を行う
	int j;					// [j] を別キャラとする

	// 自分が別のキャラと重なっているか？（重なっていたら押し出される）
	for (j = 0; j < CHARA_MAX; j++) {
		// 自キャラじゃない、かつキャラタイプがある
		if (i != j && _gChara[j].type != CHARA_TYPE_NONE) {
			// [i]と[j]で当たり判定

			// グループの組み合わせで、判定する組み合わせ以外はcontinue
			if (IsCheckCharaExistCollision(i, j) == 0) {
				continue;
			}

			MYRECT rc_i = GetHitRectFromChara(i);
			MYRECT rc_j = GetHitRectFromChara(j);

			// RECTの当たり判定
			if (IsHitBox(rc_i.x, rc_i.y, rc_i.w, rc_i.h, rc_j.x, rc_j.y, rc_j.w, rc_j.h) == 1)
			{
				// 当たった。移動方向に合わせて、キャラ[i]位置を調整
				if (mx < 0) {
					// 左に移動しようとしていた。右に位置調整
					_gChara[i].x = rc_j.x + rc_j.w - _gChara[i].hx;
				}
				if (mx > 0) {
					// 右に移動しようとしていた。左に位置調整
					_gChara[i].x = rc_j.x - (_gChara[i].hw + _gChara[i].hx);
				}

				if (my < 0) {
					// 上に移動しようとしていた。下に位置調整
					_gChara[i].y = rc_j.y + rc_j.h - _gChara[i].hy;
				}
				if (my > 0) {
					// 下に移動しようとしていた。上に位置調整
					_gChara[i].y = rc_j.y - (_gChara[i].hh + _gChara[i].hy);
				}
				hit = 1;
			}
		}
	}
	return hit;
}

// tblFrame[] の配列番号を、frameIdで調べる
int SceneGameMain::SearchFrame(int frameId) {
	int n = 0;
	while (tblFrame[n].frameId != -1) {
		if (tblFrame[n].frameId == frameId) {
			// 見つかった。[n]が配列番号
			return n;
		}
		n++;
	}
	// 見つからなかった（本来来てはいけない）
	return -1;
}

// キャラのモーション変更指示
void SceneGameMain::CharaChangeMotion(int charaIndex, int motion) {
	if (_gChara[charaIndex].motId != motion)
	{
		_gChara[charaIndex].motId = motion;
		_gChara[charaIndex].motcnt = 0;
		_gChara[charaIndex].animcnt = 0;
	}
}

void SceneGameMain::ProcessCharacter() {

	int i;
	int EnemyKnifeCnt = 0;
	for (i = 0; i < CHARA_MAX; i++) {

		if (_gChara[i].type != CHARA_TYPE_NONE) 
		{
			//
			// 共通処理（前）
			//
			int motChg = -1;		// モーションを変更する場合、ここに指定する

			// リスポーンフラグがセットされていたら、位置を変更
			if (_gChara[i].respawn == 1) {
				_gChara[i].respawn = 0;
				_gChara[i].x = _gChara[i].respawn_x;
				_gChara[i].y = _gChara[i].respawn_y;
			}

			// 重力処理
			if (_gChara[i].useGravity != 0)
			{
				_gChara[i].gravity += 1;			// キャラの、重力による加速値を大きくする
				_gChara[i].y += _gChara[i].gravity;	// 重力による加速値の分だけ移動する
			}
			_gChara[i].stand = 0;			// 床に当たってないことを前提に、床フラグリセット

			// 上下の当たり判定
			if (CheckCharaMove(i, 0, _gChara[i].gravity) != 0) 
			{
				// 当たった。当たったのは床か？（重力値はプラスだったか？）
				if (_gChara[i].gravity > 0)
				{
					_gChara[i].stand = 1;	// 床に当たったのでフラグセット
				}
				_gChara[i].gravity = 0;		// 重力による加速値をリセット
			}


			//
			// タイプ別個別処理
			//

			switch (_gChara[i].group) 
			{
			case CHARA_GROUP_PLAYER:
			{	// プレイヤー
				motChg = CharaProcessPlayer(i);
				break;
			}
			case CHARA_GROUP_PLAYER_EFFECT:
			{	// プレイヤーエフェクト
				motChg = CharaProcessPlayerEffect(i);
				break;
			}
			case CHARA_GROUP_ENEMY:
			{	// 敵
				motChg = CharaProcessEnemys(i);
				break;
			}
			case CHARA_GROUP_ITEM:
			{	// アイテム
				motChg = CharaProcessItems(i);
				break;
			}
			case CHARA_GROUP_GIMMICK:
			{	//ギミック
				motChg = CharaProcessGimmick(i);
				break;
			}
			}

			// 当たり判定
			int j;
			// 自分がダメージを受けるかの判定を行う
			for (j = 0; j < CHARA_MAX; j++) 
			{
				// 自キャラじゃない、かつキャラタイプがある
				if (i != j && _gChara[j].type != CHARA_TYPE_NONE) 
				{
					// [i]と[j]で当たり判定
					// [i]（自分）の持つダメージ判定と、[j]（相手）の持つ攻撃判定との当たり判定。
					// グループの組み合わせで、判定する組み合わせ以外はcontinue
					if (IsCheckCharaLogicCollision(i, j) == 0) {
						continue;
					}

					int ii, jj;
					for (ii = 0; ii < CHARA_HITRECT_NUM; ii++) {
						int frameId_i = SearchFrame(tblMotion[_gChara[i].motId].item[_gChara[i].motcnt].frameId);
						for (jj = 0; jj < CHARA_HITRECT_NUM; jj++) {
							int frameId_j = SearchFrame(tblMotion[_gChara[j].motId].item[_gChara[j].motcnt].frameId);
							// 当たり判定の種類別に、判定するか、取り出す矩形をどうするかを変える
							int checkHit = 0;	// 0以外なら判定する
							MYRECT rc_i, rc_j;	// 判定する2つの矩形
							if (tblFrame[frameId_i].hit[ii].type == CHARA_HITRECT_TYPE_DAMAGE
								&& tblFrame[frameId_j].hit[jj].type == CHARA_HITRECT_TYPE_ATTACK)
							{	
								// [i]のダメージ判定, [j]の攻撃判定が見つかった
								// 二つの当たり判定矩形を取り出す
								rc_i = GetHitRectFromFrame(frameId_i, ii, _gChara[i].x, _gChara[i].y, tblMotion[_gChara[i].motId].mirror_lr);
								rc_j = GetHitRectFromFrame(frameId_j, jj, _gChara[j].x, _gChara[j].y, tblMotion[_gChara[j].motId].mirror_lr);
								checkHit = 1;	// 1:攻撃とダメージの判定
							}
							else if (tblFrame[frameId_i].hit[ii].type == CHARA_HITRECT_TYPE_GET)
							{	// [i]の取得判定が見つかった
								// [j]はプレイヤーか？
								if (_gChara[j].type == CHARA_TYPE_PLAYER1
									|| _gChara[j].type == CHARA_TYPE_ENEMY_4)

								{	// プレイヤー
									// 二つの当たり判定矩形を取り出す
									rc_i = GetHitRectFromFrame(frameId_i, ii, _gChara[i].x, _gChara[i].y, tblMotion[_gChara[i].motId].mirror_lr);
									rc_j = GetHitRectFromChara(j);
									checkHit = 2;	// 2:実体と取得の判定
								}
							}
							else if (tblFrame[frameId_i].hit[ii].type == CHARA_HITRECT_TYPE_SEARCH)
							{	//敵の索敵範囲に入った際の敵の状態の変化
								if (_gChara[i].group == CHARA_GROUP_ENEMY && _gChara[j].type == CHARA_TYPE_PLAYER1)
								{
									rc_i = GetHitRectFromFrame(frameId_i, ii, _gChara[i].x, _gChara[i].y, tblMotion[_gChara[i].motId].mirror_lr);
									rc_j = GetHitRectFromChara(j);
									checkHit = 3;
								}
							}
							else if (tblFrame[frameId_i].hit[ii].type == CHARA_HITRECT_TYPE_GIMMICK)
							{	//ギミックに触れた時にギミックが発動できるように
								if (_gChara[i].group == CHARA_GROUP_GIMMICK && _gChara[j].type == CHARA_TYPE_PLAYER1)
								{
									rc_i = GetHitRectFromFrame(frameId_i, ii, _gChara[i].x, _gChara[i].y, tblMotion[_gChara[i].motId].mirror_lr);
									rc_j = GetHitRectFromChara(j);
									checkHit = 4;
								}
							}
							else if (tblFrame[frameId_i].hit[ii].type == CHARA_HITRECT_TYPE_ESCAPE && tblFrame[frameId_j].hit[jj].type == CHARA_HITRECT_TYPE_DAMAGE)
							{	//敵の索敵範囲に入った際の敵の状態の変化
								if (_gChara[i].type == CHARA_TYPE_PLAYER1 && _gChara[j].group == CHARA_GROUP_ENEMY)
								{
									rc_i = GetHitRectFromFrame(frameId_i, ii, _gChara[i].x, _gChara[i].y, tblMotion[_gChara[i].motId].mirror_lr);
									rc_j = GetHitRectFromFrame(frameId_j, jj, _gChara[j].x, _gChara[j].y, tblMotion[_gChara[j].motId].mirror_lr);
									checkHit = 5;
								}
							}
							else if (tblFrame[frameId_i].hit[ii].type == CHARA_HITRECT_TYPE_THROWRANGE)
							{	//ボスのナイフを投げる入った
								if (_gChara[i].type == CHARA_TYPE_ENEMY_4 && _gChara[j].type == CHARA_TYPE_PLAYER1)
								{
									rc_i = GetHitRectFromFrame(frameId_i, ii, _gChara[i].x, _gChara[i].y, tblMotion[_gChara[i].motId].mirror_lr);
									rc_j = GetHitRectFromChara(j);
									checkHit = 6;
								}
							}
							else if (tblFrame[frameId_i].hit[ii].type == CHARA_HITRECT_TYPE_UNDISCOVER)
							{	//ボスにみつかった
								if (_gChara[i].type == CHARA_TYPE_ENEMY_4 && _gChara[j].type == CHARA_TYPE_PLAYER1)
								{

									rc_i = GetHitRectFromFrame(frameId_i, ii, _gChara[i].x, _gChara[i].y, tblMotion[_gChara[i].motId].mirror_lr);
									rc_j = GetHitRectFromChara(j);
									checkHit = 7;
								}
							}

							else
							{
								checkHit = 0;
							}

							if (checkHit != 0) {
								// RECTの当たり判定
								if (IsHitBox(rc_i.x, rc_i.y, rc_i.w, rc_i.h, rc_j.x, rc_j.y, rc_j.w, rc_j.h) == 1)
								{
									// 当たった。どの処理種類か？
									if (checkHit == 1) {
										// i = 攻撃, j = ダメージ
										// 自分はダメージを食らう
										// ダメージの方向は、相手のX座標から判断
										if (_gChara[i].x > _gChara[j].x)
										{
											// 相手が左側に居るので、自分も左側を向く
											_gChara[i].arrow = -1;
										}
										else
										{
											// 相手が右側に居るので、自分も右側を向く
											_gChara[i].arrow = 1;
										}

										switch (_gChara[i].group) {
										case CHARA_GROUP_PLAYER:
											motChg = CharaDamagePlayer(i, j);
											break;
										case CHARA_GROUP_PLAYER_EFFECT:
											motChg = CharaDamagePlayerEffect(i, j);
											break;
										case CHARA_GROUP_ENEMY:
											motChg = CharaDamageEnemys(i, j);
											break;
										}
									}
									else if (checkHit == 2)
									{
										// i = 取られる自分, j = プレイヤー
										motChg = CharaDamageItems(i, j);
									}
									else if (checkHit == 3)
									{
										//敵が攻撃モーションに入った
										motChg = CharaSearchEnemys(i);

										if (_gChara[i].type == CHARA_TYPE_ENEMY_1)
										{	//マグロの場合、一緒に魚群が出るように
											if (_StageNo == 1)
											{
												if (SceneEv < 5)
												{
													AddChara(CHARA_TYPE_ENEMY_5, _gChara[i].x, _gChara[i].y, _gChara[i].arrow, 0);
												}
											}
											else
											{
												AddChara(CHARA_TYPE_ENEMY_5, _gChara[i].x, _gChara[i].y, _gChara[i].arrow, 0);
											}
											
										}
									}
									else if (checkHit == 4)
									{	//ギミックのモーション変化
										motChg = CharaChangeGimmick(i, j);
									}
									else if (checkHit == 5)
									{	//プレイヤーのモーション変化
										PlayerEscape = 1;
									}
									else if (checkHit == 6)
									{	
										//ボスが投擲モーションになる準備								
										motChg = EnemyThrowKnife(i, j);
									}
									else if (checkHit == 7)
									{	
										//ボスに見つかった										
										motChg = CharaRunEnemy(i, j);
									}
								}
								//コリジョンとの当たり判定外にでた
								else
								{	
									if (checkHit == 4)
									{	//ギミックから離れたときの状態の変更
										SentenceNo = 0;
										motChg = CharaChangeOpen(i, j);
									}

									else if (checkHit == 5)
									{	
										//プレイヤーのモーション変化
										PlayerEscape = 0;
									}

									else if (checkHit == 6)
									{	
										//投擲準備をやめる								
										EnemyKnifeCnt = 0;
									}
								}
							}
						}
					}
				}
			}

			// モーションは変更されないか？
			if (motChg == -1 || motChg == _gChara[i].motId) {
				// モーション分移動
				// mx,myに移動値を得る
				int mx, my;
				mx = tblMotion[_gChara[i].motId].item[_gChara[i].motcnt].mx;
				my = tblMotion[_gChara[i].motId].item[_gChara[i].motcnt].my;

				// 移動してみる
				_gChara[i].x += mx;
				_gChara[i].y += my;

				// 移動可能か？当たり判定。移動不可なら中で位置調整
				CheckCharaMove(i, mx, my);

				// 今のモーションのままなので、カウンタを進める
				_gChara[i].animcnt++;

				// モーションの今のフレームは終了したか？
				if (_GameOver != 1)
				{
					if (tblMotion[_gChara[i].motId].item[_gChara[i].motcnt].frameCnt <= _gChara[i].animcnt) {
						// 次のフレームへ
						_gChara[i].motcnt++;
						_gChara[i].animcnt = 0;

						// 次のフレームはコマンドか？
						// コマンドが複数連続で処理できるように、ループをさせておく
						int loop = 1;
						while (loop == 1) {
							// コマンド分岐
							switch (tblMotion[_gChara[i].motId].item[_gChara[i].motcnt].frameId) {
							case CHARA_MOTION_CMD_LOOP:
							{	// モーションをループする(frameCntにモーションindex指定)
								int motionIndex = tblMotion[_gChara[i].motId].item[_gChara[i].motcnt].frameCnt;
								_gChara[i].motcnt = motionIndex;
								break;
							}
							case CHARA_MOTION_CMD_MOTION:
							{	// 別のモーションへ(frameCntはモーションID)
								int motionId = tblMotion[_gChara[i].motId].item[_gChara[i].motcnt].frameCnt;
								CharaChangeMotion(i, motionId);
								loop = 0;	// ループ終了
								break;
							}
							case CHARA_MOTION_CMD_PLAYSE:
							{	// 効果音再生(frameCntにSE_xxxx)
								int seId = tblMotion[_gChara[i].motId].item[_gChara[i].motcnt].frameCnt;
								PlaySoundMem(_se[seId], DX_PLAYTYPE_BACK, TRUE);
								_gChara[i].motcnt++;
								break;
							}
							case CHARA_MOTION_CMD_HPCHECK:
							{	// HPをチェックし0以下なら死亡
								if (_gChara[i].hp <= 0)
								{
									switch (_gChara[i].type)
									{
									case CHARA_TYPE_PLAYER1:
										//プレイヤー死亡モーションに
										if (_gChara[i].arrow < 0)
										{
											motChg = MOTION_L_DEATH;
										}
										else
										{
											motChg = MOTION_R_DEATH;
										}

										break;
									case CHARA_TYPE_ENEMY_2:
										//ステージ、イベントフラグによって変更
										switch (_StageNo)
										{
										case 1:
											DeleteChara(i);
											break;
										case 2:
											if (SceneEv == 8)
											{
												motChg = MOTION_CHANGE_ZOMBIE;
											}
											else
											{
												DeleteChara(i);
											}
											break;
										}
										break;
									case CHARA_TYPE_ENEMY_3:
										DeleteChara(i);
										break;
									}
								}
								_gChara[i].motcnt++;
								break;
							}
							case CHARA_MOTION_CMD_FIRE:
							{	//ナイフを投げる
								AddChara(CHARA_TYPE_PLEFFECT_KNIFE, _gChara[i].x + _gChara[i].arrow * 200, _gChara[i].y - 400, _gChara[i].arrow, 0);
								_gChara[i].motcnt++;
								break;
							}
							case CHARA_MOTION_CMD_LAYER:
							{	//描画順を変更
								if (_gChara[i].layer == 1)
								{
									_gChara[i].layer = 4;
								}
								else
								{
									_gChara[i].layer = 1;
								}
								_gChara[i].motcnt++;
								break;
							}
							case CHARA_MOTION_CMD_END:
							{	
								//ゲームオーバーフラグを1に
								_GameOver = 1;
								loop = 0;
								break;
							}
							case CHARA_MOTION_CMD_GRAVITY:
							{	
								//重力をつかるかどうか
								_gChara[i].useGravity = 1;
								_gChara[i].motcnt++;
								break;
							}

							case CHARA_MOTION_CMD_CHANGE:
							{	
								//新しくキャラを出す
								AddChara(CHARA_TYPE_ENEMY_3, 2500, 1000, -1, 0);
								DeleteChara(i);
								break;
							}
							default:
							{	
								// コマンドじゃなかったのでループ終了
								loop = 0;
							}
							}
						}
					}
				}
				else
				{
					int motionIndex = tblMotion[_gChara[i].motId].item[_gChara[i].motcnt].frameCnt;
					_gChara[i].motcnt = motionIndex;
				}
			}

			// モーションは変更されるか？
			if (motChg != -1 && motChg != _gChara[i].motId) {
				// 今と別のモーションに変更
				CharaChangeMotion(i, motChg);
			}
		}
	}
}