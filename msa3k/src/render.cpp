#include "render.h"



Render::Render(ALLEGRO_DISPLAY **display): x(0), y(0), display(display)
{
// Get path relative to exe
	ALLEGRO_PATH *exe_path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	int error_exists = 0;

	error_exists += resolve_load(&gamebg, &exe_path, "resources/pic.png");
	error_exists += resolve_load(&cursor, &exe_path, "resources/cursor.png");
	error_exists += resolve_load(&title, &exe_path, "resources/title.png");

	al_destroy_path(exe_path);

	if(error_exists)
		abort_game("Could not find all the graphical resources!");
} // Render()



Render::~Render()
{
} // ~Render()



void Render::load_ingame()
{
} // load_ingame()



void Render::draw_title()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(title, 0, 0, 0);
	al_flip_display();
} // draw_title()



void Render::draw_ingame(const Input *inputs)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));

	// move demo
	/*
	if(engine->inputs.up)
		y += 10;
	if(engine->inputs.down)
		y -= 10;
	*/
	if(inputs->right)
		x -= 5;
	if(inputs->left)
		x += 5;
	/*al_draw_scaled_bitmap(gamebg, 0, 0, (float)width, (float)height,
		x, y, (float)width * 8, (float)height * 8, 0);
	*/

	if(x < -(int)width)
		x = 0;
	else
		x -= 1;

	width = al_get_bitmap_width(gamebg);
	height = al_get_bitmap_height(gamebg);
	al_draw_bitmap(gamebg, x, (GAME_HEIGHT - height)/2, 0);
	al_draw_bitmap(gamebg, x + width, (GAME_HEIGHT - height)/2, 0);

	// Draw Cursor
	al_draw_bitmap(cursor, inputs->aim_x - 110, inputs->aim_y - 10, 0);

	al_flip_display();
} // draw_ingame()

