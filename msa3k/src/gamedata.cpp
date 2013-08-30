#include "gamedata.h"
#include <cstdlib>
#include <cstdio> // debug
#include <cstring>


Gamedata::Gamedata()
{
} // Gamedata()



Gamedata::~Gamedata()
{
} // ~Gamedata()



void Gamedata::load_map(const char *filename)
{
	FILE *fp;
	char dimensions[32];
	char *temp;

	// get path relative to exe
	ALLEGRO_PATH *path;
	const char *path_str;
	char proper_path[128];

	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	path_str = (path) ? al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP) : "<none>";

	sprintf(proper_path, "%sresources/new.txt", path_str);

	if(!(fp = fopen(proper_path, "rb")))
	{
		fprintf(stderr, "[Gamedata Error] Could not find resources/new.txt.\n");
		return;
	} // if can't open file

	printf("File Found!\n");
	

	fgets(dimensions, 32, fp);
	temp = strtok(dimensions, ",\n\r");
	x = atoi(temp);
	temp = strtok(NULL, ",\n\r");
	y = atoi(temp);

	printf("x: %d y: %d\n", x, y);

	//ground = new 

	al_destroy_path(path);
} // load_map()



void Gamedata::update()
{
} // update()
