#include "Sprite.hpp"
#include "Texture.hpp"

namespace engine {

Sprite::Sprite(Texture* texture) :
	mTexture(texture),
	mFrameWidth(0), mFrameHeight(0),
	mHorFrames(1), mVerFrames(1),
	mAnimation(), mPosition() {
	LOG_D("### Sprite::Sprite()");
}

Sprite::~Sprite() {
	LOG_D("### Sprite::~Sprite()");
	delete mTexture;
}

void Sprite::reload() {
	mTexture->reload();
	mFrameWidth  = mTexture->getWidth()  / mHorFrames;
	mFrameHeight = mTexture->getHeight() / mVerFrames;
}

void Sprite::update(float deltaTime) {
	mAnimation.update(deltaTime);
}

void Sprite::render(float deltaTime) {
	int32_t currentFrameX;
	int32_t currentFrameY;
	mTexture->bind();
	LOG_D("--- ANIMATION FRAME: %d", mAnimation.getCursor());
}

int32_t Sprite::getFrameWidth() const {
	return mFrameWidth;
}

int32_t Sprite::getFrameHeight() const {
	return mFrameHeight;
}

int32_t Sprite::getHorFrames() const {
	return mHorFrames;
}

void Sprite::setHorFrames(int32_t horFrames) {
	assert(horFrames >= 1);
	mHorFrames = horFrames;
}

int32_t Sprite::getVerFrames() const {
	return mVerFrames;
}

void Sprite::setVerFrames(int32_t verFrames) {
	assert(verFrames >= 1);
	mVerFrames = verFrames;
}

Animation& Sprite::getAnimation() {
	return mAnimation;
}

Vector& Sprite::getPosition() {
	return mPosition;
}

}
