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
    GameObjectManager();

	//追加
	void Add(std::shared_ptr<GameObject> obj);
	//更新
	void Update();
	//描画まとめ
	void DrawByType(ObjectType type);
    //オブジェクト同士の当たり判定
    void CheckCollision();

    //ゲッター
    std::vector<std::shared_ptr<GameObject>> GetObjects() const { return m_objects; }

protected:
    //管理しているオブジェクト
	std::vector<std::shared_ptr<GameObject>> m_objects;

    //更新中に追加されたオブジェクト
    std::vector<std::shared_ptr<GameObject>> m_pendingObjects;

    //現在Update中か
    bool m_isUpdating;
};

