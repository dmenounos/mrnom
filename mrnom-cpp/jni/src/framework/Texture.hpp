#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "../common.h"
#include "Resource.hpp"

#include <GLES/gl.h>
#include <png.h>

class Texture {

public:

	Texture(Resource resource);

	virtual ~Texture();

	int32_t getWidth();

	int32_t getHeight();

	void load();

	void unload();

	void apply();

protected:

	uint8_t* loadImage();

	static void callback_read(png_structp pngStruct, png_bytep pngData, png_size_t pngSize);

private:

	Resource mResource;
	GLuint mTextureId;
	int32_t mWidth;
	int32_t mHeight;
	GLint mFormat;
};

#endif
