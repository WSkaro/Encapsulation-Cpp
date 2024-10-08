#ifndef VECTOR_H__
#define VECTOR_H__

class Vector2 {
private:
	float x;
	float y;

public:
	Vector2(float _x, float _y);

	void SetX(float _x);
	void SetY(float _y);
	float GetX();
	float GetY();
	void Print();
};

#endif