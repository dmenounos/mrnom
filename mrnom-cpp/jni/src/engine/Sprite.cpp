#include "Sprite.hpp"
#include "Texture.hpp"

Sprite::Sprite(Location location, Texture* texture, int32_t width, int32_t height) :
	mLocation(location), mTexture(texture), mWidth(width), mHeight(height),
	mFrameCount(0), mFrameXCount(0), mFrameYCount(0),
	mAnimStartFrame(0), mAnimFrameCount(0), mAnimCurrentFrame(0),
	mAnimProgress(0.0f), mAnimDuration(0.0f),
	mAnimFactor(0.0f), mAnimLoop(false) {
}

Sprite::~Sprite() {
}

void Sprite::load() {
	mFrameXCount = mTexture->getWidth() / mWidth;
	mFrameYCount = mTexture->getHeight() / mHeight;
	mFrameCount = mFrameXCount * mFrameYCount;
}

void Sprite::setAnimation(int32_t startFrame, int32_t frameCount, float duration, bool loop) {
	assert(startFrame >= 0 && startFrame < mFrameCount);
	assert(frameCount <= mFrameCount);

	mAnimStartFrame = startFrame;
	mAnimFrameCount = frameCount;
	mAnimDuration = duration;
	mAnimLoop = loop;

	mAnimFactor = frameCount / duration;
	mAnimProgress = 0.0f;
	mAnimCurrentFrame = 0;
}

bool Sprite::hasAnimationEnded() {
	return mAnimProgress >= mAnimDuration;
}

void Sprite::update(float deltaTime) {
	mAnimProgress += deltaTime;

	if (mAnimLoop || !hasAnimationEnded()) {
		if (hasAnimationEnded()) {
			mAnimProgress -= mAnimDuration;
		}

		mAnimCurrentFrame = mAnimStartFrame + mAnimProgress * mAnimFactor;
	}
	else {
		mAnimProgress = 0.0f;
		mAnimCurrentFrame = 0;
	}
}

void Sprite::render(float deltaTime) {
	int32_t currentFrameX;
	int32_t currentFrameY;
}
