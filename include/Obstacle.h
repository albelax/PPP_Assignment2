#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <array>
#include <vector>
#include <string>
#include <SDL.h>
#include <iostream>
#include "GameObject.h"
#include "GLFunctions.h"
#include <math.h>
#include "UtilityFunctions.h"
#include "Mesh.h"

class Obstacle : public GameObject
{
private:
	float m_size;
	Mesh * m_mesh;
	int m_life;

public:
	Obstacle(Vec4 const _position, Vec4 const _rotation, float _speed, bool _active, int _life, Mesh *_mesh, float _size);
	void draw() const;
};

#endif // OBSTACLE_H
