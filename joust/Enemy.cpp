#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(int n)
{
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
	}
}