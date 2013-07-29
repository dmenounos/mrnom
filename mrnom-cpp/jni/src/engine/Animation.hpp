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

	/**
	 * Offset frame.
	 */
	virtual int32_t getOffset() const;
	virtual void setOffset(int32_t offset);

	/**
	 * Total frames.
	 */
	virtual int32_t getLength() const;
	virtual void setLength(int32_t length);

private:

	int32_t mOffset;
	int32_t mLength;

	// FPS
	float mFactor;

};

}

#endif
