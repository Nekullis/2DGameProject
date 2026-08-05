//----------------------------------------------------------------------
// @filename SonarRenderer.h
// @author: Fukuma Kyohei
// @explanation
// ソナー時の特殊描画に関するクラス
//----------------------------------------------------------------------
#pragma once

//ソナー上限数
constexpr int MAX_DISTORTION = 8;

//ゆがみ情報用
struct DistortionData
{
    //0~1へ正規化した座標
    float PosX;
    float PosY;

    //残り時間
    float Timer;

    //拡張用
    float Dummy;
};

struct DistortionBuffer
{
    DistortionData Data[MAX_DISTORTION];
    int Count;
    float Padding[3];
};

class SonarRenderer
{
public:
    SonarRenderer();
    ~SonarRenderer();

    bool Init();
    //フレームクリア用
    void ClearDistortion();

    void Composite();
    void FadeHistory();
    void BeginScene();
    void EndScene();
    void BeginMask();
    void EndMask();
    void UpdateHistoryMask();

    //GPUｓぴ関数用
    void UpdateDistortionBuffer();

    //ゆがみ情報追加
    void AddDistortion(const class Vector2D& pos, float timer);

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

    //CPU側で書き込むデータ
    DistortionBuffer m_distortionBuffer;
    //GPU側定数バッファの番号
    int m_cdDistortion;
    
};

