//----------------------------------------------------------------------
// @filename GameObject.h
// @author: Fukuma Kyohei
// @explanation
// オブジェクトの基底クラス
//----------------------------------------------------------------------
#pragma once
#include <memory>
#include "Vector2D.h"
#include "Sprite.h"
#include "Collider.h"
#include "Animation.h"

enum class ObjectType
{
    None,
    Player,
    Enemy,
    Item
};

class GameObject
{
public:
	//コンストラクタ
	GameObject();
	//仮想デストラクタ
	virtual ~GameObject();
	//更新
	virtual void Update();
	//描画
	virtual void Draw();
	//死亡フラグ
	void Destory();
    //アニメーション変更
    virtual void ChangeAnimation(Animation* anim);
    //接触イベント
    virtual void OnCollision(GameObject* other);

    //ソナーが当たった
    virtual void OnSonarHit();
    //ソナー演出更新
    void UpdateSonarEffect();

    //オブジェクトタイプ
    ObjectType GetType() const { return m_objType; }
    //座標取得
    Vector2D GetPosition() const { return m_position; }
    //ソナー検知半径取得
    float GetSonarRadius()const { return m_sonarRadius; }
    //移動速度取得
    Vector2D GetVelocity() const { return m_velocity; }
	//座標設定
	void SetPosition(const Vector2D& pos);
    //ソナー検知半径設定
    void SetSonarRadius(float radius) { m_sonarRadius = radius; }
    //出現場所設定
    void SetSpawnPos(const Vector2D& pos);
	bool IsActive() const { return m_isActive; }

    Collider& GetCollider() { return m_collider; }
    const Collider& GetCollider() const { return m_collider; }

    bool IsSonarHit() const { return m_isSonarHit; }
    float GetSonarHitTimer() const { return m_sonarHitTimer; }

protected:
    ObjectType m_objType;
	//座標
	Vector2D m_position;
    //出現場所
    Vector2D m_spawnPos;
	//移動速度
	Vector2D m_velocity;
	//使用スプライト
	std::shared_ptr<Sprite> m_sprite;
	//当たり判定
	Collider m_collider;
	//生存フラグ
	bool m_isActive;
    //現在再生中のアニメーション
    Animation* m_currentAnim;

    //ソナー関連
    //ソナーに反応中か
    bool m_isSonarHit;
    //演出タイマー
    float m_sonarHitTimer;
    //ソナー反応半径
    float m_sonarRadius;
};

