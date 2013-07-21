#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "../common.h"

namespace engine {

class Animation {

public:

	Animation();

	virtual ~Animation();

	virtual void config(int32_t offset, int32_t length, float duration, bool loop);

	virtual void update(float deltaTime);

	virtual bool hasEnded();

	int32_t getCursor();

private:

	/** Offset frame. */
	int32_t mOffset;

	/** Total frames. */
	int32_t mLength;

	/** Current frame. */
	int32_t mCursor;

	/** Time accumulator. */
	float mProgress;

	/** Time duration. */
	float mDuration;

	/** Frames / Second. */
	float mFactor;

	bool mLoop;
};

}

#endif
