// Gamestate Class
//
// Stores Game data and other information (entities, maps, etc.)


#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <cstdio>
#include <cstdlib>
#include <cstring>


using namespace std;

class Gamestate
{
private:
	int x, y;
	int **ground;
	int **entities;

public:
	Gamestate();
	~Gamestate();
	void load_map(const char *filename);
	void update();

	friend class Render;
}; // class Gamestate

#endif
