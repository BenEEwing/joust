#include "stdafx.h"
#include "GameObject.h"
#include <string>


GameObject::GameObject(double x1, double y1, double l1, double w1, int type1, int speed, std::string sprite1)
{
	x = x1;
	y = y1;
	l = l1;
	w = w1;
	type = type1;
	sprite = sprite1;
	vx = 0;
	vy = 0;
	setMaxSpeed(speed);
}


GameObject::~GameObject()
{
}


void GameObject::setX(double c)
{
	x = c;
}


void GameObject::setY(double c)
{
	y = c;
}


void GameObject::setVX(double c)
{
	vx = c;
}


void GameObject::setVY(double c)
{
	vy = c;
}


void GameObject::setL(double c)
{
	l = c;
}


void GameObject::setW(double c)
{
	w = c;
}


void GameObject::setType(int c)
{
	type = c;
}


void GameObject::setSprite(std::string c)
{
	sprite = c;
}


std::string GameObject::getSprite()
{
	return sprite;
}


double GameObject::getL()
{
	return l;
}


double GameObject::getW()
{
	return w;
}


double GameObject::getVX()
{
	return vx;
}


double GameObject::getVY()
{
	return vy;
}


double GameObject::getX()
{
	return x;
}


double GameObject::getY()
{
	return y;
}


int GameObject::getType()
{
	return type;
}


void GameObject::setMaxSpeed(int speed)
{
	maxSpeed = speed;
}


int GameObject::getMaxSpeed()
{
	return maxSpeed;
}

bool GameObject::collision(double colx, double coly, bool die)
{
	return false;
}


void GameObject::changeDirection(bool x)
{
	direction = x;
}


bool GameObject::getDirection()
{
	return direction;
}