#include "stdafx.h"
#include "Enemy.h"
#include <string>


Enemy::Enemy(double x1, double y1, double l1, double w1, int type1, std::string sprite1,int n)
: GameObject::GameObject(x1, y1, l1, w1, type1, sprite1)
{
	rank = n;
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
		setL(1);
		setW(1);
		setMaxSpeed(1);
		break;
	case 2: //Enemy Name: Hunter
		setSprite("Hunter.png");
		setL(1);
		setW(1);
		setMaxSpeed(2);
		break;
	case 3: //Enemy Name: Shadow Lord
		setSprite("ShadowLord.png");
		setL(1);
		setW(1);
		setMaxSpeed(3);
		break;
	case 4: //Enemy Name: Pterodactyl
		setSprite("Pterodactyl.png");
		setL(1);
		setW(1);
		setMaxSpeed(4);
		break;
	case 5: //Enemy Name: Lava Troll
		setSprite("LavaTroll.png");
		setL(1);
		setW(1);
		setMaxSpeed(2);
		break;
	case 6: //Enemy Name: Egg
		setSprite("Egg.png");
		setL(1);
		setW(1);
		setMaxSpeed(2);
		break;
	}
}