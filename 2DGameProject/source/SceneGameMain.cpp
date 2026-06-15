#include "SceneGameMain.h"
#include "TileMap.h"
#include "EnemyParamManager.h"

SceneGameMain::SceneGameMain()
{
    //ステージ生成
    m_Stage = std::make_shared<Stage>();
    m_Stage->Load("data/json/StageMap.json");
    //プレイヤー生成
    m_Player = std::make_shared<Player>(m_Stage->GetTileMap());
    //出現位置
    m_Player->SetPosition(Vector2D(m_Stage->GetPlayerSpawnX(), m_Stage->GetPlayerSpawnY()));
    m_objectManager.Add(m_Player);
    //敵情報取得
    EnemyParamManager::Load();
    //カメラ設定
    Camera::w_camera.SetTarget(m_Player.get());
}

SceneGameMain::~SceneGameMain()
{
}

void SceneGameMain::Input()
{
}

void SceneGameMain::Process()
{
    m_objectManager.Update();
    MYRECT camLimit{};
    camLimit.x = 0;
    camLimit.y = 0;
    camLimit.w = m_Stage->GetTileMap()->GetMapWidth() * 64;
    camLimit.h = m_Stage->GetTileMap()->GetMapHeight() * 64;
    Camera::w_camera._rcLimit = camLimit;
    Camera::w_camera.Process();
}

void SceneGameMain::Draw()
{
    m_Stage->Draw();
    m_objectManager.Draw();
}
