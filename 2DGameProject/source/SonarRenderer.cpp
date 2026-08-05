#include "SonarRenderer.h"
#include "winmain.h"
#include "ShaderUtility.h"
#include <DxLib.h>
#include "Vector2D.h"

SonarRenderer::SonarRenderer() :m_psHandle(-1), m_fadePS(-1), m_rtScene(-1), m_rtCurrentMask(-1), m_historyIndex(0), m_cdDistortion(-1)
{
}

SonarRenderer::~SonarRenderer()
{
    if (m_cdDistortion != -1)
    {
        DeleteShaderConstantBuffer(m_cdDistortion);
    }
}

bool SonarRenderer::Init()
{
    m_psHandle = LoadPixelShader("shader/SonarPS.cso");
    m_fadePS = LoadPixelShader("shader/MakeFadePS.cso");
    m_rtScene = MakeScreen(SCREEN_W, SCREEN_H, TRUE);
    m_rtCurrentMask = MakeScreen(SCREEN_W, SCREEN_H, FALSE);
    m_rtHistoryMask[0] = MakeScreen(SCREEN_W, SCREEN_H, FALSE);
    m_rtHistoryMask[1] = MakeScreen(SCREEN_W, SCREEN_H, FALSE);
    m_cdDistortion = CreateShaderConstantBuffer(sizeof(DistortionBuffer));

    if (m_rtScene == -1 || m_rtCurrentMask == -1 || m_rtHistoryMask[0] == -1 || m_rtHistoryMask[1] == -1)
    {
        return false;
    }

    return true;
}

void SonarRenderer::ClearDistortion()
{
    m_distortionBuffer.Count = 0;
}

void SonarRenderer::Composite()
{
    SetDrawScreen(DX_SCREEN_BACK);
    //シェーダー有効化
    SetUsePixelShader(m_psHandle);

    //定数バッファをピクセルシェーダーのb0へ設定
    SetShaderConstantBuffer(m_cdDistortion, DX_SHADERTYPE_PIXEL, 0);

    VERTEX2DSHADER vertices[6];
    ShaderUtility::CreateFullScreenQuad(vertices, SCREEN_W, SCREEN_H);

    SetUseTextureToShader(0, m_rtScene);
    SetUseTextureToShader(1, m_rtHistoryMask[m_historyIndex]);

    DrawPolygon2DToShader(vertices, 2);

    //使用後に解除
    SetShaderConstantBuffer(-1, DX_SHADERTYPE_PIXEL, 0);

    //シェーダー解除
    SetUsePixelShader(-1);
}

void SonarRenderer::FadeHistory()
{
    int read = m_historyIndex;
    int write = 1 - m_historyIndex;

    SetDrawScreen(m_rtHistoryMask[write]);
    ClearDrawScreen();

    //前フレームをフェード
    SetUsePixelShader(m_fadePS);

    SetUseTextureToShader(0, m_rtHistoryMask[read]);

    VERTEX2DSHADER vertices[6];
    ShaderUtility::CreateFullScreenQuad(vertices, SCREEN_W, SCREEN_H);
    DrawPolygon2DToShader(vertices, 2);

    SetUseTextureToShader(0, -1);
    SetUsePixelShader(-1);

    //今フレームのMaskを重ねる
    SetDrawBlendMode(DX_BLENDMODE_ADD, 255);

    DrawExtendGraph(0, 0, SCREEN_W, SCREEN_H, m_rtCurrentMask, TRUE);

    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    SetDrawScreen(DX_SCREEN_BACK);

    m_historyIndex = write;
}

void SonarRenderer::BeginScene()
{
    SetDrawScreen(m_rtScene);
    ClearDrawScreen();
}

void SonarRenderer::EndScene()
{
    SetDrawScreen(DX_SCREEN_BACK);
}

void SonarRenderer::BeginMask()
{
    SetDrawScreen(m_rtCurrentMask);
    ClearDrawScreen();
}

void SonarRenderer::EndMask()
{
    SetDrawScreen(DX_SCREEN_BACK);
}

void SonarRenderer::UpdateHistoryMask()
{
    int write = m_historyIndex;
    int read = 1 - m_historyIndex;

    SetDrawScreen(m_rtHistoryMask[write]);
    ClearDrawScreen();

    DrawExtendGraph(0, 0, SCREEN_W, SCREEN_H, m_rtCurrentMask, TRUE);
    SetDrawScreen(DX_SCREEN_BACK);
}

void SonarRenderer::UpdateDistortionBuffer()
{
    //GPU定数バッファのメモリを取得
    void* buffer = GetBufferShaderConstantBuffer(m_cdDistortion);
    //CPU側データをコピー
    memcpy(buffer, &m_distortionBuffer, sizeof(DistortionBuffer));
    //GPUへ反映
    UpdateShaderConstantBuffer(m_cdDistortion);
}

void SonarRenderer::AddDistortion(const Vector2D& pos, float timer)
{
    //上限
    if (m_distortionBuffer.Count >= MAX_DISTORTION) { return; }

    int index = m_distortionBuffer.Count;
    //uvに変換
    m_distortionBuffer.Data[index].PosX = pos.x / SCREEN_W;
    m_distortionBuffer.Data[index].PosY = pos.y / SCREEN_H;

    m_distortionBuffer.Data[index].Timer = timer;
    m_distortionBuffer.Data[index].Dummy = 0.0f;

    m_distortionBuffer.Count++;
}

