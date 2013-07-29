#include "Sprite.hpp"
#include "Texture.hpp"
#include "Vertices.hpp"

namespace engine {

Sprite::Sprite(Texture* texture, Vertices* vertices) :
	mTexture(texture), mVertices(vertices),
	mAnimation(), mPosition(),
	mHorFrames(1), mVerFrames(1),
	mFrameWidth(0), mFrameHeight(0) {

	LOG_D("### Sprite::Sprite()");
}

Sprite::~Sprite() {
	LOG_D("### Sprite::~Sprite()");

	delete mVertices;
}

void Sprite::reload() {
	LOG_D("--> Sprite::reload()");

	mTexture->reload();

	mFrameWidth  = mTexture->getWidth()  / mHorFrames;
	mFrameHeight = mTexture->getHeight() / mVerFrames;
}


void Sprite::unload() {
	LOG_D("--> Sprite::unload()");

	mTexture->unload();
}

void Sprite::update(float deltaTime) {
	mAnimation.update(deltaTime);
}

void Sprite::render(float deltaTime) {
	int32_t currentFrameX;
	int32_t currentFrameY;

	glEnable(GL_TEXTURE_2D);
	mTexture->bind();

	mVertices->render();
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

int32_t Sprite::getFrameWidth() const {
	return mFrameWidth;
}

void Sprite::setFrameWidth(int32_t frameWidth) {
	mFrameWidth = frameWidth;
}

int32_t Sprite::getFrameHeight() const {
	return mFrameHeight;
}

void Sprite::setFrameHeight(int32_t frameHeight) {
	mFrameHeight = frameHeight;
}

Animation& Sprite::getAnimation() {
	return mAnimation;
}

Vector& Sprite::getPosition() {
	return mPosition;
}

}
