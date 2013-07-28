#ifndef BITMAP_HPP
#define BITMAP_HPP

#include "../common.h"

namespace engine {

/**
 * Picture data container.
 */
class Bitmap {

public:

	Bitmap(int32_t  width, int32_t  height,
	       int32_t  format, uint8_t* pixels);

	virtual ~Bitmap();

	int32_t getWidth() const;

	int32_t getHeight() const;

	int32_t getFormat() const;

	uint8_t* getPixels() const;

private:

	int32_t mWidth;
	int32_t mHeight;
	int32_t mFormat;
	uint8_t* mPixels;
};

}

#endif
