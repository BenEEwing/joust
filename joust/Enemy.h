#pragma once
#include "GameObject.h"
class Enemy :
	public GameObject
{
public:
	Enemy();
	~Enemy();
	void setRank(int);
	int getRank();
	void getStats(); //Change all stats in GameObject based on the rank of the enemy.
private:
	int rank; //Used to distinguish the different types of enemies.
};

