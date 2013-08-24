// Render Class
//
// Renders all game elements

#ifndef RENDER_H
#define RENDER_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include "game.h"

class Render
{
	unsigned int width, height;
	int x, y;
	ALLEGRO_BITMAP *cursor, *gamebg;
public:
	Render();
	~Render();
	
	void load_ingame(const Game* engine);
	void draw_ingame(const Game* engine, ALLEGRO_DISPLAY **display);
}; // class render

#endif
