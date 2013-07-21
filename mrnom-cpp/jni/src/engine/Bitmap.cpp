#include "Bitmap.hpp"

namespace engine {

Bitmap::Bitmap(int32_t  width, int32_t  height, int32_t  format, uint8_t* pixels) :
	mWidth(width), mHeight(height), mFormat(format), mPixels(pixels) {
	LOG_D("### Bitmap::Bitmap(%d, %d, %d, ...)", mWidth, mHeight, mFormat);
}

Bitmap::~Bitmap() {
	LOG_D("### Bitmap::~Bitmap()");

	if (mPixels != NULL) {
		delete [] mPixels;
		mPixels = NULL;
	}
}

int32_t Bitmap::getWidth() const {
	return mWidth;
}

int32_t Bitmap::getHeight() const {
	return mHeight;
}

int32_t Bitmap::getFormat() const {
	return mFormat;
}

uint8_t* Bitmap::getPixels() const {
	return mPixels;
}

}
