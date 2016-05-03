#ifndef PARTICLES_H
#define PARTICLES_H

#include <iostream>
#include <vector>
#include <string>
#include <SDL.h>
#include <math.h>
#include "GLFunctions.h"
#include "Mesh.h"
#include <Particle.h>

/// \class Particles
/// \brief handles the activation of multiple Particle objects

class Particles
{
private:
	Vec4 m_position;
	Mesh * m_mesh;
	std::vector<Particle> m_particles;
public:
	Particles(int _particles, Mesh * m_mesh);
	void activateParticles(Vec4 _position);
	void updateParticles();
	void deactivateParticles();
	void draw() const;
};

#endif // PARTICLES_H
