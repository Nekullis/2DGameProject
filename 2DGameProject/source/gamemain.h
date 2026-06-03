//----------------------------------------------------------------------
// @filename gamemain.h
// @author: Fukuma Kyohei
// @explanation
// ゲーム全体の処理、フェードインアウトを行うクラス
//----------------------------------------------------------------------

// gamemain.cpp に実体を記述
#pragma once	
#include "scene.h"

// カラーマスクの指定
void ColorMask(int colorR, int colorG, int colorB, int colorA);		

// 指定の色にフェードアウト（カラーマスク使用, alpha=255にする）
void ColorFadeOut(int colorR, int colorG, int colorB, int frames);

// 現在のカラーマスクからフェードイン（カラーマスク使用, alpha=0にする）
void ColorFadeIn(int frames);

// フェードインアウトは終了したか？
// 戻り値: 1 = フェード中, 0 = フェード終了(もしくは開始前)
int IsColorFade();

// gamemain.cpp に実体を記述
void GameMain();	




