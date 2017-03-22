#pragma once
#include <string>
class GameObject
{
public:
	GameObject(double, double, double, double, int, int, std::string);
	~GameObject();
	void setX(double);
	void setY(double);
	void setVX(double);
	void setVY(double);
	void setL(double);
	void setW(double);
	void setType(int);
	void setSprite(std::string);
	void setMaxSpeed(int);
	double getX();
	double getY();
	double getVX();
	double getVY();
	double getL();
	double getW();
	int getType(); 
	int getMaxSpeed();
	std::string getSprite();
	virtual bool collision(double, double, bool); //Resolve a collision given the x,y of the collision, virtual for player and enemy.
private:
	double x, y; //Position in the window.
	double vx, vy; //Velocity.
	double l, w; //Length and width for the object.
	int type; //Used to determine if it's either neutral, friendly or an enemy for collisions (0,1,2).
	int maxSpeed;
	std::string sprite; //File name for the sprite.
};

