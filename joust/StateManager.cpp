#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;

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

//Game loop with tick function limiting it to 20fps, could be modified but 20 seems easy.
void StateManager::run()
{
	high_resolution_clock::time_point first = high_resolution_clock::now(); //Original time.
	bool exit = false;
	int frame = 0; //Number of frames that have passed.
	while (!exit)
	{
		if (col.at(0) == NULL)
			exit = true;
		high_resolution_clock::time_point current = high_resolution_clock::now(); //Current time.
		double elapsed = duration_cast<duration<double>>(current - first).count(); //Cast it as a double.
		if (frame * 0.05 < elapsed) //If it has been a 5th of a second basically.
		{
			updateGame(); //Call to doing every game thing.
			frame++; //Increase frames since the clock is constantly growing.
		}
	}
}

//Currently in very primitive state. No gravity, only takes x/y and adds VX/VY to it.
void StateManager::applyV()
{
	for (int i = 0; i < col.size(); i++) //Apply the current velcoities.
	{
		col.at(i)->setX(col.at(i)->getX() + col.at(i)->getVX());
		col.at(i)->setY(col.at(i)->getY() + col.at(i)->getVY());
	}
	for (int i = 0; i < col.size(); i++) //Change the velocities to compensate for gravity/slowing down.
	{
		if (col.at(i)->getVY()) //Going to be an if to see if it's going up.
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
	applyV();
	//Functions
}