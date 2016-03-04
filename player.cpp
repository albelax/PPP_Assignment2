#include "player.h"

Player::Player(const Vec4 _position, const Vec4 _rotation, float _speed, bool _active, int _life) :
	GameObject(_position, _rotation, _speed, _active), m_life(_life = 3)
{
	m_speed = _speed;
	m_position = {0,1,0,1};
	m_meshAddress = "test.obj";
}

const bool Player::active()
{
	GameObject::active();
}

void Player::active(const bool _active)
{
	GameObject::active(_active);
}

/// input is the function that takes the input and stores them into a member array
void Player::input(SDL_Event & _event)
{
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
	if (m_keyPressed[0] == '1')
	{
		if (m_rotation[0] == 360)
			m_rotation = 0;
		m_rotation[0] += 5;
	}
	// right
	if (m_keyPressed[1] == '1')
	{
			if (m_rotation[0] == 0)
				m_rotation = 360;
		m_rotation[0] -= 5;
	}
	//std::cout << m_rotation[0] << std::endl;
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
		temp[0] = x_direction * m_speed;
		temp[2] = y_direction * m_speed;
	}
	// DOWN
	else if (m_keyPressed[3] == '1')
	{
		temp[0] = -x_direction * m_speed;
		temp[2] = -y_direction * m_speed;
	}

	m_position = m_position + temp;
}

const void Player::draw()
{
	glColor3f(0.21, 0.254, 0.258);

	glPushMatrix();
		glTranslatef(m_position[0],0,m_position[2]);
		glRotatef(m_rotation[0]+180,0,1,0);
			GLFunctions::cone(0.4f,0.8f,4,1);
	glPopMatrix();
}

const Vec4 Player::getPosition()
{
	return m_position;
}
