#ifndef ANIMATOR_HPP
#define ANIMATOR_HPP

#include "../../common.h"

#include "Accumulator.hpp"

namespace engine {

/**
 * Maps the accumulated time to a range of values.
 */
class Animator : public Accumulator {

public:

	Animator();

	virtual ~Animator();

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

	float _rangeOffset;
	float _rangeLength;

	/**
	 * rangeLength / tickDuration
	 */
	float _factor;
};

}

#endif
