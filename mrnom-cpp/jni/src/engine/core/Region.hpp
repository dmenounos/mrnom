#ifndef REGION_HPP
#define REGION_HPP

#include "../../common.h"

namespace engine {

/**
 * Region structure.
 */
class Region {

public:

	Region();

	virtual ~Region();

	/**
	 * Horizontal offset.
	 */
	int32_t getOffsetX() const;
	void setOffsetX(int32_t offsetX);

	/**
	 * Vertical offset.
	 */
	int32_t getOffsetY() const;
	void setOffsetY(int32_t offsetY);

	/**
	 * Grid column width.
	 */
	int32_t getCellWidth() const;
	void setCellWidth(int32_t cellWidth);

	/**
	 * Grid row height.
	 */
	int32_t getCellHeight() const;
	void setCellHeight(int32_t cellHeight);

	/**
	 * Grid column count.
	 */
	int32_t getGridCols() const;
	void setGridCols(int32_t gridCols);

	/**
	 * Grid row count.
	 */
	int32_t getGridRows() const;
	void setGridRows(int32_t gridRows);

private:

	int32_t _offsetX;
	int32_t _offsetY;

	int32_t _cellWidth;
	int32_t _cellHeight;

	int32_t _gridCols;
	int32_t _gridRows;
};

}

#endif
