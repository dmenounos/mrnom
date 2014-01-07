#ifndef REGION_HPP
#define REGION_HPP

#include "../../common.h"

namespace engine {

/**
 * Used to describe a grid arrangement over some area.
 */
class Region {

public:

	Region();

	virtual ~Region();

	/**
	 * Outer horizontal offset.
	 */
	int32_t getOffsetX() const;
	void setOffsetX(int32_t offsetX);

	/**
	 * Outer vertical offset.
	 */
	int32_t getOffsetY() const;
	void setOffsetY(int32_t offsetY);

	/**
	 * Inner grid column width ( pixels / column ).
	 */
	int32_t getCellWidth() const;
	void setCellWidth(int32_t cellWidth);

	/**
	 * Inner grid row height ( pixels / row ).
	 */
	int32_t getCellHeight() const;
	void setCellHeight(int32_t cellHeight);

	/**
	 * Inner grid column count.
	 */
	int32_t getGridCols() const;
	void setGridCols(int32_t gridCols);

	/**
	 * Inner grid row count.
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
