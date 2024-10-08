#ifndef ENTITY_H__
#define ENTITY_H__
#include "Vector.h"

class AMovable {
protected:
	Vector2 Direction;
	float Speed;

public:
	AMovable();

	virtual void SetDirection(Vector2 direction);
	virtual void SetSpeed(float speed);
	virtual void Move(Vector2 direction, float speed) = 0;
};


class Alive {
protected:
	float MaxHp;
	float Hp;

public:
	Alive();

	float GetMaxHp();
	float GetHp();
	void TakeDamage(float dmg);
};


class IAttacker {
public:
	virtual void Attack(Alive* alive) = 0;
};


class Entity {
protected:
	Vector2 Position;

public:
	Entity(float, float);

	virtual void SetPos(Vector2 position);
	virtual Vector2 GetPos();
};


class StaticObject : public Entity {
public:
	StaticObject(float, float);
};

#endif