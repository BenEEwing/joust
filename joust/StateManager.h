#pragma once
#include <vector>
#include "GameObject.h"
class StateManager
{
public:
	StateManager();
	void applyV();
	void drawWin();
	void manageWin();
	void collisionCheck();
	void manageKey(key);
	void run();

	~StateManager();
private:
	Window gameWindow;
	std::vector <GameObject>
};

