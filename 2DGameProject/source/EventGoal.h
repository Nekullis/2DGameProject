//----------------------------------------------------------------------
// @filename EventGoal.h
// @author: Fukuma Kyohei
// @explanation
// ゲームクリアに関する処理のイベント派生クラス
//----------------------------------------------------------------------
#pragma once
#include "Event.h"

class EventGoal : public Event
{
public:
    EventGoal(float x, float y);
    //ゴールイベント実行
    void Execute() override;

};

