#include "Animation.hpp"

namespace engine {

Animation::Animation() : Accumulator(),
	mOffset(0), mLength(0), mFactor(0.0f) {
	// LOG_D("### Animation::Animation()");
}

Animation::~Animation() {
	// LOG_D("### Animation::~Animation()");
}

int32_t Animation::getCursor() {
	return getTickProgress() * mFactor + mOffset;
}

int32_t Animation::getOffset() const {
	return mOffset;
}

void Animation::setOffset(int32_t offset) {
	mOffset = offset;
}

int32_t Animation::getLength() const {
	return mLength;
}

void Animation::setLength(int32_t length) {
	mLength = length;

	if (getTickDuration() > 0.0f) {
		mFactor = length / getTickDuration();
	} else {
		mFactor = 0.0f;
	}
}

}
