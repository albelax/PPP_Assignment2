#include "Obstacle.h"

Obstacle::Obstacle(Vec4 const _position, Vec4 const _rotation, float _speed, bool _active, int _life, Mesh *_mesh, float _size) :
GameObject(_position, _rotation, _speed, _active), m_life(_life = 3), m_mesh(),m_size(_size)
{
	m_speed = _speed;
	m_position = _position;
	m_mesh = _mesh;
	//m_size = 1;
	m_collisionLimit_x = m_mesh ->max().m_x*m_size;
	m_collisionLimit_z = m_mesh ->max().m_z*m_size;
}

void Obstacle::draw() const
{
	glPointSize(10);
	glColor3f(1, 0, 0);
	glPushMatrix();
		glTranslatef(m_position.m_x,0,m_position.m_z);
		//glRotatef(m_rotation.m_x,0,1,0);
		m_mesh->draw(m_size);
	glPopMatrix();
}
