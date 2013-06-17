#include "Texture.hpp"

#include <GLES/gl.h>

Texture::Texture() :
	mWidth(0), mHeight(0),
	mFormat(0), mTextureId(0) {
	LOG_D("Texture::Texture()");
}

Texture::~Texture() {
	LOG_D("Texture::~Texture()");
}

int32_t Texture::getWidth() const {
	return mWidth;
}

int32_t Texture::getHeight() const {
	return mHeight;
}

int32_t Texture::getFormat() const {
	return mFormat;
}

void Texture::load(
	int32_t width,
	int32_t height,
	int32_t format,
	uint8_t* pixels)
{
	LOG_D("Texture::load(%d, %d, %d)", width, height, format);

	GLenum errorResult;

	// Generate new texture id
	glGenTextures(1, &mTextureId);

	LOG_D("Texture::load mTextureId: %d", mTextureId);

	glBindTexture(GL_TEXTURE_2D, mTextureId);

	// Setup texture properties
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	/*
	 * Load image data into OpenGL:
	 *
	 * target         : Specifies the target texture. Must be GL_TEXTURE_2D.
	 * level          : Specifies the level-of-detail number. Level 0 is the base image level. Level n is the nth mipmap reduction image.
	 * internalformat : Specifies the number of color components in the texture. Must be 1, 2, 3, or 4.
	 * width          : Specifies the width of the texture image. Must be 2^n + 2 * (border) for some integer n.
	 * height         : Specifies the height of the texture image. Must be 2^m + 2 * (border) for some integer m.
	 * border         : Specifies the width of the border. Must be either 0 or 1.
	 * format         : Specifies the format of the pixel data. The following symbolic values are accepted:
	 *                  GL_COLOR_INDEX, GL_RED, GL_GREEN, GL_BLUE, GL_ALPHA, GL_RGB, GL_RGBA, GL_LUMINANCE, GL_LUMINANCE_ALPHA.
	 * type           : Specifies the data type of the pixel data. The following symbolic values are accepted:
	 *                  GL_UNSIGNED_BYTE, GL_BYTE, GL_BITMAP, GL_UNSIGNED_SHORT, GL_SHORT, GL_UNSIGNED_INT, GL_INT, GL_FLOAT.
	 * pixels         : Specifies a pointer to the image data in memory.
	 */

	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, pixels);

	delete [] pixels;

	mWidth  = width;
	mHeight = height;
	mFormat = format;

	LOG_D("Texture::load mWidth:  %d", mWidth);
	LOG_D("Texture::load mHeight: %d", mHeight);
	LOG_D("Texture::load mFormat: %d", mFormat);

	if (glGetError() != GL_NO_ERROR) {
		LOG_E("Error loading texture into OpenGL.");
		unload();
	}
}

void Texture::unload()
{
	if (mTextureId != 0) {
		glDeleteTextures(1, &mTextureId);
		mTextureId = 0;
	}

	mWidth  = 0;
	mHeight = 0;
	mFormat = 0;
}


void Texture::apply()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mTextureId);
}
