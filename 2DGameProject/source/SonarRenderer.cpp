#include "SonarRenderer.h"
#include "winmain.h"
#include "ShaderUtility.h"
#include <DxLib.h>

SonarRenderer::SonarRenderer() :m_psHandle(-1), m_rtScene(-1), m_rtCurrentMask(-1), m_rtHistoryMask(-1)
{
}

bool SonarRenderer::Init()
{
    m_psHandle = LoadPixelShader("shader/SonarPS.cso");
    m_rtScene = MakeScreen(SCREEN_W, SCREEN_H, TRUE);
    m_rtCurrentMask = MakeScreen(SCREEN_W, SCREEN_H, FALSE);
    m_rtHistoryMask = MakeScreen(SCREEN_W, SCREEN_H, FALSE);

    if (m_rtScene == -1 || m_rtCurrentMask == -1 || m_rtHistoryMask == -1)
    {
        return false;
    }

    return true;
}

void SonarRenderer::Composite()
{
    SetDrawScreen(DX_SCREEN_BACK);
    //シェーダー有効化
    SetUsePixelShader(m_psHandle);

    VERTEX2DSHADER vertices[6];
    ShaderUtility::CreateFullScreenQuad(vertices, SCREEN_W, SCREEN_H);

    SetUseTextureToShader(0, m_rtScene);
    SetUseTextureToShader(1, m_rtHistoryMask);

    DrawPolygon2DToShader(vertices, 2);

    //シェーダー解除
    SetUsePixelShader(-1);
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
    SetDrawScreen(m_rtHistoryMask);
    ClearDrawScreen();

    DrawExtendGraph(0, 0, SCREEN_W, SCREEN_H, m_rtCurrentMask, TRUE);
    SetDrawScreen(DX_SCREEN_BACK);
}

