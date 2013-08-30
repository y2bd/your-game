// Game Class
//
// Handles game logic


#ifndef GAME_H
#define GAME_H

#include <allegro5/allegro5.h>
#include <iostream>

#include "input.h"
#include "gamedata.h"

using namespace std;

class Game
{
	Gamedata gamedata;
	
public:
	Input inputs;

	Game();
	void update();

	friend class Render;
};

#endif
