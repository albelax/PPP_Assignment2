#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <vector>
#include <string>
#include <SDL.h>
#include <math.h>
#include "GLFunctions.h"
#include "UtilityFunctions.h"
#include "Player.h"
#include "Obstacle.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Mesh.h"
#include "EnemySatellite.h"
#include "Particles.h"
#include <typeinfo>

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

/// \class Level
/// \brief contains most objects, it is basically a "master class", which was useful to manage timers

class Level
{
private:
	int m_mapWidth;
	int m_mapHeight;
	int m_ObstacleNumber;
	float m_cellSize;
	Vec4 m_position;
	Player *m_player;
	std::vector<std::vector<char>> m_map;
	std::vector<Obstacle> m_obstacles;
	std::vector<Bullet> m_bullets;
	std::vector<EnemySatellite> m_Satellites;
	std::vector<Enemy> m_enemies;
	std::vector<GameObject*> m_objects;
	std::vector<Mesh> m_meshes;
	Particles m_particles;
	void loadMap();
public:
	Level(std::string _address, Player* _player, std::vector<Mesh *> _meshes, int _cellSize);
  void drawMap() const;
	void draw() const;
	bool wallCollision(GameObject * _gameObject, Vec4 _pos);
  void update();
  void activateBullets();
	void Collisions();
	Player * getPlayer() { return m_player;}
	void enemyCanShoot();
	Particles * getParticles() {return &m_particles;}
};

#endif // LEVEL_H
