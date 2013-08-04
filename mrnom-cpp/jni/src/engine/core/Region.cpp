#include "Region.hpp"

using namespace engine;

Region::Region() :
	mX(0), mY(0),
	mWidth(0), mHeight(0),
	mGridCols(1), mGridRows(1) {
	// LOG_D("### Region::Region()");
}

Region::~Region() {
	// LOG_D("### Region::~Region()");
}

int32_t Region::getX() const {
	return mX;
}

void Region::setX(int32_t x) {
	mX = x;
}

int32_t Region::getY() const {
	return mY;
}

void Region::setY(int32_t y) {
	mY = y;
}

int32_t Region::getWidth() const {
	return mWidth;
}

void Region::setWidth(int32_t width) {
	mWidth = width;
}

int32_t Region::getHeight() const {
	return mHeight;
}

void Region::setHeight(int32_t height) {
	mHeight = height;
}

int32_t Region::getGridCols() const {
	return mGridCols;
}

void Region::setGridCols(int32_t gridCols) {
	assert(gridCols > 0);
	mGridCols = gridCols;
}

int32_t Region::getGridRows() const {
	return mGridRows;
}

void Region::setGridRows(int32_t gridRows) {
	assert(gridRows > 0);
	mGridRows = gridRows;
}

int32_t Region::getCellWidth() const {
	return mWidth / mGridCols;
}

int32_t Region::getCellHeight() const {
	return mHeight / mGridRows;
}
