#include <iostream>
#include "Entity.h"

//AMovable construct
AMovable::AMovable() : Direction(Vector2(0.f, 0.f)) {};

void AMovable::SetDirection(Vector2 direction) {
	Direction = direction;
}

void AMovable::SetSpeed(float speed) {
	Speed = speed;
}


//Alive construct
Alive::Alive() : MaxHp(100), Hp(MaxHp) {};

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
Entity::Entity(float x, float y) : Position(Vector2(x, y)) {};

void Entity::SetPos(Vector2 position) {
	Position = position;
}

Vector2 Entity::GetPos() {
	return Position;
}


//StaticObject construct
StaticObject::StaticObject(float x, float y) : Entity(x, y) {};

