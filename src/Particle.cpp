#include "Particle.h"


Particle::Particle(Mesh *_mesh)
{
	m_mesh = _mesh;
	m_active = false;
}

void Particle::activate(Vec4 _position, float _rotation)
{
	m_position = _position;
	m_rotation = _rotation;
	m_active = true;
}

void Particle::update()
{
	if (m_active)
	{
		m_position.m_x +=  std::sin((m_rotation* M_PI)/180) * 0.35f;
		m_position.m_z += -std::cos((m_rotation* M_PI)/180) * 0.35f;
	}
}

void Particle::draw() const
{
	if (m_active)
	{
			glColor3f(1, 1, 1);
			glPushMatrix();
			glTranslatef(m_position.m_x,0,m_position.m_z);
			glRotatef(m_rotation,0,1,0);
			m_mesh->draw(1);
			glPopMatrix();
	}
}
