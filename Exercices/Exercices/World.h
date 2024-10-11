#ifndef WORLD_H__
#define WORLD_H__
#include "Entity.h"
#include <vector>

class World {
public:
	std::vector<Entity*> Entities;

	void Init();
	void Step();



};

#endif