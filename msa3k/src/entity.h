// Abstract Entity class
//
// Contains data for entity

#ifndef ENTITY_H
#define ENTITY_H

//#include "input.h"
//#include "mapdata.h"

class Entity
{
protected:
	int id_num;
	int x, y; // position
	int vx, vy; // velocity
	int top, bottom, left, right; // body box
	//Input inputs;
	//MapData *currentMap;

public:
	Entity(int i);
	~Entity();

	int fetch_id();

	virtual void update() = 0;
	friend class Render;
}; // class Entity

#endif
