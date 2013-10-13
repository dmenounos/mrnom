#include "Bitmap.hpp"

using namespace engine;

Bitmap::Bitmap(int32_t  width, int32_t  height, int32_t  format, uint8_t* pixels) :
	_width(width), _height(height), _format(format), _pixels(pixels) {
	// LOG_D("### Bitmap::Bitmap(%d, %d, %d, ...)", mWidth, mHeight, mFormat);
}

Bitmap::~Bitmap() {
	// LOG_D("### Bitmap::~Bitmap()");

	if (_pixels != NULL) {
		delete [] _pixels;
	}
}

int32_t Bitmap::getWidth() const {
	return _width;
}

int32_t Bitmap::getHeight() const {
	return _height;
}

int32_t Bitmap::getFormat() const {
	return _format;
}

uint8_t* Bitmap::getPixels() const {
	return _pixels;
}
