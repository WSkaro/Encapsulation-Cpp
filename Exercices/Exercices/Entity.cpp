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
Alive::Alive(float maxhp, std::string name) : MaxHp(maxhp), Hp(MaxHp), Name(name) {};

float Alive::GetMaxHp() {
	return MaxHp;
}

float Alive::GetHp() {
	return Hp;
}

void Alive::TakeDamage(float dmg) {
	Hp -= dmg;
}

std::string Alive::GetName() {
	return Name;
}


//Entity construct
Entity::Entity(Vector2& vector) 
	: Position(vector) {};

void Entity::SetPos(Vector2& position) {
	Position = position;
}

Vector2 Entity::GetPos() {
	return Position;
}


//StaticObject construct
StaticObject::StaticObject(Vector2& position) 
	: Entity(position) {
	std::cout << "Static Object just created at x = " << position.GetX() 
		<< " and y = " << position.GetY() << std::endl;
};


//BreakableObject construct
BreakableObject::BreakableObject(Vector2& position, float maxhp) :
	Entity(position), Alive(maxhp, "Breakable Object") {
	std::cout << "Breakable Object just created at x = " << position.GetX() 
		<< " and y = " << position.GetY() 
		<< " with " << maxhp 
		<< " HP" << std::endl;
};

void BreakableObject::TakeDamage(float dmg) {
	Alive::TakeDamage(dmg);

	if (Hp == 0) {
		std::cout << "Breakable Object just took " << dmg 
			<< " damage and broke." << std::endl;
	}
	else {
		std::cout << "Breakable Object took " << dmg << " damage."
			<< Hp << " remaining."
			<< std::endl;
	}
}


//Mob construct
Mob::Mob(Vector2& position, Vector2& direction, float maxhp) :
	Entity(position), AMovable(direction), Alive(maxhp, "Mob") {
	std::cout << "mob just created at x = " << position.GetX() 
		<< " and y = " << position.GetY() 
		<< " with " << maxhp 
		<< " HP, with direction x = " << direction.GetX() 
		<< " and direction y = " << direction.GetY() << std::endl;
}

void Mob::TakeDamage(float dmg) {
	Alive::TakeDamage(dmg);
	if (Hp == 0) {
		std::cout << "Mob just took " << dmg
			<< " damage and died." << std::endl;
	}
	else {
		std::cout << "Mob took " << dmg << " damage."
			<< Hp << " remaining."
			<< std::endl;
	}
}

void Mob::Move(Vector2& direction, float speed) {
	Position += direction; //*speed
	std::cout << "Mob moved to x = " << Position.GetX()
		<< " and y = " << Position.GetY() << std::endl;
}


//Player construct
Player::Player(Vector2& position, Vector2& direction, float maxhp) :
	Entity(position), AMovable(direction), Alive(maxhp, "Player") {
	std::cout << "Player just created at x = " << position.GetX()
		<< " and y = " << position.GetY()
		<< " with " << maxhp
		<< " HP, with direction x = " << direction.GetX()
		<< " and direction y = " << direction.GetY() << std::endl;
}

void Player::TakeDamage(float dmg) {
	Alive::TakeDamage(dmg);
	if (Hp == 0) {
		std::cout << "Player just took " << dmg
			<< " damage and died." << std::endl;
	}
	else {
		std::cout << "Player took " << dmg << " damage."
			<< Hp << " remaining."
			<< std::endl;
	}
}

void Player::Move(Vector2& direction, float speed) {
	Position += direction; //*speed
	std::cout << "Player moved to x = " << Position.GetX()
		<< " and y = " << Position.GetY() << std::endl;
}

void Player::Attack(Alive* alive) {
	alive->TakeDamage(10);
	std::cout << this->GetName() << " just attacked " << alive->GetName() << std::endl;
}
