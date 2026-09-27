#include "GimmickManager.h"
#include "GimmickStalactite.h"

GimmickManager::GimmickManager()
{
}

GimmickManager::~GimmickManager()
{
}

void GimmickManager::Load(const nlohmann::json data)
{
    //前回のギミックを削除
    m_gimmicks.clear();

    for (const auto& gimmickData : data)
    {
        std::string type = gimmickData["type"];

        float x = gimmickData["x"];
        float y = gimmickData["y"];

        // ギミックの種類に応じて生成
        if (type == "Stalactite")
        {
            //Stalactiteを追加
            m_gimmicks.push_back(std::make_shared<GimmickStalactite>(x, y));
        }
    }
}

std::vector<std::shared_ptr<Gimmick>> GimmickManager::TakeGimmicks()
{
    //読み込んだギミックの所有権を呼び出し側へ渡す
    return std::move(m_gimmicks);
}
