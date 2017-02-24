#include "stdafx.h"
#include "Player.h"


Player::Player()
{
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