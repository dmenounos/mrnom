#include "Vector.hpp"

using namespace engine;

Vector::Vector() :
	_x(0), _y(0) {
}

void Vector::setPosition(float x, float y) {
	_x = x;
	_y = y;
}

void Vector::translate(float x, float y) {
	_x += x;
	_y += y;
}

float Vector::getX() const {
	return _x;
}

float Vector::getY() const {
	return _y;
}
