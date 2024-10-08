#ifndef POINT_H__
#define POINT_H__

#include <iostream>

class Point {
public:
	float x;
	float y;
	float z;

	Point(float, float, float);

	std::string ToString();
};

#endif



