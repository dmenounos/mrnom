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
	int32_t getX() const;
	void setX(int32_t x);

	/**
	 * Vertical offset.
	 */
	int32_t getY() const;
	void setY(int32_t y);

	/**
	 * Horizontal length.
	 */
	int32_t getWidth() const;
	void setWidth(int32_t width);

	/**
	 * Vertical length.
	 */
	int32_t getHeight() const;
	void setHeight(int32_t height);

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

	/**
	 * Grid column width.
	 */
	int32_t getCellWidth() const;

	/**
	 * Grid row height.
	 */
	int32_t getCellHeight() const;

private:

	int32_t mX;
	int32_t mY;

	int32_t mWidth;
	int32_t mHeight;

	int32_t mGridCols;
	int32_t mGridRows;
};

}

#endif
