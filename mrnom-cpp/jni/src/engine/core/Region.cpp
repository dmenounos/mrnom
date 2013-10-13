#include "Region.hpp"

using namespace engine;

Region::Region() :
	_offsetX(0), _offsetY(0),
	_cellWidth(0), _cellHeight(0),
	_gridCols(1), _gridRows(1) {
	// LOG_D("### Region::Region()");
}

Region::~Region() {
	// LOG_D("### Region::~Region()");
}

int32_t Region::getOffsetX() const {
	return _offsetX;
}

void Region::setOffsetX(int32_t offsetX) {
	_offsetX = offsetX;
}

int32_t Region::getOffsetY() const {
	return _offsetY;
}

void Region::setOffsetY(int32_t offsetY) {
	_offsetY = offsetY;
}

int32_t Region::getCellWidth() const {
	return _cellWidth;
}

void Region::setCellWidth(int32_t cellWidth) {
	_cellWidth = cellWidth;
}

int32_t Region::getCellHeight() const {
	return _cellHeight;
}

void Region::setCellHeight(int32_t cellHeight) {
	_cellHeight = cellHeight;
}

int32_t Region::getGridCols() const {
	return _gridCols;
}

void Region::setGridCols(int32_t gridCols) {
	assert(gridCols > 0);
	_gridCols = gridCols;
}

int32_t Region::getGridRows() const {
	return _gridRows;
}

void Region::setGridRows(int32_t gridRows) {
	assert(gridRows > 0);
	_gridRows = gridRows;
}
