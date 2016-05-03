#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include "GameObject.h"
#include "GLFunctions.h"
#include "UtilityFunctions.h"
#include "Mesh.h"
#include "Player.h"


/// \class Bullet
/// \brief bullets that can be shot by players or enemies


class Bullet : public GameObject
{
private:
	Mesh * m_mesh;
	GameObject * m_parent;
  float m_size;
public:
	Bullet(const Vec4 _position, const Vec4 _rotation, float _speed, bool _active, Mesh * _mesh);
	void setParent(GameObject * _parent) { m_parent = _parent; }
	void active(bool const _active);
	bool active() const {return m_active;}
	void updatePosition() override;
	void draw() const;
	GameObject * getParent() { return m_parent; }
};

#endif // BULLET_H
