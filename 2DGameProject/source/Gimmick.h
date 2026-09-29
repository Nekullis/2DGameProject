//----------------------------------------------------------------------
// @filename Gimmick.h
// @author: Fukuma Kyohei
// @explanation
// ゲーム内ギミック処理の基底クラス
//----------------------------------------------------------------------
#pragma once
#include <string>
#include "GameObject.h"

class GameObjectManager;
class TileMap;

class Gimmick : public GameObject
{
public:
    Gimmick(const std::string& type, float x, float y);
    virtual ~Gimmick();

    virtual void Update() override;
    virtual void Draw() override;

    //ギミック情報獲得
    const std::string& GetType() const { return m_gimmickType; }

    //オブジェクトマネージャー設定
    void SetObjectManager(GameObjectManager* manager) { m_objectManager = manager; }

    //タイルマップ設定
    void SetTileMap(TileMap* tileMap) { m_tileMap = tileMap; }

protected:
    //ギミック種類
    std::string m_gimmickType;

    //オブジェクト管理
    GameObjectManager* m_objectManager;

    //マップ
    TileMap* m_tileMap;
};

