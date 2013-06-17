#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "../common.h"

class Location {

public:

	Location();

	void setPosition(float x, float y);

	void translate(float x, float y);

	float getX() const;

	float getY() const;

private:

	float mX;
	float mY;
};

#endif
