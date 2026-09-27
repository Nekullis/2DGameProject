//----------------------------------------------------------------------
// @filename GimmickStalactite.h
// @author: Fukuma Kyohei
// @explanation
// ギミック(鍾乳石)処理のクラス
//----------------------------------------------------------------------
#pragma once
#include "Gimmick.h"

class GimmickStalactite : public Gimmick
{
public:
    GimmickStalactite(float x, float y);
    virtual ~GimmickStalactite();

    void Update() override;
    void Draw() override;
};

