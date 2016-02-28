#include "player.h"

Player::Player(const Vec4 _position, const Vec4 _rotation, int _speed, bool _active, int _life) :
	GameObject(_position, _rotation, _speed, _active), m_life(_life = 3)
{

}

const bool Player::active()
{
	GameObject::active();
}

void Player::active(const bool _active)
{
	GameObject::active(_active);
}

void Player::input()
{

}
