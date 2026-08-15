#include "SonarManager.h"
#include "GameObject.h"

void SonarManager::Emit(const Vector2D& pos, float power)
{
    SonarWave wave;
    wave.Start(pos, power);
    //コンテナに格納
    m_waves.push_back(wave);
}

void SonarManager::Update()
{
    for (auto& wave : m_waves)
    {
        wave.Update();

        //ソナーが消えているなら判定しない
        if (!wave.IsActive()) { continue; }

        for (auto* object : m_objects)
        {
            if (!object->IsActive()) { continue; }
            //距離判定
            float dist = Vector2D::Distance(wave.GetPosition(), object->GetPosition());
            if (dist <= wave.GetRadius() + object->GetSonarRadius())
            {
                if (!wave.HasHitObject(object))
                {
                    //プレイヤーから敵への方向取得
                    Vector2D dir = object->GetPosition() - wave.GetPosition();
                    //歪み追加
                    wave.AddDistortion(atan2(dir.y, dir.x), 25.0f, 1.0f);

                    wave.AddHitObject(object);
                    object->OnSonarHit();
                }
            }
        }
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

void SonarManager::AddSonarTargetObject(GameObject* object)
{
    m_objects.push_back(object);
}
