#ifndef PLAYER_H
#define PLAYER_H

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

class Player : public GameObject
{
private:
	Vec4 m_lastActiveRotation;
	Vec4 m_nextPosition;
	float m_currentSpeed;
	int m_life;
	// 0 if the button is currently not pressed, 1 otherwise
	std::array <char,5> m_keyPressed;
	std::array <char,5> m_previousKeyPressed;
	Mesh * m_playerMesh;
	float m_size;
	//bool m_shoot;
	bool m_willCollide;
	bool m_canShoot;

public:
	Player(Vec4 const _position, Vec4 const _rotation, float _speed, bool _active, int _life, Mesh *_playerMesh);
	~Player(){}
	void updatePosition();
	void updateRotation();
	void checkCollision(bool _collided);
	void draw() const;
	//void shoot(bool _shoot) { m_shoot = _shoot; }
	bool canShoot() const { return m_canShoot; }
	void canShoot(bool _canShoot) { m_canShoot = _canShoot; }
	void input(SDL_Event & _event);
	Vec4 getNextPosition() const { return m_nextPosition; }
	void willCollide(bool _willCollide) { m_willCollide = _willCollide; }
	std::array <char,5> pressedKeys() { return m_keyPressed; }
};

#endif // PLAYER_H
