#include "Gimmick.h"
#include "GameObjectManager.h"

Gimmick::Gimmick(const std::string& gimmickType, float x, float y) : m_gimmickType(gimmickType), m_objectManager(nullptr)
{
    m_objType = ObjectType::Gimmick;

    m_collider.SetPosition(Vector2D(x,y));
    m_collider.SetType(ColliderType::Box);
    m_collider.SetSize(64.0f, 64.0f);
    m_collider.SetLayer(CollisionLayer::Gimmick);

}

Gimmick::~Gimmick()
{
}

void Gimmick::Update()
{
    GameObject::Update();
}

void Gimmick::Draw()
{
    GameObject::Draw();
}
