//----------------------------------------------------------------------
// @filename GameObjectManager.h
// @author: Fukuma Kyohei
// @explanation
// オブジェクト追加、削除を行うマネージャークラス
//----------------------------------------------------------------------
#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"

class GameObjectManager
{
public:
	//追加
	void Add(std::shared_ptr<GameObject> obj);
	//更新
	void Update();
	//描画まとめ
	void DrawByType(ObjectType type);

protected:
	std::vector<std::shared_ptr<GameObject>> m_objects;
};

