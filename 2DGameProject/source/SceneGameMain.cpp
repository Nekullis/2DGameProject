#include "SceneGameMain.h"
#include "TileMap.h"
#include "EnemyParamManager.h"
#include "Bat.h"
#include "SonarParam.h"
#include "winmain.h"

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
    //着地時にソナーが出るようにコールバック
    m_Player->SetLandCallback([this](const Vector2D& pos, float speed) {m_sonarManager.Emit(pos, speed);});
    //コンテナに追加
    m_objectManager.Add(m_Player);

    //敵情報取得
    EnemyParamManager::Load();
    //敵生成
    for (auto& spawn : m_Stage->GetEnemySpawns())
    {
        //コウモリ生成
        if (spawn.type == "Bat")
        {
            auto bat = std::make_shared<Bat>(m_Player.get());
            //初期位置設定
            bat->SetSpawnPos(Vector2D(spawn.x, spawn.y));
            //コンテナ追加
            m_objectManager.Add(bat);
        }
    }

    //ソナー情報登録
    SonarParam::Load();

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
    m_sonarManager.Update();
}

void SceneGameMain::Draw()
{
    //通常シーンをRTへ
    m_sonarRenderer.BeginScene();
    m_Stage->Draw();
    m_objectManager.DrawByType(ObjectType::Enemy);
    m_sonarRenderer.EndScene();

    //Mask生成
    m_sonarRenderer.BeginMask();
    m_sonarManager.Draw();
    m_sonarRenderer.EndMask();

    //合成
    m_sonarRenderer.Composite();

    //プレイヤー描画
    m_objectManager.DrawByType(ObjectType::Player);
}
