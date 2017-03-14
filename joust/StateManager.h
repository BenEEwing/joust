#pragma once
#include <vector>
#include "GameObject.h"
#include <SFML/Graphics.hpp>
class StateManager
{
public:
	StateManager();
	void applyVelocity(); //Calculates new x,y for objects based on their current vx,vy / Also calculates gravity and slowing.
	void drawWindow(); //Draws the window based on the newest frame.
	void manageWindow(); //Manages any changes that need to happen to the window.
	void collisionCheck(); //Checks the entirety of the window to determine if there are any collisions happening.
	void manageKey(sf::Keyboard::Key); //Manages all inputs from the user, not sure on what it takes right now **LOOK UP KEY INPUTS WITH SFML**
	void run(); //The continuous loop that will be the game.
	void addObj(GameObject*); //Add a game object to the vector.
	void updateGame(); //Will run all the functions for updating the game.

	~StateManager();
private:
	sf::RenderWindow gameWindow; //Sfml window
	std::vector <GameObject*> col; //Vector with all the different objects that are on the screen at the time.
};

