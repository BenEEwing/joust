#include "stdafx.h"
#include "Enemy.h"
#include <string>


Enemy::Enemy(double x1, double y1, double l1, double w1, int type1, int speed, std::string sprite1,int n)
: GameObject(x1, y1, l1, w1, type1, speed, sprite1)
{
	rank = n;
	setStats();
}


Enemy::~Enemy()
{
}


void Enemy::setRank(int c)
{
	rank = c;
}


int Enemy::getRank()
{
	return rank;
}


void Enemy::setStats()
{
	switch (rank) //Parameters after this line are currently placeholders
	{
	case 0: //Enemy Name: Lava 
		setSprite("Lava.png"); 
		setL(1);
		setW(1);
		setMaxSpeed(0);
		break;
	case 1: //Enemy Name: Bounder
		setSprite("Bounder.png"); 
		setL(5);
		setW(5);
		setMaxSpeed(1);
		break;
	case 2: //Enemy Name: Hunter Egg
		setSprite("HunterEgg.png");
		setL(1);
		setW(1);
		setMaxSpeed(2);
		break;
	case 3: //Enemy Name: Hunter
		setSprite("Hunter.png");
		setL(1);
		setW(1);
		setMaxSpeed(3);
		break;
	case 4: //Enemy Name: ShadowEgg
		setSprite("ShadowEgg.png");
		setL(1);
		setW(1);
		setMaxSpeed(4);
		break;
	case 5: //Enemy Name: ShadowHunter
		setSprite("ShadowHunter.png");
		setL(1);
		setW(1);
		setMaxSpeed(2);
		break;
	case 6: //Enemy Name: Pterodactyl
		setSprite("Pterodactyl.png");
		setL(1);
		setW(1);
		setMaxSpeed(2);
		break;
	case 7: //Enemy Name: Lava Troll
		setSprite("LavaTroll.png");
		setL(1);
		setW(1);
		setMaxSpeed(2);
		break;
	}
}


bool Enemy::collison(bool die)
{
	bool isDelete = false; //Decide if the object should be deleted from the array in StateManager
	if (die)
	{
		if (rank % 2 != 0) //Check if it's odd, because all the eggs are even
		{
			if (rank < 5) //Check to make sure it's a basic enemy and not a ShadowHunter
				rank++; //Increase the rank to switch it into an egg
			else
				rank = 4;
		}
		else
			isDelete = true;
	}
	else
	{
		this->setVX(this->getVX() * -1 / 2); //Flip the velocity and cut it in half.
		if (this->getVY() < 0) //If the y velocity wasn't moving downward.
			this->setVY(this->getVY() * -1 / 2);
		else
			this->setVY(0); //Stop y velocity completely
	}
	//Death animation.
	return isDelete;
}