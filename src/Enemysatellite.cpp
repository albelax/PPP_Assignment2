#include "EnemySatellite.h"

EnemySatellite::EnemySatellite(Vec4 _position, Vec4 _center, Mesh *_mesh, Player * _player, float _speed, bool _active, int _life):
	Enemy(_position,Vec4(0,0,0,1),_speed, _active, _life, _mesh, _player), m_Center(_center)
{
	//m_Center = _center;
	m_speed = _speed;
	//m_position.m_x = m_Center->getPosition().m_x + m_Center->getCollisionLimit_x();
	//m_position.m_z = m_Center->getPosition().m_z + m_Center->getCollisionLimit_z();
}

void EnemySatellite::updatePosition()
{
	float m_initRotation = 1;
	float x = m_Center.m_x + ((m_position.m_x - m_Center.m_x)*std::cos((m_initRotation*M_PI)/180) - (m_position.m_z - m_Center.m_z)*std::sin((m_initRotation*M_PI)/180));
	float z = m_Center.m_z + ((m_position.m_x - m_Center.m_x)*std::sin((m_initRotation*M_PI)/180) + (m_position.m_z - m_Center.m_z)*std::cos((m_initRotation*M_PI)/180));
	//std::cout << m_Center.m_x << " " << m_Center.m_z<< std::endl;
	m_position.m_x = x;
	m_position.m_z = z;
}

void EnemySatellite::updateRotation()
{
	float x = m_player->getPosition().m_x - m_position.m_x;
	float z = m_player->getPosition().m_z - m_position.m_z;

	if (std::abs(x) > 1 || std::abs(z) > 1)
	{
		x = m_player->getNextPosition().m_x - m_position.m_x;
		z = m_player->getNextPosition().m_z - m_position.m_z;
	}
	float angle = std::atan2(-x,-z)*180/M_PI;
	m_rotation.m_x = angle;
}
