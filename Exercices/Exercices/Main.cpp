#include <iostream>
#include "Integer.h"
#include "Entity.h"
#include "World.h"

int main(int argc, char* argv[]) {
	
	// TEST ====================
	////init staticobj
	//Vector2 staticobject_pos = Vector2(1, 2);
	//StaticObject* staticobject = new StaticObject(staticobject_pos);

	////init breakableobj
	//Vector2 breakableobject_pos = Vector2(3, 4);
	//BreakableObject* breakableobject = new BreakableObject(breakableobject_pos, 50);

	////init mob
	//Vector2 mob_pos = Vector2(5, 6);
	//Vector2 mob_dir = Vector2(1, 1);
	//Mob* mob = new Mob(mob_pos, mob_dir, 50);

	////init Player
	//Vector2 player_pos = Vector2(9, 10);
	//Vector2 player_dir = Vector2(1, 1);
	//Player* player = new Player(player_pos, player_dir, 100);

	////test breakableobj
	//breakableobject->TakeDamage(10);
	//breakableobject->TakeDamage(40);

	////test mob
	//Vector2 moving_mob = Vector2(1, 1);
	//mob->Move(moving_mob, 1);
	//mob->TakeDamage(20);
	//mob->TakeDamage(20);

	////test player
	//Vector2 moving_player = Vector2(1, 1);
	//player->Move(moving_player, 1);
	//player->TakeDamage(50);
	//player->TakeDamage(50);
	//player->Attack(mob);
	// TEST ====================

	World* world = new World();
	world->Init();

	while (world->Step()) {};


	return 0;
}
