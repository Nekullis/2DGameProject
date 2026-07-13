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
    void FadeHistory();
    void BeginScene();
    void EndScene();
    void BeginMask();
    void EndMask();
    void UpdateHistoryMask();

    int GetSceneHandle() const { return m_rtScene; }
    int GetCurrentMaskHandle()const { return m_rtCurrentMask; };
    int GetHistoryMaskHandle()const { return m_rtHistoryMask[m_historyIndex]; }

private:
    int m_psHandle;
    int m_fadePS;
    int m_rtScene;
    int m_rtCurrentMask;
    int m_rtHistoryMask[2];
    int m_historyIndex;
};

