#include "render.h"

Render::Render(): x(0), y(0)
{
}


Render::~Render()
{
}


void Render::load_ingame(const Game* engine)
{
	// Get path relative to exe
	ALLEGRO_PATH *path;
	const char *path_str;
	char proper_path[128];

	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	path_str = (path) ? al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP) : "<none>";

	// Load images
	sprintf(proper_path,"%sresources/pic.png", path_str);

	if(!(gamebg = al_load_bitmap(proper_path)))
		fprintf(stderr, "[Render Error] resources/pic.png not found\n");


	/*
	cursor = al_load_bitmap("./sprites/ingameelements/crosshairs/0.png");
		engine->gamestate.currentMap->fetch_map_dimensions(&width, &height);
	*/

	al_destroy_path(path);
} // load_ingame()


void Render::draw_ingame(const Game* engine, ALLEGRO_DISPLAY **display)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));

	// draw map
	/* move demo
	if(engine->inputs.up)
		y += 10;
	if(engine->inputs.down)
		y -= 10;
	if(engine->inputs.right)
		x -= 10;
	if(engine->inputs.left)
		x += 10;
	al_draw_scaled_bitmap(gamebg, 0, 0, (float)width, (float)height,
		x, y, (float)width * 8, (float)height * 8, 0);
	al_draw_bitmap(cursor, engine->inputs.aim_x - 10,
		engine->inputs.aim_y - 10, 0);
*/
	width = al_get_bitmap_width(gamebg);
	height = al_get_bitmap_height(gamebg);
	al_draw_bitmap(gamebg, x, (GAME_HEIGHT - height)/2, 0);
	al_draw_bitmap(gamebg, x + width, (GAME_HEIGHT - height)/2, 0);

	if(x == -(int)width)
		x = 0;
	else
		x--;
	al_flip_display();
} // draw_ingame()

