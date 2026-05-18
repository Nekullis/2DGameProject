//----------------------------------------------------------------------
// @filename Vector2D.h
// @author: Fukuma Kyohei
// @explanation
// 2Dでのベクトルを用いた位置、方向に関するクラス
//----------------------------------------------------------------------
#pragma once
#include <cmath>

class Vector2D
{
public:
	//x座標
	float x;
	//y座標
	float y;
	//コンストラクタ
	Vector2D();
	Vector2D(float x, float y);
	//ベクトル加算
	Vector2D operator+(const Vector2D& other)const;
	//ベクトル減算
	Vector2D operator-(const Vector2D& other)const;
	//スカラー倍
	Vector2D operator*(const float value)const;
	//加算代入
	Vector2D operator+=(const Vector2D& other);
	//長さ取得
	float Length()const;
	//正規化
	Vector2D Normalize()const;
	//2点間距離
	static float Distance(const Vector2D& a, const Vector2D& b);
	//内積
	static float Dot(const Vector2D& a, const Vector2D& b);

};

