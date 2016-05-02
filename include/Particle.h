#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <vector>
#include <string>
#include <SDL.h>
#include "GLFunctions.h"
#include "Mesh.h"

class Particle
{
private:
	Vec4 m_position;
	float m_rotation;
	float m_speed;
	Mesh * m_mesh;
	bool m_active;
public:
	Particle(Mesh * _mesh);
	void activate(Vec4 _position, float _rotation);
	void update();
	void deactivate() { m_active = false; }
	void draw() const;
};

#endif // PARTICLE_H
