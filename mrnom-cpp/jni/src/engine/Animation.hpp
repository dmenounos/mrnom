#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "../common.h"

#include "Accumulator.hpp"

namespace engine {

class Animation : public Accumulator {

public:

	Animation();

	virtual ~Animation();

	virtual int32_t getCursor();

	virtual int32_t getOffset() const;
	virtual void setOffset(int32_t offset);

	virtual int32_t getLength() const;
	virtual void setLength(int32_t length);

private:

	/** Offset frame. */
	int32_t mOffset;

	/** Total frames. */
	int32_t mLength;

	/** Frames / Second. */
	float mFactor;

};

}

#endif
