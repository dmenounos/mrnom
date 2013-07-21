#include "Vector.hpp"

namespace engine {

Vector::Vector() :
	mX(0), mY(0) {
}

void Vector::setPosition(float x, float y) {
	mX = x;
	mY = y;
}

void Vector::translate(float x, float y) {
	mX += x;
	mY += y;
}

float Vector::getX() const {
	return mX;
}

float Vector::getY() const {
	return mY;
}

}
