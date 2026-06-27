#include "SonarRenderer.h"
#include "winmain.h"
#include "ShaderUtility.h"
#include <DxLib.h>

SonarRenderer::SonarRenderer() :m_psHandle(-1),m_rtStage(-1), m_rtEnemy(-1), m_rtMask(-1)
{
}

bool SonarRenderer::Init()
{
    m_psHandle = LoadPixelShader("shader/SonarPS.cso");
    m_rtStage = MakeScreen(SCREEN_W, SCREEN_H, TRUE);
    m_rtEnemy = MakeScreen(SCREEN_W, SCREEN_H, TRUE);
    m_rtMask = MakeScreen(SCREEN_W, SCREEN_H, TRUE);

    if (m_rtStage == -1 || m_rtEnemy == -1 || m_rtMask == -1)
    {
        return false;
    }

    return true;
}

void SonarRenderer::End()
{
    SetDrawScreen(DX_SCREEN_BACK);
}

void SonarRenderer::Composite()
{
    SetDrawScreen(DX_SCREEN_BACK);
    //ステージとプレイヤー
    DrawGraph(0, 0, m_rtStage, TRUE);
    //シェーダー有効化
    SetUsePixelShader(m_psHandle);
    //シェーダーへテクスチャを渡す
    SetUseTextureToShader(0, m_rtEnemy);
    SetUseTextureToShader(1, m_rtMask);
    //画面全体ポリゴン描画
    VERTEX2DSHADER vertices[6];
    ShaderUtility::CreateFullScreenQuad(vertices, SCREEN_W, SCREEN_H);
    DrawPolygon2DToShader(vertices,2);
    //シェーダー解除
    SetUsePixelShader(-1);
}

void SonarRenderer::BeginStage()
{
    SetDrawScreen(m_rtStage);
    ClearDrawScreen();
}

void SonarRenderer::BeginEnemy()
{
    SetDrawScreen(m_rtEnemy);
    ClearDrawScreen();
}

void SonarRenderer::BeginMask()
{
    SetDrawScreen(m_rtMask);
    ClearDrawScreen();
}
