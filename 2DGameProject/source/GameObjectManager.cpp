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

