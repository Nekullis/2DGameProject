#include "SonarRenderer.h"
#include "winmain.h"
#include "ShaderUtility.h"
#include <DxLib.h>

SonarRenderer::SonarRenderer() :m_psHandle(-1), m_rtMask(-1), m_rtScene(-1)
{
}

bool SonarRenderer::Init()
{
    m_psHandle = LoadPixelShader("shader/SonarPS.cso");
    m_rtScene = MakeScreen(SCREEN_W, SCREEN_H, TRUE);
    m_rtMask = MakeScreen(SCREEN_W, SCREEN_H, FALSE);

    if (m_rtScene == -1 || m_rtMask == -1)
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
    SetUseTextureToShader(1, m_rtMask);

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
    SetDrawScreen(m_rtMask);
    ClearDrawScreen();
}

void SonarRenderer::EndMask()
{
    SetDrawScreen(DX_SCREEN_BACK);
}

void SonarRenderer::ResolveRT()
{
    // SceneRT → バックバッファへ
    //SetDrawScreen(DX_SCREEN_BACK);
    //(0, 0, SCREEN_W, SCREEN_H, m_rtScene, TRUE);

    //// もう一回 SceneRTに焼き戻し
    //SetDrawScreen(m_rtScene);
    //DrawExtendGraph(0, 0, SCREEN_W, SCREEN_H, DX_SCREEN_BACK, TRUE);

    // MaskRT → バックバッファへ
    //SetDrawScreen(DX_SCREEN_BACK);
    //DrawExtendGraph(0, 0, SCREEN_W, SCREEN_H, m_rtMask, TRUE);

    //// MaskRTに焼き戻し
    //SetDrawScreen(m_rtMask);
    //DrawExtendGraph(0, 0, SCREEN_W, SCREEN_H, DX_SCREEN_BACK, TRUE);
}
