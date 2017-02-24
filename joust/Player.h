#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	Player(); //Think about constructor and if it needs any input.
	~Player();
	int getScore(); // Set/Get done.
	int getLives();
	void setScore(int);
	void setLives(int);
private:
	int score;
	int lives; 
};

