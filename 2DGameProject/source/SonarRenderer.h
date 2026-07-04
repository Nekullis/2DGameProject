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
    void ResolveRT();

    int GetSceneHandle() const { return m_rtScene; }
    int GetMaskHandle()const { return m_rtMask; };

private:
    int m_psHandle;
    int m_rtMask;
    int m_rtScene;
};

