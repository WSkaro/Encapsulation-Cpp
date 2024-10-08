#ifndef PLAYER_H__
#define PLAYER_H__

#include "Entity.h"

class Player : public Entity {
public:
	Player();
	void SayHello() override;
};

#endif