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

private:
    //ステージ
    std::shared_ptr<Stage> m_Stage;
    //プレイヤー
    std::shared_ptr<Player> m_Player;
    //オブジェクト管理
    GameObjectManager m_objectManager;
    //レンダー
    SonarRenderer m_sonarRenderer;
};

