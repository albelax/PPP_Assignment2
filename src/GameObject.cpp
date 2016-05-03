#include "GameObject.h"

GameObject::GameObject(const Vec4 _position, const Vec4 _rotation, float _speed = 0, bool _active = true) :
m_position(_position), m_rotation(_rotation), m_speed(_speed = 0.1f), m_active(_active = true)
{

}

//----------------------------------------------------------------------------------------------------------------------

bool GameObject::active() const
{
	return m_active;
}

//----------------------------------------------------------------------------------------------------------------------

void GameObject::active(bool const _active)
{
	m_active = _active;
}

//----------------------------------------------------------------------------------------------------------------------
