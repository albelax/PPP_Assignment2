#ifndef PLAYER_H
#define PLAYER_H

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


class Player : public GameObject
{
private:
	Vec4 m_position;
	Vec4 m_rotation;
	Vec4 m_lastActiveRotation;
	float m_speed;
	float m_currentSpeed;
	//bool m_active;
	int m_life;
	// 0 if the button is currently not pressed, 1 otherwise
	std::array <char,4> m_keyPressed;
	std::array <char,4> m_previousKeyPressed;
	Mesh * m_playerMesh;
	float m_size;

	Vec4 m_boundingBoxMin;
	Vec4 m_boundingBoxMax;
	Vec4 m_centerBoundingBox;

public:
	Player(Vec4 const _position, Vec4 const _rotation, float _speed, bool _active, int _life, Mesh *_playerMesh);
	~Player(){}
	bool active() const;
	void active(bool const _active);
	void updatePosition();
	void updateRotation();
	void checkCollision() {}
	void draw() const;
	void shoot() const {}
	//int life() const {}
	//void life(int const _life) {}
	void input(SDL_Event & _event);
	Vec4 getPosition() const;
	Vec4 getRotation() const;
};

#endif // PLAYER_H
