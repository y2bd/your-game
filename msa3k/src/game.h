// Game Class
//
// Handles game logic


#ifndef GAME_H
#define GAME_H

#include <allegro5/allegro5.h>
#include <iostream>

#include "input.h"
#include "gamedata.h"
#include "render.h"
#include "audio.h"

using namespace std;

enum States
{
	TITLE_SCREEN,
	PLATFORM_SCREEN
}; // enum States

class Game
{
	Gamedata gamedata;
	int gamestate_mode;
	Audio *audio_manager;
	Render *render_manager;
	
public:
	Input inputs;

	Game(Audio *audio, Render *render);
	void update();
	void draw();

};

#endif
