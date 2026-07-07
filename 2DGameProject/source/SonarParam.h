//----------------------------------------------------------------------
// @filename SonarParam.h
// @author: Fukuma Kyohei
// @explanation
// ソナーのデータ読み込み用クラス
//----------------------------------------------------------------------
#pragma once
class SonarParam
{
public:
    static void Load();

public:
    static float Speed;
    static float MaxRadius;
    static float RadiusScale;
    static float MinLandingSpeed;
    static int RingWidth;
};

