#include "Location.hpp"

Location::Location() :
	mX(0), mY(0) {
}

void Location::setPosition(float x, float y) {
	mX = x;
	mY = y;
}

void Location::translate(float x, float y) {
	mX += x;
	mY += y;
}

float Location::getX() const {
	return mX;
}

float Location::getY() const {
	return mY;
}
