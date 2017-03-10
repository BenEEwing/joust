// joust.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StateManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	sf::Window win;
	StateManager state(win);
	system("pause");
	return 0;
}

