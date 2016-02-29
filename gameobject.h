#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Vec4.h"

class GameObject
{
private:
	Vec4 m_position;
	Vec4 m_rotation;
	float m_speed;
	bool m_active;

public:
	GameObject(const Vec4 _position, const Vec4 _rotation, float _speed, bool _active);
	~GameObject() {}
	virtual void updatePosition() {}
	virtual void updateRotation() {}
	virtual const bool active();
	virtual void active(const bool _active);
	virtual void checkCollision() {}
	virtual void const draw() {}
};

#endif // GAMEOBJECT_H
