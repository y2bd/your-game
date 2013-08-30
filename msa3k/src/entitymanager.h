#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <list>

#include "entity.h"

class EntityManager
{
private:
	std::list<Entity> entities;
public:
	EntityManager(void);
	~EntityManager(void);
};

#endif

