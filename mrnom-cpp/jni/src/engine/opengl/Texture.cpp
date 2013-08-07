#include "Texture.hpp"

#include "../GameContext.hpp"
#include "../core/Bitmap.hpp"
#include "../system/ResourceFactory.hpp"

using namespace engine;

Texture::Texture(GameContext* gameContext, const char* fileName) :
	mGameContext(gameContext), mFileName(fileName),
	mTextureId(0), mWidth(0), mHeight(0) {
	LOG_D("### Texture::Texture(%s)", mFileName);
}

Texture::~Texture() {
	LOG_D("### Texture::~Texture(%s)", mFileName);
}

void Texture::reload() {
	LOG_D("--> Texture::reload()");

	if (mTextureId) {
		return;
	}

	ResourceFactory* resourceFactory = mGameContext->getResourceFactory();
	Bitmap* bitmap = resourceFactory->createBitmap(mFileName);

	// Generate new texture id
	glGenTextures(1, &mTextureId);

	LOG_D("--- Texture::reload() mTextureId: %d", mTextureId);

	glBindTexture(GL_TEXTURE_2D, mTextureId);

	// Setup texture properties
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	/*
	 * Load image data into OpenGL:
	 *
	 * target         : The target texture. Must be GL_TEXTURE_2D.
	 * level          : The level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
	 * internalformat : The number of color components in the texture. Must be same as format. The following symbolic values are accepted:
	 *                  GL_ALPHA, GL_RGB, GL_RGBA, GL_LUMINANCE, GL_LUMINANCE_ALPHA.
	 * width          : The width of the texture image. Must be 2^n + 2 * (border) for some integer n.
	 * height         : The height of the texture image. Must be 2^m + 2 * (border) for some integer m.
	 * border         : The width of the border. Must be either 0 or 1.
	 * format         : The format of the pixel data. Must be same as internalformat. The following symbolic values are accepted:
	 *                  GL_ALPHA, GL_RGB, GL_RGBA, GL_LUMINANCE, GL_LUMINANCE_ALPHA.
	 * type           : The data type of the pixel data. The following symbolic values are accepted:
	 *                  GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_5_5_5_1.
	 * pixels         : A pointer to the image data in memory.
	 */

	glTexImage2D(GL_TEXTURE_2D,
	             0,
	             bitmap->getFormat(),
	             bitmap->getWidth(),
	             bitmap->getHeight(),
	             0,
	             bitmap->getFormat(),
	             GL_UNSIGNED_BYTE,
	             bitmap->getPixels());

	if (glGetError() != GL_NO_ERROR) {
		LOG_E("Error uploading texture into OpenGL.");
	}

	glBindTexture(GL_TEXTURE_2D, 0);

	mWidth  = bitmap->getWidth();
	mHeight = bitmap->getHeight();

	delete bitmap;
}

void Texture::unload() {
	LOG_D("--> Texture::unload()");

	if (!mTextureId) {
		return;
	}

	glDeleteTextures(1, &mTextureId);
}

void Texture::rebind() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mTextureId);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Texture::unbind() {
	glDisable(GL_BLEND);

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}

int32_t Texture::getWidth() const {
	return mWidth;
}

int32_t Texture::getHeight() const {
	return mHeight;
}
