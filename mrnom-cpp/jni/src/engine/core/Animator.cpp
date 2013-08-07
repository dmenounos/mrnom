#include "Animator.hpp"

using namespace engine;

Animator::Animator() : Accumulator(),
	mRangeOffset(0), mRangeLength(0), mFactor(0.0f) {
	// LOG_D("### Animator::Animator()");
}

Animator::~Animator() {
	// LOG_D("### Animator::~Animator()");
}

float Animator::getCursor() {
	return getTickProgress() * mFactor + mRangeOffset;
}

float Animator::getRangeOffset() const {
	return mRangeOffset;
}

void Animator::setRangeOffset(float rangeOffset) {
	mRangeOffset = rangeOffset;
}

float Animator::getRangeLength() const {
	return mRangeLength;
}

void Animator::setRangeLength(float rangeLength) {
	mRangeLength = rangeLength;

	if (getTickDuration() > 0.0f) {
		mFactor = mRangeLength / getTickDuration();
	} else {
		mFactor = 0.0f;
	}
}
