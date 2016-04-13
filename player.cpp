#include "player.h"

Player::Player(Vec4 const _position, Vec4 const _rotation, float _speed, bool _active, int _life, Mesh *_playerMesh) :
	 GameObject(_position, _rotation, _speed, _active), m_life(_life = 3), m_playerMesh()
{
	m_speed = _speed;
	m_position = {0,1,0,1};
	m_playerMesh = _playerMesh;
	m_size = 0.5f;
	m_boundingBoxMin = m_playerMesh -> min()*m_size;
	m_boundingBoxMax = m_playerMesh -> max()*m_size;
	m_centerBoundingBox.m_x = (std::abs(m_boundingBoxMax.m_x) - std::abs(m_boundingBoxMin.m_x))/2;
	m_centerBoundingBox.m_z = (std::abs(m_boundingBoxMax.m_z) - std::abs(m_boundingBoxMin.m_z))/2;
}

bool Player::active() const
{
	return GameObject::active();
}

void Player::active(bool const _active)
{
	GameObject::active(_active);
}

/// input is the function that takes the input and stores them into a member array
void Player::input(SDL_Event & _event)
{
	m_previousKeyPressed = m_keyPressed;
	if (_event.type == SDL_KEYDOWN)
	{
		switch (_event.key.keysym.sym)
		{
			case SDLK_LEFT : m_keyPressed[0] = '1'; break;
			case SDLK_RIGHT : m_keyPressed[1] = '1'; break;
			case SDLK_UP : m_keyPressed[2] = '1'; break;
			case SDLK_DOWN : m_keyPressed[3] = '1'; break;
			default: break;
		}
	}

	else if(_event.type == SDL_KEYUP)
	{
		switch (_event.key.keysym.sym)
		{
			case SDLK_LEFT : m_keyPressed[0] = '0'; break;
			case SDLK_RIGHT : m_keyPressed[1] = '0'; break;
			case SDLK_UP : m_keyPressed[2] = '0'; break;
			case SDLK_DOWN : m_keyPressed[3] = '0'; break;
			default: break;
		}
	}
}

void Player::updateRotation()
{
	//left
	if(m_currentSpeed != 0)
	{
		if (m_keyPressed[0] == '1')
		{
			if (m_rotation.m_x == 360)
				m_rotation.m_x = 0;
			m_rotation.m_x += 2.5f;
		}
		// right
		if (m_keyPressed[1] == '1')
		{
				if (m_rotation.m_x == 0)
					m_rotation.m_x = 360;
			m_rotation.m_x -= 2.5f;
		}
	}

	if (m_keyPressed[2] == '1' || m_keyPressed[3] == '1')
		m_lastActiveRotation = m_rotation;

//	m_boundingBoxMin.m_x = m_centerBoundingBox.m_x + (m_boundingBoxMin.m_x - m_centerBoundingBox.m_x) * std::cos((m_rotation.m_x* M_PI)/180) -
//	(m_boundingBoxMin.m_z - m_centerBoundingBox.m_z) * -std::sin((m_rotation.m_x* M_PI)/180);

//	m_boundingBoxMin.m_z = m_centerBoundingBox.m_z + (m_boundingBoxMin.m_x - m_centerBoundingBox.m_x) * -std::sin((m_rotation.m_x* M_PI)/180) +
//	(m_boundingBoxMin.m_z - m_centerBoundingBox.m_z) * std::cos((m_rotation.m_x* M_PI)/180);

}

