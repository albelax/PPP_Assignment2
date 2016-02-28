#include "gameobject.h"

GameObject::GameObject(const Vec4 _position, const Vec4 _rotation, int _speed = 0, bool _active = true) :
m_position(_position), m_rotation(_rotation), m_speed(_speed = 1), m_active(_active = true)
{

}

const bool GameObject::active()
{
	return m_active;
}


void GameObject::active(const bool _active)
{
	m_active = _active;
}
