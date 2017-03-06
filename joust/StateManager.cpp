#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"


StateManager::StateManager(sf::Window c)
{
	gameWindow = c;
	col.push_back(new Player(0.0, 0.0, 5, 5, 1, "Player.png")); //Make player at position 0.
}


StateManager::~StateManager()
{
	for (int i = col.size()-1; i >= 0; i--) //Delete all the Game objects.
	{
		delete col.at(i);
		col.pop_back();
	}
}

//Need a tick function.
void StateManager::run()
{
	bool exit = false;
	while (!exit)
	{

		updateGame();
		if (col.at(0) = NULL)
			exit = true;
	}
}

//Currently in very primitive state. No gravity, only takes x/y and adds VX/VY to it.
void StateManager::applyV()
{
	for (int i = 0; i < col.size(); i++)
	{
		col.at(i)->setX(col.at(i)->getX() + col.at(i)->getVX());
		col.at(i)->setY(col.at(i)->getY() + col.at(i)->getVY());
	}
}

//Going to print out all the objects into the window.
void StateManager::drawWin()
{

}

//Manages any changes that need to happen with the window. Not sure purpose right now.
void StateManager::manageWin()
{

}

//Check quadrants of the window, narrow in on where he collision may be.
void StateManager::collisionCheck()
{
	//Check for the collision, call collision for the objects and delete the ones that need to be deleted.
}

//Change Velocity based on key press/Pause menu.
void StateManager::manageKey(sf::Keyboard::Key x)
{

}

//Adds the new gameobject to the back of the vector.
void StateManager::addObj(GameObject* x)
{
	col.push_back(x);
}

//To make it cleaner in run. Will call all the functions that happen every tick.
void StateManager::updateGame()
{
	//Functions
}