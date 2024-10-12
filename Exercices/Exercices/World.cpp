#include "World.h"

//World Init
void World::Init() {

	//Init StaticObject
	Vector2 statobj_pos = Vector2(1, 2);
	Entities.push_back(new StaticObject(statobj_pos));

	//Init BreakableObject
	Vector2 breakableobject_pos = Vector2(3, 4);
	Entities.push_back(new BreakableObject(breakableobject_pos, 1));

	//Init Mob
	Vector2 mob_pos = Vector2(5, 6);
	Vector2 mob_dir = Vector2(1, 1);
	Entities.push_back(new Mob(mob_pos, mob_dir, 1, 20));

	//Init Player
	Vector2 player_pos = Vector2(9, 10);
	Vector2 player_dir = Vector2(1, 1);
	Entities.push_back(new Player(player_pos, player_dir, 1, 10));
}

int World::Step() {
	for (int i = 0; i < Entities.size(); i++) {

		if (typeid(*Entities.at(i)) == typeid(Mob)) {
			Mob* mob = dynamic_cast<Mob*>(Entities.at(i));
			for (int j = 0; j < Entities.size(); j++) {
				if (typeid(*Entities.at(j)) == typeid(BreakableObject)) {
					BreakableObject* breakableobject = dynamic_cast<BreakableObject*>(Entities.at(i));

					mob->Move()
				}
			}
		}
		else if (typeid(*Entities.at(i)) == typeid(Player)) {
			Player* player = dynamic_cast<Player*>(Entities.at(i));
		}
	}
}