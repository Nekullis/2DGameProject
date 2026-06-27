#include "SceneGameMain.h"
#include "TileMap.h"
#include "EnemyParamManager.h"
#include "Bat.h"

SceneGameMain::SceneGameMain()
{
    m_sonarRenderer.Init();

    //ステージ生成
    m_Stage = std::make_shared<Stage>();
    m_Stage->Load("data/json/StageMap.json");

    //プレイヤー生成
    m_Player = std::make_shared<Player>(m_Stage->GetTileMap());
    //プレイヤー出現位置
    m_Player->SetSpawnPos(Vector2D(m_Stage->GetPlayerSpawnX(), m_Stage->GetPlayerSpawnY()));
    m_objectManager.Add(m_Player);

    //敵情報取得
    EnemyParamManager::Load();
    //敵生成
    for (auto& spawn : m_Stage->GetEnemySpawns())
    {
        if (spawn.type == "Bat")
        {
            auto bat = std::make_shared<Bat>(m_Player.get());
            bat->SetSpawnPos(Vector2D(spawn.x, spawn.y));
            m_objectManager.Add(bat);
        }
    }

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
    m_sonarRenderer.BeginStage();
    m_Stage->Draw();
    m_objectManager.DrawByType(ObjectType::Player);

    m_sonarRenderer.BeginEnemy();
    m_objectManager.DrawByType(ObjectType::Enemy);

    //Mask
    m_sonarRenderer.BeginMask();
    DrawCircle(900, 500, 300, GetColor(255, 255, 255), TRUE);

    //レンダーターゲット終了
    m_sonarRenderer.End();

    // 最終描画
    m_sonarRenderer.Composite();
}
