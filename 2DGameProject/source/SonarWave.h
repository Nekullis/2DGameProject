//----------------------------------------------------------------------
// @filename SonarWave.h
// @author: Fukuma Kyohei
// @explanation
// ソナーのデータ構造体クラス
//----------------------------------------------------------------------
#pragma once
#include "Vector2D.h"

class SonarWave
{
public:
    SonarWave();

    void Start(const Vector2D& pos, float landingSpeed);
    void Update();
    void Draw()const;

    bool IsActive()const { return m_active; }

    //ゲッター
    Vector2D GetPos() { return m_position; }

private:
    //位置
    Vector2D m_position;
    //半径
    float m_radius;
    //最大範囲
    float m_maxRadius;
    //到達速度
    float m_speed;
    //α値
    float m_alpha;
    bool m_active;
};

