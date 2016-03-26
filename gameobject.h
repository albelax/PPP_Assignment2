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
	virtual bool active() const;
	virtual void active(bool const _active);
	virtual void checkCollision() {}
	virtual void draw() const {}
};

#endif // GAMEOBJECT_H
