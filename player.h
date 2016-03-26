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


class Player : public GameObject
{
private:
	Vec4 m_position;
	Vec4 m_rotation;
	float m_speed;
	//bool m_active;
	int m_life;
	// 0 if the button is currently not pressed, 1 otherwise
	std::array <char,4> m_keyPressed;
	std::vector < std::array <float,3> >  m_meshVertices;
	std::string m_meshAddress;

	std::vector<std::string> m_mesh;
	std::vector<std::array<float,3>> m_vertices;
	std::vector<std::array<float,3>> m_normals;
	std::vector<std::vector<std::string>> m_faces;

public:
	Player(const Vec4 _position, const Vec4 _rotation, float _speed, bool _active, int _life);
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
