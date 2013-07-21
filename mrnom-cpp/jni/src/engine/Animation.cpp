#include "Animation.hpp"

namespace engine {

Animation::Animation() :
	mOffset(0), mLength(0),
	mDuration(0.0), mLoop(false),
	mProgress(0.0), mCursor(0) {
	LOG_D("### Animation::Animation()");
}

Animation::~Animation() {
	LOG_D("### Animation::~Animation()");
}

void Animation::config(int32_t offset, int32_t length, float duration, bool loop) {
	assert(offset >= 0 && offset < length);

	LOG_D("### Animation::config(%d, %d, %f, %d)", offset, length, duration, loop);

	mOffset = offset;
	mLength = length;
	mDuration = duration;
	mLoop = loop;

	mFactor = length / duration;
	mCursor = mProgress = 0.0f;
}

void Animation::update(float deltaTime) {
	mProgress += deltaTime;

	while (mLoop && hasEnded()) {
		mProgress -= mDuration;
	}

	if (!hasEnded()) {
		mCursor = mOffset + mProgress * mFactor;
	}
	else {
		mCursor = mProgress = 0.0f;
	}
}

bool Animation::hasEnded() {
	return mProgress >= mDuration;
}

int32_t Animation::getCursor() {
	return mCursor;
}

}
