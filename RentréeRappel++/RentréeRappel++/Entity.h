#ifndef ENTITY_H__
#define ENTITY_H__

#include "Point.h"

class Entity {
protected:
	Point position;

public:
	Entity();
	virtual void SayHello();
};

#endif