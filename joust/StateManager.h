#pragma once
#include <vector>
#include "GameObject.h"
#include <SFML/Graphics.hpp>
class StateManager
{
public:
	StateManager();
	void applyV(); //Calculates new x,y for objects based on their current vx,vy.
	void drawWin(); //Draws the window based on the newest frame.
	void manageWin(); //Manages any changes that need to happen to the window.
	void collisionCheck(); //Checks the entirety of the window to determine if there are any collisions happening.
	void manageKey(key); //Manages all inputs from the user, not sure on what it takes right now **LOOK UP KEY INPUTS WITH SFML**
	void run(); //The continuous loop that will be the game.

	~StateManager();
private:
	window gameWindow; //Sfml window
	std::vector <GameObject> //Vector with all the different objects that are on the screen at the time.
};

