//----------------------------------------------------------------------
// @filename GameObject.h
// @author: Fukuma Kyohei
// @explanation
// 鍾乳石の処理を行うゲームオブジェクトの派生クラス
//----------------------------------------------------------------------
#pragma once
#include "GameObject.h"

class TileMap;

class ObjectWaterDrop : public GameObject
{
public:
    ObjectWaterDrop(float x, float y, TileMap* tileMap);
    virtual ~ObjectWaterDrop();

    void Update() override;
    void Draw() override;

private:
    //マップ
    TileMap* m_tileMap;
};

