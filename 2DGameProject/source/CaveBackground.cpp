#include "CaveBackground.h"
#include <DxLib.h>
#include "mymath.h"
#include "camera.h"

CaveBackground::CaveBackground() :m_worldWidth(0), m_worldHeight(0),m_rng(std::random_device{}())
{
}

void CaveBackground::Generate(int mapWidth, int mapHeight, int tileSize)
{
    //タイル数をピクセル数へ変換
    m_worldWidth = mapWidth * tileSize;
    m_worldHeight = mapHeight * tileSize;

    //データクリア
    m_rocks.clear();

    const int spacing = 180;
    for (int y = -100; y < m_worldHeight + 100; y += spacing)
    {
        for (int x = -100; x < m_worldWidth + 100; x += spacing)
        {
            BackgroundRock rock;

            float random = static_cast<float>(GetRand(80));
            //格子状に配置
            rock.position.x = x + random - 40.0f;
            rock.position.y = y + random - 40.0f;
            //岩の大きさ
            float baseRadius = random + 120.0f;
            //円を何個重ねるか
            int circleCount = GetRand(3) + 5;

            for (int j = 0; j < circleCount; j++)
            {
                RockCircle circle;

                //円の位置を少しだけずらす
                circle.offset.x = GetRand(static_cast<int>(baseRadius)) - baseRadius / 2;
                circle.offset.y = GetRand(static_cast<int>(baseRadius)) - baseRadius / 2;

                //円ごとに半径を変える
                circle.radius = baseRadius * (0.7f + GetRand(30) / 100.0f);

                rock.circles.push_back(circle);
            }

            m_rocks.push_back(rock);
        }
    }
    //コンテナ内順番をランダム化
    std::shuffle(m_rocks.begin(), m_rocks.end(), m_rng);
}

void CaveBackground::Update()
{
}

void CaveBackground::Draw()
{
    //カメラの座標取得
    Vector2D camPos = Vector2D(Camera::w_camera._pos.x, Camera::w_camera._pos.y);

    //洞窟背景描画
    DrawBox(0, 0, m_worldWidth, m_worldHeight, GetColor(8,8,8), TRUE);

    //すべて描画
    for (int i = 0; i < m_rocks.size(); i++)
    {
        const auto& rock = m_rocks[i];
        //岩ごとに少しだけ明るさを変える
        int shade = 1 + (i % 4) * 2;
        int color = GetColor(shade, shade, shade);

        //円を複数重ねて1つの岩を表現
        for (const auto& circle : rock.circles)
        {
            //描画
            DrawCircle(
                static_cast<int>(rock.position.x + circle.offset.x - camPos.x),
                static_cast<int>(rock.position.y + circle.offset.y - camPos.y),
                static_cast<int>(circle.radius),
                color,
                TRUE);
        }
    }
}
