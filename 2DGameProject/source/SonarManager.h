//----------------------------------------------------------------------
// @filename SonarManager.h
// @author: Fukuma Kyohei
// @explanation
// ソナー管理クラス
//----------------------------------------------------------------------
#pragma once
#include "Vector2D.h"
#include <vector>
#include "SonarWave.h"

class GameObject;

class SonarManager
{
public:
    void Emit(const Vector2D& pos, float power);

    void Update();
    void Draw();

    //ソナー判定対象の敵を登録
    void AddSonarTargetObject(GameObject* object);
    //ゲッター
    std::vector<SonarWave> GetWavws() { return m_waves; }

private:
    std::vector<SonarWave> m_waves;
    std::vector<GameObject*> m_objects;
};

