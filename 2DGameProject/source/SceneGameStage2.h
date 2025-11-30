//----------------------------------------------------------------------
// @filename SceneGameStage2.h
// @author: Fukuma Kyohei
// @explanation
// 2つ目のゲームステージのクラス
//----------------------------------------------------------------------
#pragma once
#include "s_gamemain.h"

class SceneGameStage2 : public Scene
{
public:
    SceneGameStage2();
    virtual ~SceneGameStage2();

    void Input()    override;
    void Process()  override;
    void Draw()     override;

protected:
    SceneGameMain _s_GameMain;
};