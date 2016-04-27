#ifndef ENEMY_H
#define ENEMY_H

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

class Enemy : public GameObject
{
protected:
	bool m_shoot;
	int m_life;
	Mesh * m_mesh;
	Player * m_player;
	float m_size;
	bool m_canShoot;
	bool m_closeToPlayer;
	//float m_initRotation;
public:
	Enemy(Vec4 const _position, Vec4 const _rotation, float _speed, bool _active, int _life, Mesh *_mesh, Player * _player);
	virtual void updatePosition();
	virtual void updateRotation();
	virtual void draw() const;
	bool canShoot() const { return m_canShoot; }
	void canShoot(bool _canShoot) { m_canShoot = _canShoot; }
};

#endif // ENEMY_H
