#include "SonarManager.h"

void SonarManager::Emit(const Vector2D& pos, float power)
{
    SonarWave wave;
    wave.Start(pos, power);
    //ƒRƒ“ƒeƒi‚ÉŠi”[
    m_waves.push_back(wave);
}

void SonarManager::Update()
{
    for (auto& wave : m_waves)
    {
        wave.Update();
    }

    m_waves.erase(std::remove_if(m_waves.begin(), m_waves.end(), 
        [](const SonarWave& wave)
        {
            return !wave.IsActive();
        }),
        m_waves.end()
    );
}

void SonarManager::Draw()
{
    for (auto& wave : m_waves)
    {
        wave.Draw();
    }
}
