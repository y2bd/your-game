// represents the player's component bag

#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include "entity.h"

class PlayerEntity :
	public Entity
{
public:
	PlayerEntity(int i);
	~PlayerEntity();

	virtual void update();
};

#endif