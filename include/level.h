#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <vector>
#include <string>
#include <SDL.h>
#include <math.h>
#include "GLFunctions.h"
#include "utilityfunctions.h"
#include "player.h"
#include "obstacle.h"
#include "bullet.h"
#include <typeinfo>

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

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
	void generateMap();
	void loadMap();
public:
	Level(int _height, int _width, int _obstacles, Player* _player);
	Level(std::string _address, Player* _player, std::vector<Mesh *> _meshes, int _cellSize);
  void drawMap() const;
	void draw() const;
	bool wallCollision(GameObject * _gameObject, Vec4 _pos);
  void update();
  void activateBullets();

};

#endif // LEVEL_H
