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



std::vector<std::array<float,3>> utilityFunctions::getNormals(std::vector<std::string> _vectorIn)
{
	std::vector<std::array<float,3>> normals;
	std::vector<std::string> tempData;
	int count = 0;

	for (int i = 0; i < _vectorIn.size(); ++i)
	{
		tempData = split(_vectorIn[i],' ');
		if (tempData[0] == "vn")
		{
			if(normals.size() >= count)
				normals.resize(normals.size() + 1);
			for (int j = 0; j < tempData.size()-1; ++j) // -1 to avoid overflow
			{
				normals[count][j] = std::stof(tempData[j+1]); // +1 because the first is a letter, v for example
			}
			tempData.clear();
			++count;
		}
	}
	return normals;
}

//std::vector<std::vector<int>> utilityFunctions::getFaces(const std::vector<std::string> _vectorIn)
//{
//	std::vector<std::vector<int>> faces;
//	std::vector<std::string> tempLine;
//	std::vector<std::string> tempFace;
//	std::vector<int> vertices;
//	int count = 0;

//	for (int i = 0; i < _vectorIn.size(); ++i)
//	{
//		tempLine = split(_vectorIn[i],' ');
//		if (tempLine[0] == "f")
//		{
//			for (int j = 0; j < tempLine.size()-1; ++j)
//			{
//				tempFace = split(tempLine[j+1], '/');
//				vertices.push_back(std::stoi(tempFace[0]));
//			}
//			faces.push_back(vertices);
//			vertices.clear();
//			++count;
//		}
//	}
//	return faces;
//}


std::vector<std::vector<std::string>> utilityFunctions::getFaces(const std::vector<std::string> _vectorIn)
{
	std::vector<std::vector<std::string>> faces;
	std::vector<std::string> tempFaces;
	std::vector<std::string> tempLine;
	int count = 0;

	for (int i = 0; i < _vectorIn.size(); ++i)
	{
		tempLine = split(_vectorIn[i],' ');
		if (tempLine[0] == "f")
		{
			for (int j = 0; j < tempLine.size()-1; ++j)
			{
				tempFaces.push_back(tempLine[j+1]);
			}
			faces.push_back(tempFaces);
			tempFaces.clear();
			++count;
		}
	}
	return faces;
}


//void utilityFunctions::DrawFaces(const std::vector<std::array<float,3>> _vertices, std::vector<std::vector<int>> _faces)
//{
//	glPointSize(10);
//	glColor4f(1,0,0,1);
//	glBegin(GL_TRIANGLES);
//	for (int i = 0; i < _faces.size(); ++i)
//	{
//		for (int j = 0; j < _faces[i].size();++j)
//		{
//			glVertex3f(_vertices[_faces[i][j]][0], _vertices[_faces[i][j]][1],_vertices[_faces[i][j]][2]);
//			//std::cout << _vertices[_faces[i][j]][0] << " " << _vertices[_faces[i][j]][1] << " " << _vertices[_faces[i][j]][1] << std::endl;
//		}
//		//std::cout << std::endl;
//	}
//	glEnd();
//}

void utilityFunctions::DrawFaces(const std::vector<std::array<float,3>> _vertices, const std::vector<std::array<float,3>> _normals, std::vector<std::vector<std::string>> _faces)
{
	std::vector<std::string> tempFace;
	glPointSize(10);
	glColor4f(1,0,0,1);

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < _faces.size(); ++i)
	{
		for (int j = 0; j < _faces[i].size();++j)
		{
			tempFace = split(_faces[i][j],'/');
			glNormal3f(_normals[std::stoi(tempFace[2]) -1 ][0], _normals[std::stoi(tempFace[2]) -1][1],_normals[std::stoi(tempFace[2]) -1][2]);
			glVertex3f(_vertices[std::stof(tempFace[0]) - 1][0], _vertices[std::stoi(tempFace[0]) - 1][1],_vertices[std::stoi(tempFace[0]) - 1][2]);
			//std::cout << _vertices[std::stoi(tempFace[0])][0] << " " << _vertices[std::stoi(tempFace[0])][1] << " " << _vertices[std::stoi(tempFace[0])][2] << "\n";
		}
	}
	glEnd();
}


