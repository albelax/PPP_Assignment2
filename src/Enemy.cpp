#include "Enemy.h"

Enemy::Enemy(Vec4 const _position, Vec4 const _rotation, float _speed, bool _active, int _life, Mesh *_mesh, Player * _player) :
	 GameObject(_position, _rotation, _speed, _active), m_mesh()
{
	m_mesh = _mesh;
	m_size = 0.35f;
	m_player = _player;
	m_canShoot = false;
	m_life = _life;
	m_collisionLimit_x = std::max(std::abs(m_mesh->min().m_x), m_mesh->max().m_x)*m_size;
	m_collisionLimit_z = std::max(std::abs(m_mesh->min().m_z), m_mesh->max().m_z)*m_size;
}

void Enemy::updatePosition()
{

}

void Enemy::updateRotation()
{
	float x = m_player->getPosition().m_x - m_position.m_x;
	float z = m_player->getPosition().m_z - m_position.m_z;

	if ((std::abs(x) > 1 || std::abs(z) > 1))
	{
		x = m_player->getNextPosition().m_x - m_position.m_x;
		z = m_player->getNextPosition().m_z - m_position.m_z;
	}
	float angle = std::atan2(-x,-z)*180/M_PI;
	m_rotation.m_x = angle;

}

void Enemy::draw() const
{
	glColor3f(1.0f, 0, 0);
	glPushMatrix();
		glTranslatef(m_position.m_x, 0, m_position.m_z);
		glRotatef(m_rotation.m_x,0, 1, 0);
		m_mesh->draw(m_size);
	glPopMatrix();
}
