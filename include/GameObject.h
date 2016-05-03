#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Vec4.h"

/// \class GameObject
/// \brief this class is the base class for most of the objects in the scene

class GameObject
{
protected:
	Vec4 m_position;
	Vec4 m_rotation;
	float m_speed;
	float m_size;
	float m_life;
	float m_collisionLimit_x;
	float m_collisionLimit_z;
	bool m_active;
	bool m_collided;

public:
	GameObject(const Vec4 _position, const Vec4 _rotation, float _speed, bool _active);
	~GameObject() {}
  virtual void updatePosition() {}
  virtual void updateRotation() {}
	virtual bool active() const;
	virtual void active(bool const _active);
	virtual void checkCollision(bool _collided) {}
	virtual void draw() const {}
	int life() const { return m_life; }
	void life(int const _life) { m_life = _life; }
	Vec4 getPosition() const { return m_position; }
	Vec4 getRotation() const { return m_rotation; }
	float getCollisionLimit_x() const { return m_collisionLimit_x; }
	float getCollisionLimit_z() const { return m_collisionLimit_z; }
	float getSize() const { return m_size; }
};

#endif // GAMEOBJECT_H
