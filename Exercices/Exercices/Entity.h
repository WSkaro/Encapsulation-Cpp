#ifndef ENTITY_H__
#define ENTITY_H__
#include "Vector.h"
#include <iostream>

class AMovable {
protected:
	Vector2 Direction;
	float Speed;

public:
	AMovable(Vector2&);

	virtual void SetDirection(Vector2&);
	virtual void SetSpeed(float);
	virtual void Move(Vector2&, float) = 0;
};


class Alive {
protected:
	float MaxHp;
	float Hp;
	std::string Name;

public:
	Alive(float, std::string);

	virtual float GetMaxHp();
	virtual float GetHp();
	virtual void TakeDamage(float);
	virtual std::string GetName();
};


class IAttacker {
public:
	virtual void Attack(Alive*) = 0;
};


class Entity {
protected:
	Vector2 Position;

public:
	Entity(Vector2&);

	virtual void SetPos(Vector2&);
	virtual Vector2 GetPos();
};


class StaticObject : public Entity {
public:
	StaticObject(Vector2&);
};


class BreakableObject : public Entity, public Alive {
public:
	BreakableObject(Vector2&, float);

	void TakeDamage(float) override;
};


class Mob : public Entity, public Alive, public AMovable {
public:
	Mob(Vector2&, Vector2&, float);

	void TakeDamage(float) override;
	void Move(Vector2&, float) override;
};


class Player : public Entity, public Alive, public AMovable, public IAttacker {
public:
	Player(Vector2&, Vector2&, float);

	void TakeDamage(float) override;
	void Move(Vector2&, float) override;
	void Attack(Alive*) override;
};

#endif