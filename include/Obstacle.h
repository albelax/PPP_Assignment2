#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <array>
#include <vector>
#include <string>
#include <SDL.h>
#include <iostream>
#include "gameobject.h"
#include "GLFunctions.h"
#include <math.h>
#include "utilityfunctions.h"
#include "mesh.h"

class Obstacle : public GameObject
{
private:
	float m_size;
	Mesh * m_mesh;
	int m_life;

public:
	Obstacle(Vec4 const _position, Vec4 const _rotation, float _speed, bool _active, int _life, Mesh *_mesh, float _size);
	void draw() const;
	//float getCollisionLimitX() const { return  m_collisionLimit_x; }
	//float getCollisionLimitZ() const { return  m_collisionLimit_z; }
};

#endif // OBSTACLE_H
