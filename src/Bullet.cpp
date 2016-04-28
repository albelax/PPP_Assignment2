#include "Bullet.h"

Bullet::Bullet(const Vec4 _position, const Vec4 _rotation, float _speed, bool _active, Mesh * _mesh) :
	GameObject(_position, _rotation, _speed, _active), m_mesh()
{
	m_mesh = _mesh;
  m_active = false;
  m_speed = _speed;
	m_size = 1;
  m_collisionLimit_x = std::max(std::abs(_mesh ->min().m_x),m_mesh ->max().m_x)*m_size;
  m_collisionLimit_z = std::max(std::abs(_mesh ->min().m_z),m_mesh ->max().m_z)*m_size;
}

void Bullet::active(bool const _active)
{
	if (m_active == false)
	{
		m_rotation = m_parent->getRotation();
		m_position = m_parent->getPosition();
	}
	m_active = _active;
}

void Bullet::updatePosition()
{
	if(m_active)
	{
		 m_position.m_x = m_position.m_x -std::sin((m_rotation[0]* M_PI)/180) * m_speed;
		 m_position.m_z = m_position.m_z -std::cos((m_rotation[0]* M_PI)/180) * m_speed;
	}
}

void Bullet::draw() const
{
	if (m_active)
	{
    if (dynamic_cast<Player*>(m_parent))
      glColor3f(0,1,0);
    else
      glColor3f(1,0,0);
    glPushMatrix();
      glTranslatef(m_position.m_x,0,m_position.m_z);
      glRotatef(m_rotation.m_x,0,1,0);
      m_mesh->draw(m_size);
    glPopMatrix();
	}
}
