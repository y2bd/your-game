// Gamedata Class
//
// Stores Game data and other information (entities, maps, etc.)


#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "allegro5/allegro5.h"
#include <cstring>


using namespace std;

class Gamedata
{
private:
	int x, y;
	int **ground;
	int **entities;

public:
	Gamedata();
	~Gamedata();
	void load_map(const char *filename);
	void update();

	friend class Render;
}; // class Gamedata

#endif
