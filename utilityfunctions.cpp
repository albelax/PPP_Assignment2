#include "utilityfunctions.h"


std::vector<std::string> utilityFunctions::split(std::string _stringIn, char _splitChar)
{
	int count = 0;
	std::string tempString;
	std::vector<std::string> retVector;
	for (int i = 0; i < _stringIn.length()+1; i++)
	{
		if(tempString.length() < 1 && _stringIn[i] == ' ') continue;
		else if(_stringIn[i] != _splitChar)
		{
			tempString += _stringIn[i];
		}
		else
		{
			retVector.resize(retVector.size() + 1);
			retVector[count] = tempString;
			tempString.clear();
			count++;
		}

		if(i == _stringIn.length())
		{
			retVector.resize(retVector.size()+1);
			retVector[count] = tempString;
			tempString.clear();
			count++;
		}
	}
	return retVector;
}

std::vector<std::string> utilityFunctions::loadFromFile(std::string _fileName)
{
	/*
	 * reads from a file and returns a vector containing all the lines of the file
	 */
	std::vector<std::string> Lines;
	std::ifstream Source;
	Source.open(_fileName);
	Source.seekg(0, std::ios::end); // starts from the beginning and goes to the end of the file to know the lenght of it
	int len = (int)Source.tellg();
	Source.seekg(0);
	int count = 0;

	while (len > 0)
	{
		std::string line;
		getline(Source, line);
		if (line != "")
		{
			if(Lines.size() <= count)
				Lines.resize(Lines.size()+1);
			Lines[count] = line;
			++count;
		}
		--len;
		line.clear();
	}
	Source.close();
	return Lines;
}

std::vector<std::array<float,3>> utilityFunctions::getVertices(std::vector<std::string> _vectorIn)
{
	std::vector<std::array<float,3>> vertices;
	std::vector<std::string> tempData;
	int count = 0;

	for (int i = 0; i < _vectorIn.size(); ++i)
	{
		tempData = split(_vectorIn[i],' ');
		if (tempData[0] == "v")
		{
			if(vertices.size() >= count)
				vertices.resize(vertices.size() + 1);
			for (int j = 0; j < tempData.size()-1; ++j) // -1 to avoid overflow
			{
				vertices[count][j] = std::stof(tempData[j+1]); // +1 because the first is a letter, v for example
			}
			tempData.clear();
			++count;
		}
	}
	return vertices;
}