/// UpdatePosition gets a member array containing the input previously stored and updates the player's position
void Player::updatePosition()
{
	/* the vector has to be setthis way,
	 * the x and z values are the only ones that will be modified,
	 * the other ones need to be set to 1 so that the Assert in the normalize() won't fail
	 * (just in case it will be normalized)
	 */
	Vec4 temp(0,1,0,1);
	float x_direction = 0;
	float y_direction = 0;

	x_direction = -std::sin((m_rotation[0]* M_PI)/180);
	y_direction = -std::cos((m_rotation[0]* M_PI)/180);

	if (m_keyPressed[2] == '1' && m_keyPressed[3] == '1')
	{
		temp[0] = 0;
		temp[2] = 0;
	}
	// UP
	else if (m_keyPressed[2] == '1')
	{
		m_currentSpeed = m_speed;
		temp[0] = x_direction * m_speed;
		temp[2] = y_direction * m_speed;
	}
	// DOWN
	else if (m_keyPressed[3] == '1')
	{
		m_currentSpeed = -m_speed;
		temp[0] = -x_direction * m_speed;
		temp[2] = -y_direction * m_speed;
	}

	// slowdown before stopping
	if (m_currentSpeed < 0.001f && m_currentSpeed > -0.001f)
	{
		m_currentSpeed = 0;
	}
	if (m_keyPressed[2] == '0' && m_currentSpeed > 0 && m_previousKeyPressed[3] != '1')
	{
		temp[0] = -std::sin((m_lastActiveRotation[0]* M_PI)/180) * m_currentSpeed;
		temp[2] = -std::cos((m_lastActiveRotation[0]* M_PI)/180) * m_currentSpeed;
		m_currentSpeed -= 0.002f;
	}

	if(m_keyPressed[3] == '0' && m_currentSpeed < 0 && m_previousKeyPressed[2] != '1')
	{
		temp[0] = -std::sin((m_lastActiveRotation[0]* M_PI)/180) * m_currentSpeed;
		temp[2] = -std::cos((m_lastActiveRotation[0]* M_PI)/180) * m_currentSpeed;

		m_currentSpeed += 0.002f;
	}

	m_position = m_position + temp;

//	m_boundingBoxMin.m_x = m_boundingBoxMin.m_x + temp.m_x;
//	m_boundingBoxMax.m_x = m_boundingBoxMax.m_x + temp.m_x;
//	m_boundingBoxMin.m_z = m_boundingBoxMin.m_z + temp.m_z;
//	m_boundingBoxMax.m_z = m_boundingBoxMax.m_z + temp.m_z;
	m_centerBoundingBox.m_x = m_centerBoundingBox.m_x + temp.m_x;
	m_centerBoundingBox.m_z = m_centerBoundingBox.m_z + temp.m_z;

//	m_boundingBoxMin.m_x = (m_centerBoundingBox.m_x + (((m_playerMesh ->min().m_x*m_size)+m_position.m_x) - m_centerBoundingBox.m_x) * std::cos((m_rotation.m_x* M_PI)/180)
//	- (((m_playerMesh ->min().m_z*m_size)+m_position.m_z) - m_centerBoundingBox.m_z)*std::sin((m_rotation.m_x* M_PI)/180));

//	m_boundingBoxMin.m_z = m_centerBoundingBox.m_z + (((m_playerMesh ->min().m_x*m_size)+m_position.m_x)-m_centerBoundingBox.m_x) * std::sin((m_rotation.m_x* M_PI)/180)
//	+ (((m_playerMesh ->min().m_z*m_size) + m_position.m_z)-m_centerBoundingBox.m_z)*std::cos((m_rotation.m_x* M_PI)/180);

//	m_boundingBoxMax.m_x = (m_centerBoundingBox.m_x + (((m_playerMesh ->max().m_x*m_size)+m_position.m_x) - m_centerBoundingBox.m_x) * std::cos((m_rotation.m_x* M_PI)/180)
//	- (((m_playerMesh ->max().m_z*m_size)+m_position.m_z) - m_centerBoundingBox.m_z)*std::sin((m_rotation.m_x* M_PI)/180));

//	m_boundingBoxMax.m_z = m_centerBoundingBox.m_z + (((m_playerMesh ->max().m_x*m_size)+m_position.m_x)-m_centerBoundingBox.m_x) * std::sin((m_rotation.m_x* M_PI)/180)
//	+ (((m_playerMesh ->max().m_z*m_size) + m_position.m_z)-m_centerBoundingBox.m_z)*std::cos((m_rotation.m_x* M_PI)/180);
}

void Player::draw() const
{
	Vec4 min = m_playerMesh ->min();
	Vec4 max = m_playerMesh ->max();

	float centerX = ((max.m_x + min.m_x) * m_size) + m_position.m_x;
	float centerZ = ((max.m_z + min.m_z) * m_size) + m_position.m_z;

	glPointSize(10);
	glColor3f(0.21f, 0.254f, 0.258f);
	glPushMatrix();
		glTranslatef(m_position.m_x,0,m_position.m_z);
		glRotatef(m_rotation.m_x,0,1,0);
		m_playerMesh->draw(m_size);
	glPopMatrix();

	glBegin(GL_POINTS);
//		glVertex3f(m_boundingBoxMin.m_x, m_boundingBoxMin.m_y, m_boundingBoxMin.m_z);
//		glVertex3f(m_boundingBoxMin.m_x, m_boundingBoxMin.m_y, m_boundingBoxMax.m_z);
//		glVertex3f(m_boundingBoxMax.m_x, m_boundingBoxMin.m_y, m_boundingBoxMin.m_z);
//		glVertex3f(m_boundingBoxMax.m_x, m_boundingBoxMin.m_y, m_boundingBoxMax.m_z);

			//glVertex3f( (centerX + (((min.m_x*m_size)+m_position.m_x) - centerX) * std::cos((m_rotation.m_x* M_PI)/180) - (((min.m_z*m_size)+m_position.m_z) - centerZ)*-std::sin((m_rotation.m_x* M_PI)/180)),min.m_y,
				//centerZ + (((min.m_x*m_size)+m_position.m_x)-centerX)* -std::sin((m_rotation.m_x* M_PI)/180) + (((min.m_z*m_size)+m_position.m_z)-centerZ)*std::cos((m_rotation.m_x* M_PI)/180));
			glVertex3f(m_centerBoundingBox.m_x,min.m_y, m_centerBoundingBox.m_z);
	glEnd();
}

Vec4 Player::getPosition() const
{
	return m_position;
}

Vec4 Player::getRotation() const
{
	return m_rotation;
}
