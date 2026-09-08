#include "Enemy.h"
#include "Player.h"
#include "Time.h"

Enemy::Enemy():m_player(nullptr), m_detectRange(0.0f), m_lostRange(0.0f)
{
    m_objType = ObjectType::Enemy;
    m_collider.SetLayer(CollisionLayer::Enemy);
    m_collider.SetType(ColliderType::Box);
    SetSonarRadius(200.0f);
}

void Enemy::Update()
{
    GameObject::Update();
}

void Enemy::OnSonarHit()
{
    GameObject::OnSonarHit();
}
