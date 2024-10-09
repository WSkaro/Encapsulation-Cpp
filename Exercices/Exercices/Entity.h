#ifndef ENTITY_H__
#define ENTITY_H__
#include "Vector.h"

class AMovable {
protected:
	Vector2 Direction;
	float Speed;

public:
	AMovable(Vector2&);

	virtual void SetDirection(Vector2& direction);
	virtual void SetSpeed(float speed);
	virtual void Move(Vector2& direction, float speed) = 0;
};


class Alive {
protected:
	float MaxHp;
	float Hp;

public:
	Alive(float);

	virtual float GetMaxHp();
	virtual float GetHp();
	virtual void TakeDamage(float dmg);
};


class IAttacker {
public:
	virtual void Attack(Alive* alive) = 0;
};


class Entity {
protected:
	Vector2 Position;

public:
	Entity(Vector2&);

	virtual void SetPos(Vector2& position);
	virtual Vector2 GetPos();
};


class StaticObject : public Entity {
public:
	StaticObject(Vector2&);
};


class BreakableObject : public Entity, public Alive {
public:
	BreakableObject(Vector2&, float maxhp);

	void TakeDamage(float dmg) override;
};


class Mob : public Entity, public Alive, public AMovable {
public:
	Mob(Vector2&, Vector2&, float);

	void TakeDamage(float dmg) override;
};

#endif