//----------------------------------------------------------------------
// @filename Bat.h
// @author: Fukuma Kyohei
// @explanation
// 敵のコウモリに関するクラス
//----------------------------------------------------------------------
#pragma once
#include "Enemy.h"

enum class BAT_STATE
{
    //待機
    Idle,
    //追跡
    Chase,
    //帰還
    Return
};

class Bat : public Enemy
{
public:
    Bat(Player* player);
    void Update() override;

protected:
    void LoadAnimation();
    void UpdateIdle();
    void UpdateChase();
    void UpdateReturn();

    //ステータス
    BAT_STATE m_state;
    //移動量
    float m_moveSpeed;
    //アニメーション関連
    Animation m_idleAnim;
    Animation m_ChaseAnim;
    Animation m_ReturnAnim;
};

