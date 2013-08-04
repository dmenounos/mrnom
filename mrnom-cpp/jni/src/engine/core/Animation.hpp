#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "../../common.h"

#include "Accumulator.hpp"

namespace engine {

class Animation : public Accumulator {

public:

	Animation();

	virtual ~Animation();

	/**
	 * The current cursor, a value in between
	 * the offset (included) and the length (excluded).
	 */
	virtual float getCursor();

	/**
	 * The range offset.
	 */
	virtual float getRangeOffset() const;
	virtual void setRangeOffset(float rangeOffset);

	/**
	 * The range length.
	 */
	virtual float getRangeLength() const;
	virtual void setRangeLength(float rangeLength);

private:

	float mRangeOffset;
	float mRangeLength;

	/**
	 * rangeLength / tickDuration
	 */
	float mFactor;
};

}

#endif
