#include "Animation.hpp"

using namespace engine;

Animation::Animation() : Accumulator(),
	mRangeOffset(0), mRangeLength(0), mFactor(0.0f) {
	// LOG_D("### Animation::Animation()");
}

Animation::~Animation() {
	// LOG_D("### Animation::~Animation()");
}

float Animation::getCursor() {
	return getTickProgress() * mFactor + mRangeOffset;
}

float Animation::getRangeOffset() const {
	return mRangeOffset;
}

void Animation::setRangeOffset(float rangeOffset) {
	mRangeOffset = rangeOffset;
}

float Animation::getRangeLength() const {
	return mRangeLength;
}

void Animation::setRangeLength(float rangeLength) {
	mRangeLength = rangeLength;

	if (getTickDuration() > 0.0f) {
		mFactor = mRangeLength / getTickDuration();
	} else {
		mFactor = 0.0f;
	}
}
