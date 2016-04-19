#ifndef MESH_H
#define MESH_H

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

#include <array>
#include <vector>
#include <string>
#include <SDL.h>
#include <iostream>
#include "GLFunctions.h"
#include "utilityfunctions.h"

class Mesh
{
private:
	std::vector<float> m_vertices;
	std::vector<float> m_normals;
	float m_minX, m_minY, m_minZ, m_maxX, m_maxY, m_maxZ;
  std::string m_name;
public:
  Mesh(std::string _address, std::string _name);
	Mesh();
	void draw(const float size) const;
	Vec4 min()const {return Vec4(m_minX,m_minY,m_minZ,1);}
	Vec4 max()const {return Vec4(m_maxX,m_maxY,m_maxZ,1);}
  std::string name() const {return m_name;}
};

#endif // MESH_H
