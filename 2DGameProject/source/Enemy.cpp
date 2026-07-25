#include "Enemy.h"
#include "Player.h"

Enemy::Enemy():m_player(nullptr), m_detectRange(0.0f), m_lostRange(0.0f)
{
    m_objType = ObjectType::Enemy;
    m_collider.SetLayer(CollisionLayer::Enemy);
}
