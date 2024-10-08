#include <iostream>
#include <sstream>
#include "Point.h"

Point::Point(float _x, float _y, float _z) : x(0.f), y(0.f), z(0.f) {};


std::string Point::ToString() {
    std::stringstream strCoord;
    strCoord << "Point:" << " x: " << x << " y: " << y << " z: " << z << std::endl;

    return strCoord.str();
}

