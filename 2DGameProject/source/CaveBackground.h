//----------------------------------------------------------------------
// @filename CaveBackground.h
// @author: Fukuma Kyohei
// @explanation
// ステージ背景に関するクラス
//----------------------------------------------------------------------
#pragma once
#include <vector>
#include <random>
#include "Vector2D.h"

struct RockCircle
{
    //岩の中心からの相対座標
    Vector2D offset;
    //円の半径
    float radius;
};

struct BackgroundRock
{
    //岩の中心座標
    Vector2D position;
    //岩を構成する円
    std::vector<RockCircle> circles;
};

class CaveBackground
{
public: 
    CaveBackground();
    //生成
    void Generate(int mapWidth, int mapHeight, int tileSize);
    //更新
    void Update();
    //描画
    void Draw();

private:
    int m_worldWidth;
    int m_worldHeight;
    //天井、床の高さ
    std::vector<BackgroundRock> m_rocks;
    //描画シャッフル用の乱数
    std::mt19937 m_rng;

    static constexpr int SEGMENT_WIDTH = 16;
};
