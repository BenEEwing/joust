#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StateManager.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;


StateManager::StateManager()
{
	col.push_back(new Player(50, 50, 5, 5, 5, "player.png")); //Make player at position 0.
	sf::RenderWindow window(sf::VideoMode(800, 600), "Joust");
	sf::RenderWindow * windowptr = &window;
	gameWindow = windowptr;
	run();
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
		sf::Event event;

		if (col.at(0) == NULL)
			exit = true;
		high_resolution_clock::time_point current = high_resolution_clock::now(); //Current time.
		double elapsed = duration_cast<duration<double>>(current - first).count(); //Cast it as a double.
		if (frame * 0.05 < elapsed) //If it has been a 5th of a second basically.
		{
			while (gameWindow->pollEvent(event))
			{
				// check the type of the event...
				if (event.type == sf::Event::Closed)
					gameWindow->close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					manageKey(sf::Keyboard::Key::Left);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					manageKey(sf::Keyboard::Key::Right);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					manageKey(sf::Keyboard::Key::Up);
			}
			updateGame(); //Call to doing every game thing.
			frame++; //Increase frames since the clock is constantly growing.
		}
	}
}

//Currently in very primitive state. Attempted gravity and slowing down, need to check on math and stuff.
void StateManager::applyVelocity()
{	
	for (int i = 0; i < col.size(); i++) //Change the velocities to compensate for gravity/slowing down.
	{
		if (col.at(i)->getVY() < 5) //Going to be an if to see if it's going up.
			col.at(i)->setVY(col.at(i)->getVY() + 0.2); //Need to test to see what number actually makes sense here for gravity.
		else
			col.at(i)->setVY(5);
		if (col.at(i)->getVX() > 0 && col.at(i)->getVX() + 0.2 > 0)
			col.at(i)->setVX(col.at(i)->getVX() + 0.2); //Natural slowing down, seems bad right now, not sure on the math for this stuff.
		else if (col.at(i)->getVX() < 0 && col.at(i)->getVX() - 0.2 < 0)
			col.at(i)->setVX(col.at(i)->getVX() - 0.2);
		else
			col.at(i)->setVX(0);
	}
	for (int i = 0; i < col.size(); i++) //Apply the current velcoities.
	{
		if (col.at(i)->getX() + col.at(i)->getVX() < 700 && col.at(i)->getX() + col.at(i)->getVX() > 0)
			col.at(i)->setX(col.at(i)->getX() + col.at(i)->getVX());
		else if (col.at(i)->getX() + col.at(i)->getVX() < 700)
		{
			col.at(i)->setX(700);
		}
		else
		{
			col.at(i)->setX(0);
			col.at(i)->setVX(0);
		}
		if (col.at(i)->getY() + col.at(i)->getVY() < 500 && col.at(i)->getY() + col.at(i)->getVY() > 0)
			col.at(i)->setY(col.at(i)->getY() + col.at(i)->getVY());
		else if (col.at(i)->getY() + col.at(i)->getVY() < 500)
			col.at(i)->setY(6);
		else
		{
			col.at(i)->setY(500);
			col.at(i)->setVY(0);
		}
	}

}

//Going to print out all the objects into the window.
void StateManager::drawWindow()
{
	sf::Texture pTexture;
	sf::Sprite pSprite;
	gameWindow->clear();
	for (int i = 0; i < col.size(); i++)
	{
		pTexture.loadFromFile(col.at(i)->getSprite());
		pSprite.setTexture(pTexture);		
		pSprite.setPosition(col.at(i)->getX(), col.at(i)->getY());

		gameWindow->draw(pSprite);
		std::cout << "x: " << col.at(i)->getX() << "y: " << col.at(i)->getY() << std::endl;
	}
	gameWindow->display();
}

//Manages any changes that need to happen with the window. Not sure purpose right now.
void StateManager::manageWindow()
{
	
}

//Check quadrants of the window, narrow in on where he collision may be.
void StateManager::collisionCheck()
{
	//Check for the collision, call collision for the objects and delete the ones that need to be deleted.
}

//Change Velocity based on key press/Pause menu.
void StateManager::manageKey(sf::Keyboard::Key input)
{
	std::cout << input << std::endl;
	switch (input)
	{
	case sf::Keyboard::Key::Up:
	case sf::Keyboard::Key::W:
		if (col.at(0)->getVY() - 0.5 < col.at(0)->getMaxSpeed() * -1)
			col.at(0)->setVY(col.at(0)->getVY() - 0.5);
		else
			col.at(0)->setVY(col.at(0)->getMaxSpeed() * -1);
		break;
	case sf::Keyboard::Key::Right:
	case  sf::Keyboard::Key::D:
		if (col.at(0)->getVX() - 0.5 < col.at(0)->getMaxSpeed() * -1)
			col.at(0)->setVX(col.at(0)->getVX() - 0.5);
		else
			col.at(0)->setVX(col.at(0)->getMaxSpeed() * -1);
		break;
	case sf::Keyboard::Key::Left:
	case  sf::Keyboard::Key::A:
		if (col.at(0)->getVX() + 0.5 > col.at(0)->getMaxSpeed())
			col.at(0)->setVX(col.at(0)->getVX() + 0.5);
		else
			col.at(0)->setVX(col.at(0)->getMaxSpeed());
		break;
	}
}

//Adds the new gameobject to the back of the vector.
void StateManager::addObj(GameObject* x)
{
	col.push_back(x);
}

//To make it cleaner in run. Will call all the functions that happen every tick.
void StateManager::updateGame()
{
	applyVelocity();
	drawWindow();
	//Functions
}

void StateManager::playSoundFile(std::string filename)
{
	sf::SoundBuffer buffer;
	sf::Sound sound;

	std::string temp = "joust_sounds\\joust_" + filename + ".ogg";

	buffer.loadFromFile(temp);
	sound.setBuffer(buffer);
	sound.play();
}