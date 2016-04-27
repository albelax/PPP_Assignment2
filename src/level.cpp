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


Level::Level(std::string _address, Player* _player, std::vector<Mesh *> _meshes, int _cellSize)
{
	m_player = _player;
	m_position = Vec4(0,0,0,1);
	m_cellSize = _cellSize;
  int obstacle;
  int bullet;
  for (int i = 0; i < _meshes.size(); ++i)
  {
    if(_meshes[i]->name() == "obstacle")
      obstacle = i;
    if(_meshes[i]->name() == "bullet")
      bullet = i;
  }
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
			for (int j = 0; j < utilityFunctions::split(mapFile[i]).size(); ++j)
			{
				std::string tempLine = utilityFunctions::split(mapFile[i])[j];
				if(tempLine == "0")
				{
					tempVec.push_back('0');
				}
				else if(tempLine == "1")
				{
					tempVec.push_back('1');
				}
				else if(tempLine == "2")
				{
					tempVec.push_back('2');
					m_obstacles.push_back(Obstacle(Vec4(j*m_cellSize+1.5f, 0, i*m_cellSize - m_cellSize*1.5f),Vec4(0,0,0,1),0,true,0, _meshes[obstacle],6));
					m_Satellites.push_back(EnemySatellite(
						Vec4(m_obstacles.back().getPosition().m_x + m_obstacles.back().getCollisionLimit_x(),0,m_obstacles.back().getPosition().m_z + m_obstacles.back().getCollisionLimit_z()),
						m_obstacles.back().getPosition(),_meshes[0],m_player,0.01f,true,3));
				}
				else if(tempLine == "3")
				{
					tempVec.push_back('3');
					m_obstacles.push_back(Obstacle(Vec4(j*m_cellSize+1.5f, 0, i*m_cellSize - m_cellSize*1.5f),Vec4(0,0,0,1),0,true,0, _meshes[obstacle],8));
					m_Satellites.push_back(EnemySatellite(
						Vec4(m_obstacles.back().getPosition().m_x + m_obstacles.back().getCollisionLimit_x(),0,m_obstacles.back().getPosition().m_z + m_obstacles.back().getCollisionLimit_z()),
						m_obstacles.back().getPosition(), _meshes[0],m_player,0.01f,true,3));
				}
				else if(tempLine == "4")
				{
					tempVec.push_back('4');
					m_obstacles.push_back(Obstacle(Vec4(j*m_cellSize+1.5f, 0, i*m_cellSize - m_cellSize*1.5f),Vec4(0,0,0,1),0,true,0, _meshes[obstacle],12));
					m_Satellites.push_back(EnemySatellite(
						Vec4(m_obstacles.back().getPosition().m_x + m_obstacles.back().getCollisionLimit_x(),0,m_obstacles.back().getPosition().m_z + m_obstacles.back().getCollisionLimit_z()),
						m_obstacles.back().getPosition(),_meshes[0],m_player,0.01f,true,3));
				}
				else if (tempLine == "e")
				{
					tempVec.push_back('e');
					m_enemies.push_back(Enemy(Vec4(j*m_cellSize+2, 0, i*m_cellSize - m_cellSize*1.5f),Vec4(0,0,0,1),0.5f,true,3,_meshes[0],m_player));
				}
			}
			m_map.push_back(tempVec);
			tempVec.clear();
		}
		++count;
	}
	for (int i = 0; i < 50; ++i)
  {
		m_bullets.push_back(Bullet(Vec4(0,0,0,1),Vec4(0,0,0,1),0.5f,false, _meshes[bullet]));
	}
	for (int i = 0; i < m_enemies.size(); ++i)
	{
		m_objects.push_back(&m_enemies[i]);
	}
	for (int i = 0; i < m_Satellites.size(); ++i)
	{
		m_objects.push_back(&m_Satellites[i]);
	}
	for (int i = 0; i < m_obstacles.size(); ++i)
	{
		m_objects.push_back(&m_obstacles[i]);
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


bool Level::wallCollision(GameObject * _gameObject, Vec4 _pos)
{
	int xPositive = static_cast<int>((_pos.m_x + _gameObject->getCollisionLimit_x())/(m_cellSize));
	int zPositive = static_cast<int>((_pos.m_z + _gameObject->getCollisionLimit_z())/(m_cellSize));
	int xNegative = static_cast<int>((_pos.m_x - _gameObject->getCollisionLimit_x())/(m_cellSize));
	int zNegative = static_cast<int>((_pos.m_z - _gameObject->getCollisionLimit_z())/(m_cellSize));

	if(m_map[zPositive][xPositive] == '0' || m_map[zNegative][xNegative] == '0' || m_map[zPositive][xNegative] == '0' || m_map[zNegative][xPositive] == '0')
		return true;
	return false;
}

void Level::update()
{
	m_player->updateRotation();
	m_player->updatePosition();

	for (int i = 0; i < m_objects.size(); ++i)
	{
		if(std::abs(m_player->getPosition().m_x - m_objects[i]->getPosition().m_x) < 40 && std::abs(m_player->getPosition().m_z - m_objects[i]->getPosition().m_z) < 40)
		{
			m_objects[i]->updatePosition();
			m_objects[i]->updateRotation();

			// check collisions between player and the surrounding objects
			if (std::abs(m_player->getPosition().m_x - m_objects[i]->getPosition().m_x) < m_player->getCollisionLimit_x() + m_objects[i]->getCollisionLimit_x()
			&& std::abs(m_player->getPosition().m_z - m_objects[i]->getPosition().m_z) < m_player->getCollisionLimit_z()+ m_objects[i]->getCollisionLimit_z())
			{
				m_player->checkCollision(true);
			}

			if (std::abs(m_player->getNextPosition().m_x - m_objects[i]->getPosition().m_x) < m_player->getCollisionLimit_x() + m_objects[i]->getCollisionLimit_x()
			&& std::abs(m_player->getNextPosition().m_z - m_objects[i]->getPosition().m_z) < m_player->getCollisionLimit_z()+ m_objects[i]->getCollisionLimit_z())
			{
				m_player->willCollide(true);
			}
		}
	}
	activateBullets();

	// checks collision between the playar and the walls
	if(wallCollision(m_player, m_player->getPosition()))
		m_player->checkCollision(true);
	if(wallCollision(m_player, m_player->getNextPosition()))
		m_player->willCollide(true);

	// checks collisions between bullets and the walls
	for(int i = 0; i< m_bullets.size(); ++i)
	{
    if(m_bullets[i].active())
    {
      m_bullets[i].updatePosition();
			if(wallCollision(&m_bullets[i], m_bullets[i].getPosition()))
        m_bullets[i].active(false);
    }
	}
}

void Level::draw() const
{
  m_player->draw();

	for (int i = 0; i < m_objects.size(); ++i)
	{
		if(std::abs(m_player->getPosition().m_x - m_objects[i]->getPosition().m_x) < 40 && std::abs(m_player->getPosition().m_z - m_objects[i]->getPosition().m_z) < 40)
		{
			m_objects[i]->draw();
		}
	}
  for (int i = 0; i < m_bullets.size(); ++i)
  {
    if(m_bullets[i].active())
      m_bullets[i].draw();
  }
  drawMap();
}


void Level::drawMap() const
{
  float x = m_cellSize/2;
  float z = m_cellSize/2;

  glColor3f(1, 0, 0);

  for (int i = 0; i < m_map.size(); ++i)
  {
    for (int j = 0; j < m_map[i].size(); ++j)
    {
      if ( m_map[i][j] == '0' )
      {
				if (std::abs(m_player->getPosition().m_x - j*m_cellSize) < 30
				 && std::abs(m_player->getPosition().m_z - i*m_cellSize) < 30)
        {
          glPushMatrix();
            glTranslatef(x,0,z);
            GLFunctions::cube(m_cellSize, 1, m_cellSize);
          glPopMatrix();
        }
      }
      x += m_cellSize;
    }
    z += m_cellSize;
    x = m_cellSize/2;
  }
}

void Level::activateBullets()
{
	for(int i = 0; i< m_bullets.size(); ++i)
  {
		if(m_bullets[i].active() == false && m_player->canShoot() && m_player->pressedKeys()[4] == '1')
    {
      m_bullets[i].setParent(m_player);
      m_bullets[i].active(true);
			m_player->canShoot(false);
			return;
    }

		for (int i = 0; i < m_objects.size(); ++i)
		{
			if((std::abs(m_player->getPosition().m_x - m_objects[i]->getPosition().m_x) < 30 && std::abs(m_player->getPosition().m_z - m_objects[i]->getPosition().m_z) < 30)
			&& dynamic_cast<Enemy*>(m_objects[i]))
			{
				Enemy* temp_enemy = dynamic_cast<Enemy*>(m_objects[i]);
				//if(temp_enemy->canShoot())
				//{
					m_bullets[i].setParent(temp_enemy);
					m_bullets[i].active(true);
					//temp_enemy->canShoot(false);
				//}
			}
		}
  }
}
