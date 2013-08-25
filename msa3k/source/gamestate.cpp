#include "gamestate.h"
#include <cstdlib>
#include <cstdio> // debug
#include <cstring>


Gamestate::Gamestate()
{
} // Gamestate()



Gamestate::~Gamestate()
{
} // ~Gamestate()



void Gamestate::load_map(const char *filename)
{
	FILE *fp;
	char dimensions[32];
	char *cp;

	char *env, *line, back[128], path[128];
	env = getenv("_"); // get executable's path. Specific to Linux
	strcpy(back, env);
	line= strrchr(back, '/');
	line[1] = '\0';
	sprintf(path,"%sresources/%s", back, filename);
	printf("looky :%s\n", path);

	if(!(fp = fopen(path, "rb")))
	{
		fprintf(stderr, "[Map Error] Count not find and open file.\n");
		return;
	} // if can't open file

	printf("File Found!\n");
	

	fgets(dimensions, 32, fp);
	cp = strtok(dimensions, ",\n\r");
	x = atoi(cp);
	cp = strtok(NULL, ",\n\r");
	y = atoi(cp);

	printf("x: %d y: %d\n", x, y);

	//ground = new 


} // load_map()



void Gamestate::update()
{
} // update()
