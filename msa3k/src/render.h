// Render Class
//
// Renders all game elements

#ifndef RENDER_H
#define RENDER_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <cstdio>

#include "constants.h"
//#include "game.h"
#include "input.h"

int resolve_load(ALLEGRO_BITMAP **image, const char *path_str,
	const char *filename);

class Render
{
private:
	unsigned int width, height;
	int x, y;
	ALLEGRO_BITMAP *cursor, *gamebg, *title;
	ALLEGRO_DISPLAY **display;

public:
	Render(ALLEGRO_DISPLAY **display);
	~Render();
	
	void load_ingame();
	void draw_title();
	void draw_ingame(const Input *inputs);
}; // class render

#endif
