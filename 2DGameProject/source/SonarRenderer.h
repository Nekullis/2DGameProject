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
    void Composite();
    void BeginScene();
    void EndScene();
    void BeginMask();
    void EndMask();
    void UpdateHistoryMask();

    int GetSceneHandle() const { return m_rtScene; }
    int GetMaskHandle()const { return m_rtCurrentMask; };

private:
    int m_psHandle;
    int m_rtScene;
    int m_rtCurrentMask;
    int m_rtHistoryMask;
};

