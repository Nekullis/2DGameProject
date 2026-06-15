//----------------------------------------------------------------------
// @filename EnemyParamManager.h
// @author: Fukuma Kyohei
// @explanation
// エネミーのパラメータ取得に関するマネージャークラス
//----------------------------------------------------------------------
#pragma once
#include <string>
#include <unordered_map>

struct EnemyData
{
    float MoveSpeed;
    float DetactRange;
    float LoatRange;
    float ReturnRange;
};

class EnemyParamManager
{
public:
    static void Load();
    //敵名からパラメータ取得
    static const EnemyData& Get(const std::string& name);

private:
    static std::unordered_map<std::string, EnemyData> m_param;

};

