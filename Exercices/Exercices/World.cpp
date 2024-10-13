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
	float speed = 1;

	//find Mob
	for (int i = 0; i < Entities.size(); i++) {
		if (typeid(*Entities.at(i)) == typeid(Mob)) {
			Mob* mob = dynamic_cast<Mob*>(Entities.at(i));

			//show mob location
			std::cout << "Mob location : ";
			mob->GetPos().Print();
		
			//find Breakable Object
			for (int j = 0; j < Entities.size(); j++) {
				if (typeid(*Entities.at(j)) == typeid(BreakableObject)) {
					BreakableObject* breakableobject = dynamic_cast<BreakableObject*>(Entities.at(j));

					//show Breakable Object location
					std::cout << "Breakable Object location : ";
					breakableobject->GetPos().Print();

					if (mob->GetHp() > 0) {
						//move Mob to Breakable Object
						Vector2 tobreakableobj = breakableobject->GetPos() - mob->GetPos();
						mob->Move(tobreakableobj, speed);
					}
					
					//find Player
					for (int k = 0; k < Entities.size(); k++) {
						if (typeid(*Entities.at(k)) == typeid(Player)) {
							Player* player = dynamic_cast<Player*>(Entities.at(k));

							//show player location
							std::cout << "Player location : ";
							player->GetPos().Print();

							if (mob->GetHp() > 0) {

								if (player->GetPos().distancesqrd(mob->GetPos()) <= 1) {
									player->Attack(mob);

									return 1;
								}

								//move Player to Mob
								Vector2 tomob = mob->GetPos() - player->GetPos();
								player->Move(tomob, speed);

							}
							else if (breakableobject->GetHp() > 0) {
								
								if (player->GetPos().distancesqrd(breakableobject->GetPos()) <= 1) {
									player->Attack(breakableobject);

									return 1;
								}

								//move player to Breakable Object
								Vector2 tobreakableobj = breakableobject->GetPos() - player->GetPos();
								player->Move(tobreakableobj, speed);

							}
							else
							{
								std::cout << "Simulation Finished" << std::endl;
								return 0;
							}
						}
					}
				}
			}
		}
	}
}