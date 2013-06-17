#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "../common.h"

class Texture {

public:

	Texture();

	virtual ~Texture();

	int32_t getWidth() const;

	int32_t getHeight() const;

	int32_t getFormat() const;

	/**
	 * Initializes texture meta data.
	 * Maintains OpenGL texture handle.
	 * Transfers pixel buffer into OpenGL.
	 */
	void load(
		int32_t  width,
		int32_t  height,
		int32_t  format,
		uint8_t* pixels);

	/**
	 * Clears texture meta data and handle.
	 * Deletes OpenGL pixel buffer.
	 */
	void unload();

	void apply();

private:

	int32_t mWidth;
	int32_t mHeight;
	int32_t mFormat;
	uint32_t mTextureId;
};

#endif
