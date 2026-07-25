#include "GameObjectManager.h"
#include "GameObject.h"

void GameObjectManager::Add(std::shared_ptr<GameObject> obj)
{
	//末尾に追加
	m_objects.push_back(obj);
}

void GameObjectManager::Update()
{
	//各オブジェクトの更新処理
	for (auto& obj : m_objects)
	{
		//無効なら更新しない
		if (!obj->IsActive())
		{
			continue;
		}
		obj->Update();
	}

	//削除処理
	//コンテナの中の順番を条件の合うものを後ろに追い出してからその位置の物を削除する
	m_objects.erase(std::remove_if(m_objects.begin(), m_objects.end(), 
		[](const std::shared_ptr<GameObject>& obj){return !obj->IsActive();}),
		m_objects.end()
	);
}

void GameObjectManager::DrawByType(ObjectType type)
{
    //プレイヤーオブジェクトの描画処理
    for (auto& obj : m_objects)
    {
        if (!obj->IsActive())
        {
            continue;
        }
        if (obj->GetType() != type)
        {
            continue;
        }
        obj->Draw();
    }
}

void GameObjectManager::CheckCollision()
{
    //全走査して当たり判定を調べる
    for (size_t i = 0; i < m_objects.size(); i++)
    {
        for (size_t j = i + 1; j < m_objects.size(); j++)
        {
            if (!m_objects[i]->IsActive() || !m_objects[j]->IsActive()) { continue; }

            if (m_objects[i]->GetCollider().IsHit(m_objects[j]->GetCollider()))
            {
                m_objects[i]->OnCollision(m_objects[j].get());
                m_objects[j]->OnCollision(m_objects[i].get());
            }
        }
    }
}

