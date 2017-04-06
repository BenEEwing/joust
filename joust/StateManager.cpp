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
using namespace std;

StateManager::StateManager()
{
	col.push_back(new Player(102, 102, 5, 5, 5, 10, "player.png")); //Make player at position 0.
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
	int level = 0;
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
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					manageKey(sf::Keyboard::Key::Space);
			}
			updateGame(level); //Call to doing every game thing.
			frame++; //Increase frames since the clock is constantly growing.
			level++;
		}
	}
}

//Currently in very primitive state. Attempted gravity and slowing down, need to check on math and stuff.
void StateManager::applyVelocity()
{	
	for (int i = 0; i < col.size(); i++) //Change the velocities to compensate for gravity/slowing down.
	{
		if (col.at(i)->getType() !=0)
		{
			if (col.at(i)->getVY() < 5 && col.at(i)->getVY() != 0) //Going to be an if to see if it's going up.
				col.at(i)->setVY(col.at(i)->getVY() + 0.2); //Need to test to see what number actually makes sense here for gravity.
			else if (col.at(i)->getVY() != 0)
				col.at(i)->setVY(5);
			if (col.at(i)->getVX() > 0 && col.at(i)->getVX() - 0.2 > 0)
				col.at(i)->setVX(col.at(i)->getVX() - 0.2); //Natural slowing down, seems bad right now, not sure on the math for this stuff.
			else if (col.at(i)->getVX() < 0 && col.at(i)->getVX() + 0.2 < 0)
				col.at(i)->setVX(col.at(i)->getVX() + 0.2);
			else
				col.at(i)->setVX(0);
		}
	}
	for (int i = 0; i < col.size(); i++) //Apply the current velcoities.
	{
		if (col.at(i)->getX() + col.at(i)->getVX() < 815 && col.at(i)->getX() + col.at(i)->getVX() > -10) //Check to see if it's at a horizontal edge
			col.at(i)->setX(col.at(i)->getX() + col.at(i)->getVX()); //If it's not then apply velcoites as normal
		else if (col.at(i)->getX() + col.at(i)->getVX() < 815) //If it's on the left edge set it to the right edge
		{
			col.at(i)->setX(815);
		}
		else
		{
			col.at(i)->setX(-10); //Otherwise set it to the left edge
		}
		if (col.at(i)->getY() + col.at(i)->getVY() < 500 && col.at(i)->getY() + col.at(i)->getVY() > 0)
			col.at(i)->setY(col.at(i)->getY() + col.at(i)->getVY());
		else if (col.at(i)->getY() + col.at(i)->getVY() < 500)
		{
			col.at(i)->setY(6);
			col.at(i)->setVY(1);
		}
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

//Gonna put all the objects we need into the array for each level.
void StateManager::levelGen(int level)
{
	if (level == 0)
	{
		addObj(new GameObject(100, 500, 50, 50, 0, 0, "plat5.png"));
		addObj(new Enemy(500, 500, 10, 5, 2, 0, "Bounder.png",1));
	}
}

//Change Velocity based on key press/Pause menu.
void StateManager::manageKey(sf::Keyboard::Key input)
{
	std::cout << input << std::endl;
	switch (input)
	{
	case sf::Keyboard::Key::Space:
		if (col.at(0)->getVY() - 1 < -2)
			col.at(0)->setVY(col.at(0)->getVY() - 1);
		else
			col.at(0)->setVY(-2);
		break;
	case sf::Keyboard::Key::Left:
		if (col.at(0)->getVX() - 0.5 > col.at(0)->getMaxSpeed() * -1)
			col.at(0)->setVX(col.at(0)->getVX() - 0.5);
		else
			col.at(0)->setVX(col.at(0)->getMaxSpeed() * -1);
		break;
	case sf::Keyboard::Key::Right:
		if (col.at(0)->getVX() + 0.5 < col.at(0)->getMaxSpeed())
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
void StateManager::updateGame(int level)
{	
	levelGen(level);
	collisionCheck();	
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


void StateManager::collisionCheck()
{
	for (int i = 0; i < col.size(); i++)
	{
		for (int c = 0; c < col.size(); c++)
		{
			if (col.at(c)->getY() + col.at(c)->getL() < col.at(i)->getY() || col.at(i)->getY() + col.at(i)->getL() < col.at(c)->getY() || col.at(c)->getX() + col.at(c)->getW() < col.at(i)->getX() || col.at(i)->getX() + col.at(i)->getW() < col.at(c)->getX() || i == c)
				cout << "No Collision!" << endl;
			else
			{
				cout << "Collision!!!" << endl;
				if (col.at(c)->getY() <= col.at(i)->getY() + col.at(i)->getL())
				{					
					col.at(c)->collision(false, col.at(i)->getX(), col.at(c)->getY());
					if (col.at(i)->collision(true, col.at(c)->getX(), col.at(i)->getY()) && !dynamic_cast<Player*>(col.at(c)))
						col.erase(col.begin() + c);
					else if (col.at(i)->collision(true, col.at(c)->getX(), col.at(i)->getY()))
					{
						//End the game?????
					}
				}
				else if (col.at(i)->getX() <= col.at(c)->getX() + col.at(c)->getW() / 2 && col.at(i)->getY() <= col.at(c)->getY() + col.at(c)->getL() / 2) //If it's above it and to the left
				{					
					col.at(i)->collision(false, col.at(c)->getX(), col.at(c)->getY());
					if (col.at(c)->collision(true, col.at(c)->getX(), col.at(c)->getY()) && !dynamic_cast<Player*>(col.at(c)))
						col.erase(col.begin() + c);
					else if (col.at(c)->collision(true, col.at(c)->getX(), col.at(c)->getY()))
					{
						//End the game?????
					}
				}
				else if (col.at(i)->getX() <= col.at(c)->getX() + col.at(c)->getW() / 2) //If it's just to the left
				{					
					col.at(c)->collision(false, col.at(c)->getX(), col.at(i)->getY() + col.at(i)->getL());
					if (col.at(i)->collision(true, col.at(c)->getX(), col.at(i)->getY() + col.at(i)->getL()) && !dynamic_cast<Player*>(col.at(i)))
						col.erase(col.begin() + i);
					else if (col.at(i)->collision(true, col.at(c)->getX(), col.at(i)->getY() + col.at(i)->getL()))
					{
						//End the game?????
					}
				}
				else if (col.at(i)->getX() + col.at(i)->getW() / 2 >= col.at(c)->getX() && col.at(i)->getY() <= col.at(c)->getY() + col.at(c)->getL() / 2) //If it's to the right and above
				{					
					col.at(i)->collision(false, col.at(c)->getX() + col.at(c)->getW(), col.at(c)->getY());
					if (col.at(c)->collision(true, col.at(c)->getX() + col.at(c)->getW(), col.at(c)->getY()) && !dynamic_cast<Player*>(col.at(c)))
						col.erase(col.begin() + c);
					else if (col.at(c)->collision(true, col.at(c)->getX() + col.at(c)->getW(), col.at(c)->getY()))
					{
						//End the game?????
					}
				}
				else if (col.at(i)->getX() + col.at(i)->getW() / 2 >= col.at(c)->getX()) // If it's to the right
				{					
					col.at(c)->collision(false, col.at(c)->getX() + col.at(c)->getW(), col.at(i)->getY() + col.at(i)->getL());
					if (col.at(i)->collision(true, col.at(c)->getX() + col.at(c)->getW(), col.at(i)->getY() + col.at(i)->getL()) && !dynamic_cast<Player*>(col.at(i)))
						col.erase(col.begin() + i);
					else if (col.at(i)->collision(true, col.at(c)->getX() + col.at(c)->getW(), col.at(i)->getY() + col.at(i)->getL()))
					{
						//End the game?????
					}
				}
			}
		}
	}
}