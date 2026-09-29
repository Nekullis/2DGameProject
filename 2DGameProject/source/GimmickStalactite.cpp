#include "GimmickStalactite.h"
#include "Time.h"
#include "ObjectWaterDrop.h"
#include "GameObjectManager.h"


GimmickStalactite::GimmickStalactite(float x, float y) :Gimmick("Stalactite", x, y), m_dropInterval(2.0f), m_dropTimer(2.0f)
{
}

GimmickStalactite::~GimmickStalactite()
{
}

void GimmickStalactite::Update()
{
    //基本的なギミック挙動
    Gimmick::Update();

    //水滴生成タイマー
    m_dropTimer -= Time::DeltaTime();

    if (m_dropTimer <= 0.0f)
    {
        //タイマーリセット
        m_dropTimer = m_dropInterval;

        //GameObjectManagerが設定されていれば水滴生成
        if (m_objectManager)
        {
            std::shared_ptr<ObjectWaterDrop> waterDrop = std::make_shared<ObjectWaterDrop>(m_position.x, m_position.y, m_tileMap);
            m_objectManager->Add(waterDrop);
        }
    }
}

void GimmickStalactite::Draw()
{
    Gimmick::Draw();
}
