#include "Event.h"

Event::Event(const std::string& type, float x, float y) : m_type(type), m_x(x), m_y(y), m_isTriggerd(false)
{
    //EventÇÃColliderê›íË
    m_collider.SetPosition(Vector2D(m_x, m_y));
    m_collider.SetType(ColliderType::Circle);
    m_collider.SetRadius(32.0f);
    m_collider.SetLayer(CollisionLayer::Event);
}

Event::~Event()
{
}

void Event::Execute()
{
}
