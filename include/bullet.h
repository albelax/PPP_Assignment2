#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include <string>
#include <iostream>
#include "gameobject.h"
#include "GLFunctions.h"
#include <math.h>
#include "utilityfunctions.h"
#include "mesh.h"

class Bullet : public GameObject
{
private:
	Mesh * m_mesh;
	GameObject * m_parent;
public:
	Bullet(const Vec4 _position, const Vec4 _rotation, float _speed, bool _active, Mesh * _mesh);
	void setParent(GameObject * _parent) { m_parent = _parent; }
	//bool active() const { return m_active; }
	void active(bool const _active);
	bool active() const {return m_active;}
	void updatePosition() override;
	void draw() const;
};

#endif // BULLET_H
