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

float Vector2::GetX() {
	return x;
}

float Vector2::GetY() {
	return y;
}

void Vector2::Print() {
	std::stringstream stringvec;
	stringvec << "(" << x << ", " << y << ")" << std::endl;

	std::string str = stringvec.str();

	std::cout << str;
}