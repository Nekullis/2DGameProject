#include "EventManager.h"
#include "EventGoal.h"
#include "Player.h"

EventManager::EventManager()
{
}

EventManager::~EventManager()
{
}

void EventManager::Load(const nlohmann::json data)
{
    m_events.clear();

    for (const auto& eventData : data)
    {
        //type取得
        std::string type = eventData["type"];
        //座標取得
        float x = eventData["x"];
        float y = eventData["y"];

        //typeによってイベント作成
        if (type == "Goal")
        {
            m_events.push_back(std::make_shared<EventGoal>(x, y));
        }
    }
}

void EventManager::Update(const Player* player)
{
    for (auto& event : m_events)
    {
        if (event->IsTriggerd())
        {
            continue;
        }

        if (CheckCollision(player, event.get()))
        {
            event->Execute();
            event->SetTriggerd(false);
        }
    }
}

bool EventManager::CheckCollision(const Player* player, const Event* event) const
{
    if (event == nullptr)
    {
        return false;
    }
    
    return player->GetCollider().IsHit(event->GetCollider());
}
