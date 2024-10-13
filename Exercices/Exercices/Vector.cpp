#include <sstream>
#include "Vector.h"
#include <math.h>

Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {};

void Vector2::SetX(float _x) {
	x = _x;
}

void Vector2::SetY(float _y) {
	y = _y;
}

float Vector2::GetX() const {
	return x;
}

float Vector2::GetY() const {
	return y;
}

void Vector2::Print() {
	std::stringstream stringvec;
	stringvec << "(" << x << ", " << y << ")" << "\n" << std::endl;

	std::string str = stringvec.str();

	std::cout << str;
}

Vector2 Vector2::operator + (const Vector2& other) const {
	return Vector2(this->x + other.GetX(), this->y + other.GetY());
}

Vector2* Vector2::operator += (const Vector2& other) {
	Vector2* tmp = new Vector2(this->x += other.GetX(), this->y += other.GetY());
	return tmp;
}

Vector2 Vector2::operator - (const Vector2& other) const {
	return Vector2(this->x - other.GetX(), this->y - other.GetY());
}

Vector2 Vector2::operator * (const float other) const {
	Vector2 tmp = Vector2(this->x * other, this->y * other);
	return tmp;
}

float Vector2::magnitude() const {
	return sqrt(this->x * this->x + this->y * this->y);
}

Vector2 Vector2::normalize() const {
	return Vector2(this->x / magnitude(), this->y / magnitude());
}

float Vector2::distancesqrd(const Vector2& other) {
	return ((other.GetX() - this->x) * (other.GetX() - this->x)
		+ (other.GetY() - this->y) * (other.GetY() - this->y));
}