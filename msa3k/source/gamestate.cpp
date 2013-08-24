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
	char line[32];
	char *cp;

	if(!(fp = fopen(filename, "rb")))
	{
		fprintf(stderr, "[Map Error] Count not find and open file.\n");
		return;
	} // if can't open file

	printf("File Found!\n");
	

	fgets(line, 32, fp);
	cp = strtok(line, ",\n\r");
	x = atoi(cp);
	cp = strtok(NULL, ",\n\r");
	y = atoi(cp);

	printf("x: %d y: %d\n", x, y);

	//ground = new 


} // load_map()



void Gamestate::update()
{
} // update()
