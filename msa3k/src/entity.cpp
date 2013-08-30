#include "entity.h"

Entity::Entity(int i): id_num(i),
	x(0), y(0), vx(0), vy(0)
{
} // Entity()

int Entity::fetch_id()
{
	return id_num;
} // fetch_id()
