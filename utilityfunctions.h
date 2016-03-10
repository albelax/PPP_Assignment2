#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H


#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

#include <string>
#include <vector>
#include <array>
#include <ios>
#include <iostream>
#include <fstream>

class utilityFunctions
{
public:
	utilityFunctions() = delete;
	static std::vector<std::string> split(const std::string _stringIn, char _splitChar = ' ');
	static std::vector<std::string> loadFromFile(const std::string _fileName);
	static std::vector<std::array<float,3>> getVertices(const std::vector<std::string> _vectorIn);
	static std::vector<std::vector<std::string>> getFaces(const std::vector<std::string> _vectorIn);
	static std::vector<std::array<float,3>> getNormals(const std::vector<std::string> _vectorIn);
	static void DrawFaces(const std::vector<std::array<float,3>> _vertices,const std::vector<std::array<float,3>> _normals, std::vector<std::vector<std::string>> _faces);
};

#endif // UTILITYFUNCTIONS_H


