#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H

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
};

#endif // UTILITYFUNCTIONS_H


