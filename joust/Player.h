#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	Player();
	~Player();
	int getScore();
	int getLives();
	void setScore(int);
	void setLives(int);
private:
	int score;
	int lives; 
};

