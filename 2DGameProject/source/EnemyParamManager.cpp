#include "EnemyParamManager.h"
#include "JSONManager.h"

std::unordered_map<std::string, EnemyData> EnemyParamManager::m_param;

void EnemyParamManager::Load()
{
    //データ読み取り
    auto data = JSONManager::Read("data/json/EnemyParam.json");
    //初回読み込み時、情報をクリア
    m_param.clear();
    //データを取得
    for (auto& enemy : data.items())
    {
        EnemyData param{};
        param.MoveSpeed = enemy.value()["MoveSpeed"];
        param.DetectRange = enemy.value()["DetectRange"];
        param.LostRange = enemy.value()["LostRange"];
        param.ReturnRange = enemy.value()["ReturnRange"];

        m_param[enemy.key()] = param;
    }
}

const EnemyData& EnemyParamManager::Get(const std::string& name)
{
    return m_param.at(name);
}
