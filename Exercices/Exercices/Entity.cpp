#include <iostream>
#include "Entity.h"

//AMovable construct
AMovable::AMovable(Vector2& vector) : Direction(vector), Speed(0.f) {};

void AMovable::SetDirection(Vector2& direction) {
	Direction = direction;
}

void AMovable::SetSpeed(float speed) {
	Speed = speed;
}


//Alive construct
Alive::Alive(float maxhp) : MaxHp(maxhp), Hp(MaxHp) {};

float Alive::GetMaxHp() {
	return MaxHp;
}

float Alive::GetHp() {
	return Hp;
}

void Alive::TakeDamage(float dmg) {
	Hp -= dmg;
}


//Entity construct
Entity::Entity(Vector2& vector) : Position(vector) {};

void Entity::SetPos(Vector2& position) {
	Position = position;
}

Vector2 Entity::GetPos() {
	return Position;
}


//StaticObject construct
StaticObject::StaticObject(Vector2& position) : Entity(position) {
	std::cout << "Static Object just created at x = " << position.GetX() << " and y = " << position.GetY() << std::endl;
};


//BreakableObject construct
BreakableObject::BreakableObject(Vector2& position, float maxhp) : Entity(position), Alive(maxhp) {
	std::cout << "Breakable Object just created at x = " << position.GetX() << " and y = " << position.GetY()
		<< " with " << maxhp << " HP" << std::endl;
};

void BreakableObject::TakeDamage(float dmg) {
	Alive::TakeDamage(dmg);
	std::cout << "Breakable Object just broke" << std::endl;
}


//Mob construct
Mob::Mob(Vector2& position, Vector2& direction, float maxhp) : Entity(position), AMovable(direction), Alive(maxhp) {
	std::cout << "mob just created at x = " << position.GetX() << " and y = " << position.GetY()
		<< " with " << maxhp << " HP, with direction x = " << direction.GetX() << " and direction y = " << direction.GetY() << std::endl;
}

void Mob::TakeDamage(float dmg) {
	Alive::TakeDamage(dmg);
	std::cout << "Mob just died" << std::endl;
}