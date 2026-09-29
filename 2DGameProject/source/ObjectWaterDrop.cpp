#include "ObjectWaterDrop.h"
#include "Time.h"
#include "TileMap.h"
#include "Physics.h"

ObjectWaterDrop::ObjectWaterDrop(float x, float y, TileMap* tileMap) : m_tileMap(tileMap)
{
    m_objType = ObjectType::Gimmick;

    //初期位置設定
    SetPosition(Vector2D(x, y));
    //落下速度
    m_velocity = Vector2D(0.0f, 300.0f);

    //水滴の当たり判定
    m_collider.SetType(ColliderType::Circle);
    m_collider.SetRadius(5.0f);
    m_collider.SetLayer(CollisionLayer::Gimmick);
}

ObjectWaterDrop::~ObjectWaterDrop()
{
}

void ObjectWaterDrop::Update()
{
    //位置更新、Collider位置更新
    GameObject::Update();

    //TileMapが設定されていなければなにもしない
    if (m_tileMap == nullptr)
    {
        return;
    }

    //水滴の矩形生成
    MYRECT dropRect{};
    dropRect.x = static_cast<int>(m_position.x - 5.0f);
    dropRect.y = static_cast<int>(m_position.y - 5.0f);
    dropRect.w = 10;
    dropRect.h = 10;
    
    //マップ上の壁を取得
    std::vector<MYRECT> walls = m_tileMap->GetWallRects();

    //すべての壁と判定
    for (const auto& wall : walls)
    {
        CollisionSide hit = Physics::ResolveBoxCollision(dropRect, wall);
        if (hit == CollisionSide::None)
        {
            continue;
        }

        //壁に触れたら水滴を削除
        Destory();

        break;
    }
}

void ObjectWaterDrop::Draw()
{
    GameObject::Draw();
}
