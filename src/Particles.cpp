#include "Particles.h"


Particles::Particles(int _particles, Mesh * _mesh)
{
	m_mesh = _mesh;
	for (int i = 0; i < _particles; ++i)
	{
		m_particles.push_back(Particle(m_mesh));
	}
}

void Particles::activateParticles(Vec4 _position)
{
	float currentRotation = 0;
	float increment = 360/m_particles.size();

	for (int i = 0; i < m_particles.size(); ++i)
	{
		m_particles[i].activate(_position, currentRotation);
		currentRotation+= increment;
	}
}

void Particles::updateParticles()
{
	for (int i = 0; i < m_particles.size(); ++i)
	{
		m_particles[i].update();
	}
}

void Particles::draw() const
{
	for (int i = 0; i < m_particles.size(); ++i)
	{
		m_particles[i].draw();
	}
}


void Particles::deactivateParticles()
{
	for (int i = 0; i < m_particles.size(); ++i)
	{
		m_particles[i].deactivate();
	}
}
