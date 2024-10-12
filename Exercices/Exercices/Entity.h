#ifndef ENTITY_H__
#define ENTITY_H__
#include "Vector.h"
#include <iostream>

class AMovable {
protected:
	Vector2 Direction;
	float Speed;

public:
	AMovable(Vector2& direction, float speed);

	virtual void SetDirection(Vector2& direction);
	virtual void SetSpeed(float speed);
	virtual void Move(Vector2& direction, float speed) = 0;
};


class Alive {
protected:
	float MaxHp;
	float Hp;
	std::string Name;

public:
	Alive(float Hp, std::string Name);

	virtual float GetMaxHp();
	virtual float GetHp();
	virtual void TakeDamage(float damage);
	virtual std::string GetName();
};


class IAttacker {
public:
	virtual void Attack(Alive* alive) = 0;
};


class Entity {
protected:
	Vector2 Position;

public:
	Entity(Vector2& position);

	virtual void SetPos(Vector2& position);
	virtual Vector2 GetPos();
};


class StaticObject : public Entity {
public:
	StaticObject(Vector2& position);
};


class BreakableObject : public Entity, public Alive {
public:
	BreakableObject(Vector2& position, float hp);

	void TakeDamage(float damage) override;
};


class Mob : public Entity, public Alive, public AMovable {
public:
	Mob(Vector2& position, Vector2& direction, float speed, float hp);

	void TakeDamage(float damage) override;
	void Move(Vector2& direction, float speed) override;
};


class Player : public Entity, public Alive, public AMovable, public IAttacker {
public:
	Player(Vector2& position, Vector2& direction, float speed, float hp);

	void TakeDamage(float damage) override;
	void Move(Vector2& direction, float speed) override;
	void Attack(Alive* alive) override;
};

#endif