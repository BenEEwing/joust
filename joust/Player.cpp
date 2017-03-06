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


bool Player::collision(double colx, double coly, bool die)
{
	bool isDelete = false; //Decide if the object should be deleted from the array in StateManager
	if (die)
	{
		if (lives != 0)
			lives--;
		else
		{
			isDelete = true;
		}
	}
	else
	{
		this->setVX(this->getVX() * -1 / 2); //Flip the velocity and cut it in half.
		if (this->getVY() > 0) //If the y velocity wasn't moving downward.
			this->setVY(this->getVY() * -1 / 2);
		else
			this->setVY(0); //Stop y velocity completely
	}
	//Death Animation.
	return isDelete;
}