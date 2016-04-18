#include "player.h"

Player::Player(Vec4 const _position, Vec4 const _rotation, float _speed, bool _active, int _life, Mesh *_playerMesh) :
	 GameObject(_position, _rotation, _speed, _active), m_life(_life = 3), m_playerMesh()
{
	m_playerMesh = _playerMesh;
	m_size = 0.25f;

	m_collisionLimit_x = std::max(std::abs(_playerMesh ->min().m_x),m_playerMesh ->max().m_x)*m_size;
	m_collisionLimit_z = std::max(std::abs(_playerMesh ->min().m_z),m_playerMesh ->max().m_z)*m_size;
	m_collided = false;
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
	/* updates the rotation of the player based on the key pressed
	 * m_lastActiveRotation is updated everytime the Player is moving,
	 * it is needed to allow the player to
	 * keep sliding in the last direction before stopping
	 */

	if(m_currentSpeed != 0) //left
	{
		if (m_keyPressed[0] == '1')
		{
			if (m_rotation.m_x == 360)
				m_rotation.m_x = 0;
			m_rotation.m_x += 2.5f;
		}

		if (m_keyPressed[1] == '1') // right
		{
				if (m_rotation.m_x == 0)
					m_rotation.m_x = 360;
			m_rotation.m_x -= 2.5f;
		}
	}

	if (m_keyPressed[2] == '1' || m_keyPressed[3] == '1')
		m_lastActiveRotation = m_rotation;
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

	if (m_collided == false)
	{
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
		m_nextPosition = m_position + temp*3;
	}
	else
	{
		m_position.m_x += std::sin((m_rotation[0]* M_PI)/180)*m_currentSpeed * 5;
		m_position.m_z += std::cos((m_rotation[0]* M_PI)/180)*m_currentSpeed * 5;
		m_currentSpeed = 0;
		m_collided = false;
	}
}

void Player::draw() const
{
	glPointSize(10);
	glColor3f(0.21f, 0.254f, 0.258f);
	glPushMatrix();
		glTranslatef(m_position.m_x,0,m_position.m_z);
		glRotatef(m_rotation.m_x,0,1,0);
		m_playerMesh->draw(m_size);
	glPopMatrix();
}



void Player::checkCollision(bool _collided)
{
//	m_position.m_x += std::sin((m_rotation[0]* M_PI)/180)*m_currentSpeed * 5;
//	m_position.m_z += std::cos((m_rotation[0]* M_PI)/180)*m_currentSpeed * 5;
//	m_currentSpeed = 0;
	m_collided = _collided;
}
