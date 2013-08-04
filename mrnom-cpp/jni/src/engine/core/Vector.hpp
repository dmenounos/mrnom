#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../../common.h"

namespace engine {

class Vector {

public:

	Vector();

	void setPosition(float x, float y);

	void translate(float x, float y);

	float getX() const;

	float getY() const;

private:

	float mX;
	float mY;
};

}

#endif
