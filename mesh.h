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
public:
	Mesh(std::string _address);
	void draw(const float size) const;
};

#endif // MESH_H
