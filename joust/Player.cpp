#include "stdafx.h"
#include "Player.h"


Player::Player(double x1, double y1, double l1, double w1, int type1, std::string sprite1) 
: GameObject::GameObject(x1, y1, l1, w1, type1, sprite1)
{
	lives = 5;
	score = 0;
}


Player::~Player()
{
}


void Player::setScore(int c)
{
	score = c;
}


void Player::setLives(int c)
{
	lives = c;
}


int Player::getScore()
{
	return score;
}


int Player::getLives()
{
	return lives;
}


void Player::collision(double colx, double coly, bool die)
{
	if (die)
	{
		if (lives != 0)
			lives--;
		else
		{
			//Game end, delete all objects.
		}
	}
	else
	{
		//Change velocity
	}
}