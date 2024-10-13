#ifndef VECTOR_H__
#define VECTOR_H__
#include <iostream>

class Vector2 {
private:
	float x;
	float y;

public:
	Vector2(float _x, float _y);

	void SetX(float _x);
	void SetY(float _y);
	float GetX() const;
	float GetY() const;
	void Print();

	Vector2 operator + (const Vector2& other) const;
	Vector2* operator += (const Vector2& other);
	Vector2 operator - (const Vector2& other) const;
	Vector2 operator * (const float other) const; //Vector2 * float
	float magnitude() const;
	Vector2 normalize() const;
	float distancesqrd(const Vector2& other);
};

#endif