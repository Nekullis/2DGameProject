//----------------------------------------------------------------------
// @filename Enemy.h
// @author: Fukuma Kyohei
// @explanation
// “GŠî’êƒNƒ‰ƒX
//----------------------------------------------------------------------
#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
    Enemy();
    virtual void Update() = 0;

protected:
    class Player* m_player;
    //ŒŸo”ÍˆÍ
    float m_detectRange;
    //Œ©¸‚¤‹——£
    float m_lostRange;
};

