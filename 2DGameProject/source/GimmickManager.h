//----------------------------------------------------------------------
// @filename EventManager.h
// @author: Fukuma Kyohei
// @explanation
// ゲーム内ギミック処理全般のマネージャークラス
//----------------------------------------------------------------------
#pragma once
#include <vector>
#include <nlohmann/json.hpp>
#include "Gimmick.h"

class GimmickManager
{
public:
    GimmickManager();
    ~GimmickManager();

    //JSONからデータを読み込む
    void Load(const nlohmann::json data);

    //読み込んだギミックをGameOgjectManagerへ渡す
    std::vector<std::shared_ptr<Gimmick>> TakeGimmicks();

private:
    //読み込んだギミック
    std::vector<std::shared_ptr<Gimmick>> m_gimmicks;
};

