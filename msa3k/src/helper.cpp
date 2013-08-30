#include "helper.h"



int resolve_load(ALLEGRO_BITMAP **image, ALLEGRO_PATH **exe_path,
	const char *filename)
{
	const char *proper_path;

	al_set_path_filename(*exe_path, filename);

	if(*exe_path)
		proper_path = al_path_cstr(*exe_path, ALLEGRO_NATIVE_PATH_SEP);
	
	if(!(*image = al_load_bitmap(proper_path))) 
	{
		fprintf(stderr, "[Render Error] %s not found!\n", proper_path);
		return 1;
	} // if image load failed (NULL)

	return 0;
} // resolve_load(image)



int resolve_load(ALLEGRO_SAMPLE **sample, ALLEGRO_PATH **exe_path,
	const char *filename)
{
	const char *proper_path;

	al_set_path_filename(*exe_path, filename);

	if(*exe_path)
		proper_path = al_path_cstr(*exe_path, ALLEGRO_NATIVE_PATH_SEP);
	
	if(!(*sample = al_load_sample(proper_path))) 
	{
		fprintf(stderr, "[Audio Error] %s not found!\n", proper_path);
		return 1;
	} // if sample load failed (NULL)

	return 0;
} // resolve_load(sample)



void abort_game(const char *message)
{
	fprintf(stderr, "[SEVERE] %s\nAborting...\n", message);
	exit(1);
	// quick_exit();
} // abort_game()
