#include "EnemySatellite.h"

EnemySatellite::EnemySatellite(Vec4 _position, Vec4 _center, Mesh *_mesh, Player * _player, float _speed, bool _active, int _life):
	Enemy(_position,Vec4(0,0,0,1),_speed, _active, _life, _mesh, _player), m_Center(_center)
{
	m_speed = _speed;
}

//----------------------------------------------------------------------------------------------------------------------

void EnemySatellite::updatePosition()
{
	/// updates the position of the enemy so that it will move around a specific point
	float m_initRotation = 1;
	float x = m_Center.m_x + ((m_position.m_x - m_Center.m_x)*std::cos((m_initRotation*M_PI)/180) - (m_position.m_z - m_Center.m_z)*std::sin((m_initRotation*M_PI)/180));
	float z = m_Center.m_z + ((m_position.m_x - m_Center.m_x)*std::sin((m_initRotation*M_PI)/180) + (m_position.m_z - m_Center.m_z)*std::cos((m_initRotation*M_PI)/180));
	m_position.m_x = x;
	m_position.m_z = z;
}

//----------------------------------------------------------------------------------------------------------------------

