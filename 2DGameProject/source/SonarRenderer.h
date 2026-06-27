//----------------------------------------------------------------------
// @filename SonarRenderer.h
// @author: Fukuma Kyohei
// @explanation
// ソナー時の特殊描画に関するクラス
//----------------------------------------------------------------------
#pragma once

class SonarRenderer
{
public:
    SonarRenderer();

    bool Init();
    void End();
    void Composite();
    void BeginStage();
    void BeginEnemy();
    void BeginMask();

    int GetStageHandle() const { return m_rtStage; }
    int GetEnemyHandle()const { return m_rtEnemy; };
    int GetMaskHandle()const { return m_rtMask; };

private:
    int m_psHandle;
    int m_rtStage;
    int m_rtEnemy;
    int m_rtMask;
};

