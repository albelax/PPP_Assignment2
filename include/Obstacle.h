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

/// \class Obstacle
/// \brief inherits from GameObject and is a static element in the scene

class Obstacle : public GameObject
{
private:
  int m_life;
  Mesh * m_mesh;
  float m_size;

public:
	Obstacle(Vec4 const _position, Vec4 const _rotation, float _speed, bool _active, int _life, Mesh *_mesh, float _size);
	void draw() const;
};

#endif // OBSTACLE_H
