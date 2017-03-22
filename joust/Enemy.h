#pragma once
#include "GameObject.h"
#include <string>
class Enemy :
	public GameObject
{
public:
	Enemy(double, double, double, double, int, int, std::string, int);
	~Enemy();
	void setRank(int);
	int getRank();
	void setStats(); //Change all stats in GameObject based on the rank of the enemy.
	virtual bool collison(double, double, bool);
private:
	int rank; //Used to distinguish the different types of enemies. 
			  //Lava = 0, Bounder = 1, Hunter egg is 2, Hunter is 3, Shadow Egg is 4
			  //Shadow Lord is 5, Pterodactyl is 6, Lava Troll is 7
};

