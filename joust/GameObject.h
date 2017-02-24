#pragma once
#include <string>
class GameObject
{
public:
	GameObject();
	~GameObject();
	void setX(double);
	void setY(double);
	void setVX(double);
	void setVY(double);
	void setL(double);
	void setW(double);
	void setType(int);
	void setSprite(std::string);
	double getX();
	double getY();
	double getVX();
	double getVY();
	double getL();
	double getW();
	int getType();
	std::string getSprite();
	void collision(double, double); //Resolve a collision given the x,y of the collision.
private:
	double x, y; //Position in the window.
	double vx, vy; //Velocity.
	double l, w; //Length and width for the object.
	int type; //Used to determine if it's either neutral, friendly or an enemy for collisions.
	std::string sprite; //File name for the sprite.
};

