#ifndef ENEMYSATELLITE_H
#define ENEMYSATELLITE_H

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
#include "player.h"
#include "enemy.h"

class EnemySatellite : public Enemy
{
	Vec4 m_Center;
public:
	EnemySatellite(Vec4 _position, Vec4 _center, Mesh *_mesh, Player * _player, float _speed, bool _active, int _life);
	void updatePosition() override;
	void updateRotation() override;
};

#endif // ENEMYSATELLITE_H
