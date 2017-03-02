#pragma once
#include "GameObject.h"
#include <string>
class Enemy :
	public GameObject
{
public:
	Enemy(double, double, double, double, int, std::string, int);
	~Enemy();
	void setRank(int);
	int getRank();
	void setStats(); //Change all stats in GameObject based on the rank of the enemy.
private:
	int rank; //Used to distinguish the different types of enemies. 
			  //Lava = 0, Bounder = 1, Hunter is 2, Shadow Lord is 3, Pterodactyl is 4, Lava Troll is 5
};

