#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include "gameobject.h"


class Player : public GameObject
{
private:
	Vec4 m_position;
	Vec4 m_rotation;
	int m_speed;
	bool m_active;
	int m_life;
	// 0 if the button is currently not pressed, 1 otherwise
	std::array <char,4> keyPressed;
	void input();

public:
	Player(const Vec4 _position, const Vec4 _rotation, int _speed, bool _active, int _life);
	~Player();
	const bool active();
	void active(const bool _active);
	void updatePosition(){}
	void updateRotation(){}
	void checkCollision() {}
	void const draw() {}
	void const shoot() {}
	int const life() {}
	void life(const int _life) {}
};

#endif // PLAYER_H
