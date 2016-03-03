#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include <vector>
#include <string>
#include <SDL.h>
#include <iostream>
#include <ios>
#include "gameobject.h"
#include "GLFunctions.h"
#include <math.h>



class Player : public GameObject
{
private:
	Vec4 m_position;
	Vec4 m_rotation;
	float m_speed;
	bool m_active;
	int m_life;
	// 0 if the button is currently not pressed, 1 otherwise
	std::array <char,4> m_keyPressed;
	std::vector < std::array <float,3> >  m_meshVertices;
	std::string m_meshAddress;
	void loadMesh();

public:
	Player(const Vec4 _position, const Vec4 _rotation, float _speed, bool _active, int _life);
	~Player(){}
	const bool active();
	void active(const bool _active);
	void updatePosition();
	void updateRotation();
	void checkCollision() {}
	void const draw();
	void const shoot() {}
	int const life() {}
	void life(const int _life) {}
	void input(SDL_Event & _event);
	Vec4 const getPosition();
};

#endif // PLAYER_H
