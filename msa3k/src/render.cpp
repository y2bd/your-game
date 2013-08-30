#include "render.h"

int resolve_load(ALLEGRO_BITMAP **image, const char *path_str,
	const char *filename)
{
	char proper_path[512];
	sprintf(proper_path, "%s%s", path_str, filename);
	
	if(!(*image = al_load_bitmap(proper_path)))
	{
		fprintf(stderr, "Render Error %s not found!\n", filename);
		return 0;
	} // if image load failed (NULL)

	return 1;
} // resolve_load()



Render::Render(ALLEGRO_DISPLAY **display): x(0), y(0), display(display)
{
// Get path relative to exe
	ALLEGRO_PATH *path;
	const char *path_str;
	int error_exists = 0;

	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	path_str = (path) ? al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP) : "<none>";

	error_exists += resolve_load(&gamebg, path_str, "resources/pic.png");
	error_exists += resolve_load(&cursor, path_str, "resources/cursor.png");
	error_exists += resolve_load(&title, path_str, "resources/title.png");

	//if(error)

	al_destroy_path(path);
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

