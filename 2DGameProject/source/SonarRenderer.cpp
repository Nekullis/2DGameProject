#include "SonarRenderer.h"
#include <DxLib.h>
#include "winmain.h"

SonarRenderer::SonarRenderer() :m_rtStage(-1), m_rtEnemy(-1), m_rtMask(-1)
{
}

bool SonarRenderer::Init()
{
    m_rtStage = MakeScreen(SCREEN_W, SCREEN_H, TRUE);
    m_rtEnemy = MakeScreen(SCREEN_W, SCREEN_H, TRUE);
    m_rtMask = MakeScreen(SCREEN_W, SCREEN_H, TRUE);

    if (m_rtStage == -1 || m_rtEnemy == -1 || m_rtMask == -1)
    {
        return false;
    }

    return true;
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
