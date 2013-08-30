#include "helper.h"



int resolve_load(ALLEGRO_BITMAP **image, ALLEGRO_PATH **exe_path,
	const char *filename)
{
	const char *proper_path;

	al_append_path_component(*exe_path, filename);

	if(*exe_path)
		proper_path = al_path_cstr(*exe_path, ALLEGRO_NATIVE_PATH_SEP);

	if(!proper_path || !(*image = al_load_bitmap(proper_path))) 
	{
		fprintf(stderr, "[Render Error] %s not found!\n", proper_path);
		abort_game("[Render Error]", "Cannot start without resource!\n");
		return 0;
	} // if image load failed (NULL)

	return 1;
} // resolve_load(image)



int resolve_load(ALLEGRO_SAMPLE **sample, ALLEGRO_PATH **exe_path,
	const char *filename)
{
	/*char *proper_path;
	int len_prefix = strlen(path_prefix) + 1;
	int len_filename = strlen(filename) + 1;

	proper_path = (char*)malloc((len_prefix + len_filename) * sizeof(char));
	sprintf(proper_path, "%s%s", path_prefix, filename);
	
	if(!(*image = al_load_bitmap(proper_path))) 
	{
		fprintf(stderr, "[Render Error] %s%s not found!\n", path_prefix, filename);
		free(proper_path);
		return 0;
	} // if image load failed (NULL)

	free (proper_path);
*/
	return 0;
} // resolve_load(sample)



void abort_game(const char *error_type, const char *message)
{
	fprintf(stderr, "%s %s\nAborting...\n", error_type, message);
	exit(1);
	// quick_exit();
} // abort_game()

