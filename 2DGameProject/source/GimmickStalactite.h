//----------------------------------------------------------------------
// @filename GimmickStalactite.h
// @author: Fukuma Kyohei
// @explanation
// ƒMƒ~ƒbƒN(ß“ûÎ)ˆ—‚ÌƒNƒ‰ƒX
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

private:
    //…“H‚ğ—‚Æ‚·ŠÔŠu
    float m_dropInterval;

    //Ÿ‚Ì…“H‚Ü‚Å‚ÌŠÔ
    float m_dropTimer;
};

