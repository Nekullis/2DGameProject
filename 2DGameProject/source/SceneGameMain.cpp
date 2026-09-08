#include "SceneGameMain.h"
#include "TileMap.h"
#include "EnemyParamManager.h"
#include "Bat.h"
#include "SonarParam.h"
#include "winmain.h"
#include "Time.h"

SceneGameMain::SceneGameMain() :m_gameState(GameState::Playing), m_gameStateTimer(0.0f)
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
            m_sonarManager.AddSonarTargetObject(bat.get());
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
    switch (m_gameState)
    {
    case GameState::Playing:
        ProcessPlaying();
        break;

    case GameState::MovingStage:
        ProcessMovingStage();
        break;

    case GameState::GameOverEffect:
        ProcessGameOverEffect();
        break;

    case GameState::GameOverMenu:
        ProcessGameOverMenu();
        break;

    case GameState::GameClearEffect:
        ProcessGameClearEffect();
        break;

    }
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

    //履歴更新
    m_sonarRenderer.FadeHistory();
    //ゆがみ情報追加
    m_sonarRenderer.ClearDistortion();
    for (const auto& obj : m_objectManager.GetObjects())
    {
        //敵以外は対象外
        if (obj->GetType() != ObjectType::Enemy) { continue; }

        //ソナー反応中でなければスキップ
        if (!obj->IsSonarHit()) { continue; }

        //シェーダーへ送る情報を登録
        m_sonarRenderer.AddDistortion(obj->GetPosition(), obj->GetSonarHitTimer());
    }

    m_sonarRenderer.UpdateDistortionBuffer();

    //最終合成
    m_sonarRenderer.Composite();

    //プレイヤー描画
    m_objectManager.DrawByType(ObjectType::Player);
}

void SceneGameMain::ChangeGameState(GameState state)
{
    m_gameState = state;
    m_gameStateTimer = 0.0f;
}

void SceneGameMain::ProcessPlaying()
{
    //タイマー加算
    m_gameStateTimer += Time::DeltaTime();

    //オブジェクト更新
    m_objectManager.Update();

    //当たり判定
    m_objectManager.CheckCollision();

    //カメラ範囲設定
    MYRECT camLimit{};
    camLimit.x = 0;
    camLimit.y = 0;
    camLimit.w = m_Stage->GetTileMap()->GetMapWidth() * 64;
    camLimit.h = m_Stage->GetTileMap()->GetMapHeight() * 64;
    Camera::w_camera._rcLimit = camLimit;
    //カメラ更新
    Camera::w_camera.Process();

    //ソナー更新
    m_sonarManager.Update();
}

void SceneGameMain::ProcessMovingStage()
{

}

void SceneGameMain::ProcessGameOverEffect()
{
    //タイマー加算
    m_gameStateTimer += Time::DeltaTime();

    //死亡演出

    //一定時間経過でゲームオーバーメニュー出現
    if (m_gameStateTimer >= 1.5f)
    {
        ChangeGameState(GameState::GameOverMenu);
    }

}

void SceneGameMain::ProcessGameOverMenu()
{

}

void SceneGameMain::ProcessGameClearEffect()
{

}
