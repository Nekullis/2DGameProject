#include "GameObject.h"
#include "Time.h"

GameObject::GameObject() :m_objType(ObjectType::None), m_position(0, 0), m_velocity(0, 0), m_isActive(true), m_currentAnim(nullptr), m_isSonarHit(false), m_sonarHitTimer(0.0f), m_sonarRadius(0.0f)
{
}

GameObject::~GameObject()
{

}

void GameObject::Update()
{
	//座標更新
	m_position += m_velocity * Time::DeltaTime();
	//collider位置同期
	m_collider.SetPosition(m_position);
	//Sprite位置同期
	if (m_sprite)
	{
		m_sprite->SetPosition(m_position.x, m_position.y);
	}
    UpdateSonarEffect();
}

void GameObject::Draw()
{
	if (m_sprite)
	{
		m_sprite->Draw();
	}
}

void GameObject::Destory()
{
	m_isActive = false;
}

void GameObject::ChangeAnimation(Animation* anim)
{
    //同じアニメーションならなにもしない
    if (m_currentAnim == anim)
    {
        return;
    }
    //切り替え
    m_currentAnim = anim;
    m_currentAnim->Reset();
}

void GameObject::OnCollision(GameObject* other)
{
    //なにもしない
}


void GameObject::OnSonarHit()
{
    //演出開始
    m_isSonarHit = true;
    //タイマーリセット
    m_sonarHitTimer = 0.5;
}

void GameObject::UpdateSonarEffect()
{
    if (!m_isSonarHit) { return; }

    //時間を減らす
    m_sonarHitTimer -= Time::DeltaTime();
    //終了
    if (m_sonarHitTimer <= 0)
    {
        m_sonarHitTimer = 0.0f;
        m_isSonarHit = false;
    }
}

void GameObject::SetPosition(const Vector2D& pos)
{
	m_position = pos;
	m_collider.SetPosition(pos);
	if (m_sprite)
	{
		m_sprite->SetPosition(pos.x, pos.y);
	}
}

void GameObject::SetSpawnPos(const Vector2D& pos)
{
    m_spawnPos = m_position = pos;
    m_collider.SetPosition(pos);
    if (m_sprite)
    {
        m_sprite->SetPosition(pos.x, pos.y);
    }
}
