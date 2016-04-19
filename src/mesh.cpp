#include "mesh.h"

Mesh::Mesh()
{

}

Mesh::Mesh(std::string _address, std::string _name)
{
  m_name = _name;
	std::vector<float> tempVertices;
	std::vector<float> tempNormals;
	std::vector<std::string> tempFaces;
	std::string line;
	std::vector<std::string> tempData;

	std::ifstream Source;
	Source.open(_address);
	Source.seekg(0, std::ios::end); // starts from the beginning and goes to the end of the file to know the lenght of it
	int len = (int)Source.tellg();
	Source.seekg(0);

	m_minX = 500;
	m_minY = 500;
	m_minZ = 500;
	m_maxX = 0;
	m_maxY = 0;
	m_maxZ = 0;
	while (len > 0)
	{
		getline(Source, line);
		if (line != "")
		{
			tempData = utilityFunctions::split(line);

			if (tempData[0] == "v")
			{
				tempVertices.push_back(std::stof(tempData[1]));
				tempVertices.push_back(std::stof(tempData[2]));
				tempVertices.push_back(std::stof(tempData[3]));
			}
			else if (tempData[0] == "vn")
			{
				tempNormals.push_back(std::stof(tempData[1]));
				tempNormals.push_back(std::stof(tempData[2]));
				tempNormals.push_back(std::stof(tempData[3]));
			}
			else if (tempData[0] == "f")
			{
				for (int i = 0; i < static_cast<int>(tempData.size()-1); ++i) // -1 to avoid overflow
				{
					tempFaces = utilityFunctions::split(tempData[i+1], '/');

					m_vertices.push_back(tempVertices[(std::stoi(tempFaces[0])-1)*3]);
					m_vertices.push_back(tempVertices[((std::stoi(tempFaces[0])-1)*3)+1]);
					m_vertices.push_back(tempVertices[((std::stoi(tempFaces[0])-1)*3)+2]);

					m_normals.push_back(tempNormals[(std::stoi(tempFaces[2])-1)*3]);
					m_normals.push_back(tempNormals[((std::stoi(tempFaces[2])-1)*3)+1]);
					m_normals.push_back(tempNormals[((std::stoi(tempFaces[2])-1)*3)+2]);

						if (tempVertices[(std::stoi(tempFaces[0])-1)*3] < m_minX)
							m_minX = tempVertices[(std::stoi(tempFaces[0])-1)*3];
						else if (tempVertices[(std::stoi(tempFaces[0])-1)*3] > m_maxX)
							m_maxX = tempVertices[(std::stoi(tempFaces[0])-1)*3];
						if (tempVertices[((std::stoi(tempFaces[0])-1)*3)+1] < m_minY)
							m_minY = tempVertices[((std::stoi(tempFaces[0])-1)*3)+1];
						else if (tempVertices[((std::stoi(tempFaces[0])-1)*3)+1] > m_maxY)
							m_maxY = tempVertices[((std::stoi(tempFaces[0])-1)*3)+1];
						if(tempVertices[((std::stoi(tempFaces[0])-1)*3)+2] < m_minZ)
							m_minZ = tempVertices[((std::stoi(tempFaces[0])-1)*3)+2];
						else if(tempVertices[((std::stoi(tempFaces[0])-1)*3)+2] > m_maxZ)
							m_maxZ = tempVertices[((std::stoi(tempFaces[0])-1)*3)+2];
					tempFaces.clear();
				}
			}
		}
		--len;
		tempData.clear();
		line.clear();
	}
//	std::cout <<"minX: " << m_minX << " " << "minY: " << m_minY << " " <<"minZ: " << m_minZ <<std::endl;
//	std::cout <<"maxX: " << m_maxX << " " << "maxY: " << m_maxY << " " <<"maxZ: " << m_maxZ <<std::endl;
	Source.close();
}

void Mesh::draw(const float size) const
{
	glBegin(GL_TRIANGLES);
		for (int i = 0; i < m_vertices.size(); i+=3)
		{
			glNormal3f(m_normals[i]*size, m_normals[i+1]*size, m_normals[i+2]*size);
			glVertex3f(m_vertices[i]*size, m_vertices[i+1]*size, m_vertices[i+2]*size);
		}
	glEnd();
}
