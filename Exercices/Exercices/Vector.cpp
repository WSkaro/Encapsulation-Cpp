#include <iostream>
#include <sstream>
#include "Vector.h"

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
	stringvec << "(" << x << ", " << y << ")" << std::endl;

	std::string str = stringvec.str();

	std::cout << str;
}

Vector2 Vector2::operator + (const Vector2& _other) {
	Vector2 tmp(this->x + _other.GetX(), this->y + _other.GetY());

	return tmp;
}

Vector2* Vector2::operator += (const Vector2& _other) {
	Vector2* tmp = new Vector2(this->x += _other.GetX(), this->y += _other.GetY());

	return tmp;
}

Vector2 Vector2::operator * (const float _other) {
	Vector2 tmp = Vector2(this->x * _other, this->y * _other);

	return tmp;
}