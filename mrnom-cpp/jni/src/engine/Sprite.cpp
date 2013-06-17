#include "Sprite.hpp"
#include "Texture.hpp"

Sprite::Sprite(Location location, Texture* texture, int32_t width, int32_t height) :
	mLocation(location), mTexture(texture), mWidth(width), mHeight(height),
	mFrameCount(0), mFrameXCount(0), mFrameYCount(0),
	mAnimStartFrame(0), mAnimFrameCount(0),
	mAnimSpeed(0), mAnimFrame(0.0f),
	mAnimLoop(false) {
}

Sprite::~Sprite() {
}

void Sprite::load() {
	mFrameXCount = mTexture->getWidth() / mWidth;
	mFrameYCount = mTexture->getHeight() / mHeight;
	mFrameCount = mFrameXCount * mFrameYCount;
}

void Sprite::draw(float deltaTime) {
	int32_t currentFrame;
	int32_t currentFrameX;
	int32_t currentFrameY;

	mAnimFrame += deltaTime * mAnimSpeed;

	if (mAnimLoop) {
		// offset frame + current frame
		currentFrame = mAnimStartFrame + mAnimFrame % mAnimFrameCount;
	}
}

void Sprite::setAnimation(int32_t startFrame, int32_t frameCount, float speed, bool loop) {
	mAnimStartFrame = startFrame;
	mAnimFrameCount = frameCount;
	mAnimFrame = 0.0f;
	mAnimSpeed = speed;
	mAnimLoop = loop;
}

bool Sprite::hasAnimationEnded() {
	return mAnimFrame >= mAnimFrameCount;
}
