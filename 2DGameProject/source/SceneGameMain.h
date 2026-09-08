//----------------------------------------------------------------------
// @filename SceneGameMain.h
// @author: Fukuma Kyohei
// @explanation
// ゲームのメインクラス
//----------------------------------------------------------------------
#pragma once
#include "Scene.h"
#include "Stage.h" 
#include "Player.h"
#include "camera.h"
#include "GameObjectManager.h"
#include "SonarRenderer.h"
#include "SonarManager.h"

enum class GameState
{
    //通常
    Playing,
    //ステージ遷移
    MovingStage,
    //死亡演出
    GameOverEffect,
    //リトライ待ち
    GameOverMenu,
    //クリア演出
    GameClearEffect
};

class SceneGameMain : public Scene
{
public:
	// コンストラクタ
	SceneGameMain();
	// デストラクタ
	virtual ~SceneGameMain();

	// 入力
	void Input() override;
	// 計算
	void Process()override;
	// 描画
	void Draw() override;

    //ゲームステータス変更
    void ChangeGameState(GameState state);

    //各ゲームステータスの更新処理
    //通常状態
    void ProcessPlaying();
    //ステージ遷移
    void ProcessMovingStage();
    //死亡演出
    void ProcessGameOverEffect();
    //リトライ待ち
    void ProcessGameOverMenu();
    //クリア演出
    void ProcessGameClearEffect();

private:
    //ステージ
    std::shared_ptr<Stage> m_Stage;
    //プレイヤー
    std::shared_ptr<Player> m_Player;
    //オブジェクト管理
    GameObjectManager m_objectManager;
    //レンダー
    SonarRenderer m_sonarRenderer;
    //ソナー
    SonarManager m_sonarManager;

    //ゲームステータス
    GameState m_gameState;
    //現在のゲームステータスのタイマー
    float m_gameStateTimer;
};

