#include "Region.hpp"

using namespace engine;

Region::Region() :
	mOffsetX(0), mOffsetY(0),
	mCellWidth(0), mCellHeight(0),
	mGridCols(1), mGridRows(1) {
	// LOG_D("### Region::Region()");
}

Region::~Region() {
	// LOG_D("### Region::~Region()");
}

int32_t Region::getOffsetX() const {
	return mOffsetX;
}

void Region::setOffsetX(int32_t offsetX) {
	mOffsetX = offsetX;
}

int32_t Region::getOffsetY() const {
	return mOffsetY;
}

void Region::setOffsetY(int32_t offsetY) {
	mOffsetY = offsetY;
}

int32_t Region::getCellWidth() const {
	return mCellWidth;
}

void Region::setCellWidth(int32_t cellWidth) {
	mCellWidth = cellWidth;
}

int32_t Region::getCellHeight() const {
	return mCellHeight;
}

void Region::setCellHeight(int32_t cellHeight) {
	mCellHeight = cellHeight;
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
