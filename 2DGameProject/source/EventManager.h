//----------------------------------------------------------------------
// @filename EventManager.h
// @author: Fukuma Kyohei
// @explanation
// ゲーム内イベント処理全般のマネージャークラス
//----------------------------------------------------------------------
#pragma once
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
#include "Event.h"

class Player;

class EventManager
{
public:
    EventManager();
    ~EventManager();
    
    //JSONからデータを読み込む
    void Load(const nlohmann::json data);
    //イベントを更新
    void Update(const Player* player);

private:
    //PlayerとEventの衝突判定
    bool CheckCollision(const Player* player, const Event* event) const;

private:
    std::vector<std::shared_ptr<Event>> m_events;

};

