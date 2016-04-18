#include "level.h"

Level::Level(int _width, int _height, int _obstacles, Player* _player) :
	m_mapWidth(_width),m_mapHeight(_height),m_ObstacleNumber(_obstacles)
{
	m_map.resize(m_mapHeight);
	std::vector<std::vector<char>>::iterator it;
	for (it = m_map.begin(); it != m_map.end(); ++it)
	{
		(*it).resize(m_mapWidth);
	}
	generateMap();
}


Level::Level(std::string _address, Player* _player)
{
	m_player = _player;
	m_position = Vec4(0,0,0,1);
	m_cellSize = 5;
	std::vector<std::string> mapFile = utilityFunctions::loadFromFile(_address);
	int count = 0;
	for (int i = 0; i < mapFile.size(); ++i)
	{
		if (utilityFunctions::split(mapFile[i])[0] == "w")
			m_mapWidth = std::stoi(utilityFunctions::split(mapFile[i])[1]);
		else if (utilityFunctions::split(mapFile[i])[0] == "h")
		{
			m_mapHeight = std::stoi(utilityFunctions::split(mapFile[i])[1]);
		}
		else
		{
			std::vector<char> tempVec;
			for (int j = 0; j < utilityFunctions::split(mapFile[i]).size()-1; ++j)
			{
				std::string tempLine = utilityFunctions::split(mapFile[i])[j];
				if( tempLine == "0")
					tempVec.push_back('0');
				else if(tempLine == "1")
					tempVec.push_back('1');
			}
			m_map.push_back(tempVec);
			tempVec.clear();
		}
		++count;
	}
}

void Level::generateMap()
{
	srand((int)time(NULL));
	std::vector<int> taken;

	int obstacles = m_ObstacleNumber;
	while (obstacles > 0)
	{
		int w = rand()%4;
		int h = rand()%4;
		int x = rand()%m_mapWidth;
		int y = rand()%m_mapHeight;
		bool patchFree = true;

		if (w < 3)
			w = 3;
		if (h < 3)
			h = 3;
		if ( x + w > m_mapWidth)
			x -= w;
		if ( y + h > m_mapWidth)
			y -= h;

		if (taken.size() == 0)
		{
			taken.push_back(x+w);
			taken.push_back(y+h);
		}

		for (int i = 0; i < taken.size(); i+=2)
		{
			if (x+w == i || y+h == i+1)
				patchFree = false;
		}

		if(patchFree)
		{
			for (int i = 0; i < h; ++i)
			{
				for (int j = 0; j < w; ++j)
				{
					m_map[x+j][y+i] = '1';
				}
			}
			--obstacles;
		}
	}
	std::vector<std::vector<char>>::iterator it;
	for (it = m_map.begin(); it != m_map.end(); ++it)
	{
		std::vector<char>::iterator it_2;
		for (it_2 = (*it).begin(); it_2 != (*it).end(); ++it_2)
		{
			if ( (*it_2) != '1' )
				(*it_2) = '0';
			std::cout << (*it_2) << " ";
		}
		std::cout << std::endl;
	}
}

void Level::draw() const
{
	float x = m_cellSize/2;
	float z = m_cellSize/2;

	glColor3f(1, 0, 0);

	for (int i = 0; i < m_map.size(); ++i)
	{
		for (int j = 0; j < m_map[i].size(); ++j)
		{
			if ( m_map[i][j] != '1' )
			{
				if (std::abs(m_player->getPosition().m_x - j*m_cellSize) < 15
				 && std::abs(m_player->getPosition().m_z - i*m_cellSize) < 15)
				{
					glPushMatrix();
						glTranslatef(x,0,z);
						GLFunctions::cube(m_cellSize,1,m_cellSize);
					glPopMatrix();
				}
			}
			x += m_cellSize;
		}
		z += m_cellSize;
		x = m_cellSize/2;
	}
}


bool Level::wallCollision(GameObject * _gameObject)
{
	int xPositive = static_cast<int>((_gameObject->getPosition().m_x + _gameObject->getCollisionLimit_x())/(m_cellSize));
	int zPositive = static_cast<int>((_gameObject->getPosition().m_z + _gameObject->getCollisionLimit_z())/(m_cellSize));
	int xNegative = static_cast<int>((_gameObject->getPosition().m_x - _gameObject->getCollisionLimit_x())/(m_cellSize));
	int zNegative = static_cast<int>((_gameObject->getPosition().m_z - _gameObject->getCollisionLimit_z())/(m_cellSize));

	if(m_map[zPositive][xPositive] == '0' || m_map[zNegative][xNegative] == '0' || m_map[zPositive][xNegative] == '0' || m_map[zNegative][xPositive] == '0')
	{
		_gameObject->checkCollision(true);
		return true;
	}
	return false;
}

