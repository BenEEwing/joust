#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	Player(double, double, double, double, int, int, std::string); //Think about constructor and if it needs any input.
	~Player();
	int getScore(); 
	int getLives();
	void setScore(int);
	void setLives(int);
	virtual bool collision(double, double, bool); //Virtual so it can have access to lives.
private:
	int score;
	int lives; 
};

