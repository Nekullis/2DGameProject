//----------------------------------------------------------------------
// @filename SceneGameStage1.h
// @author: Fukuma Kyohei
// @explanation
// 1つ目のゲームステージのクラス
//----------------------------------------------------------------------
#pragma once
#include "s_gamemain.h"

class SceneGameStage1 :public Scene
{
public :
    SceneGameStage1();
    virtual ~SceneGameStage1();

    void Input()    override;
    void Process()  override;
    void Draw()     override;

protected :
   SceneGameMain _s_GameMain;
};



