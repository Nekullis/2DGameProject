//----------------------------------------------------------------------
// @filename SceneGameStage3.h
// @author: Fukuma Kyohei
// @explanation
// 3つ目のゲームステージのクラス
//----------------------------------------------------------------------
#pragma once
#include "s_gamemain.h"

class SceneGameStage3 :public Scene
{
public:
    SceneGameStage3();
    virtual ~SceneGameStage3();

    void Input()    override;
    void Process()  override;
    void Draw()     override;

protected:
    SceneGameMain _s_GameMain;
};