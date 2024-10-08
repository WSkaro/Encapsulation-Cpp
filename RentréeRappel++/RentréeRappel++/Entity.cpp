#include <iostream>
#include "Entity.h"

Entity::Entity() : position(0.f, 0.f, 0.f) {};

void Entity::SayHello() {
	std::cout << "Hello Entity !" << std::endl;
}