#include "Sprite.hpp"

#include "./opengl/Texture.hpp"
#include "./opengl/Vertices.hpp"

using namespace engine;

Sprite::Sprite(Texture* texture) :
	Image(texture),
	_position(),
	_textureRegion(),
	_textureRegionAnimator() {

	LOG_D("### Sprite::Sprite()");

	// Default, use the whole texture area.

	_textureRegion.setCellWidth(GRID_CELL_SIZE_AUTO);
	_textureRegion.setCellHeight(GRID_CELL_SIZE_AUTO);

	// Default, use the grid cell count.

	_textureRegionAnimator.setRangeLength(ANIM_RANGE_FULL_GRID);
}

Sprite::~Sprite() {
	LOG_D("$$$ Sprite::~Sprite()");
}

void Sprite::upload() {
	Image::upload();
	LOG_D("--> Sprite::upload()");

	if (GRID_CELL_SIZE_AUTO == _textureRegion.getCellWidth()) {
		_textureRegion.setCellWidth(_texture->getWidth() / _textureRegion.getGridCols());
		LOG_D("--- Sprite::upload() region auto cellWidth: %d", _textureRegion.getCellWidth());
	}

	if (GRID_CELL_SIZE_AUTO == _textureRegion.getCellHeight()) {
		_textureRegion.setCellHeight(_texture->getHeight() / _textureRegion.getGridRows());
		LOG_D("--- Sprite::upload() region auto cellHeight: %d", _textureRegion.getCellHeight());
	}

	if (ANIM_RANGE_FULL_GRID == _textureRegionAnimator.getRangeLength()) {
		_textureRegionAnimator.setRangeLength(_textureRegion.getGridRows() * _textureRegion.getGridCols());
		LOG_D("--- Sprite::upload() animator auto rangeLength: %f", _textureRegionAnimator.getRangeLength());
	}

	init(_textureRegion.getOffsetX(), _textureRegion.getOffsetY(),
	     _textureRegion.getCellWidth(), _textureRegion.getCellHeight());
}

void Sprite::unload() {
	Image::unload();
	LOG_D("--> Sprite::unload()");
}

void Sprite::update(float deltaTime) {
	_textureRegionAnimator.update(deltaTime);
}

void Sprite::render(float deltaTime) {
	int cursor = _textureRegionAnimator.getCursor();
	int cursorRow = cursor / _textureRegion.getGridCols();
	int cursorCol = cursor % _textureRegion.getGridCols();

	// OpenGL renders image data according to the mapped texture coordinates.

	// If the image data were left at the original order, the image top row would
	// render at the bottom row (from 0,0 to 1,0). The image would end up side down.

	// texture     0,1   1,1
	// +-+-+-+      +-+-+-+
	// |0|1|2|      |6|7|8|
	// +-+-+-+      +-+-+-+
	// |3|4|5|  ->  |3|4|5|
	// +-+-+-+      +-+-+-+
	// |6|7|8|      |0|1|2|
	// +-+-+-+      +-+-+-+
	//             0,0   1,0

	// For that, when the image data are loaded, we also invert the row order so as
	// to compensate for the OpenGL inversion.

	//  image       texture     0,1   1,1
	// +-+-+-+      +-+-+-+      +-+-+-+
	// |0|1|2|      |6|7|8|      |0|1|2|
	// +-+-+-+      +-+-+-+      +-+-+-+
	// |3|4|5|  ->  |3|4|5|  ->  |3|4|5|
	// +-+-+-+      +-+-+-+      +-+-+-+
	// |6|7|8|      |0|1|2|      |6|7|8|
	// +-+-+-+      +-+-+-+      +-+-+-+
	//                          0,0   1,0

	// However the region grid is arranged according to the original image order.
	// So we have to also invert the cursorRow order to match the inverted texture.

	cursorRow = _textureRegion.getGridRows() - cursorRow - 1;

	// TEXTURE coordinates are normalized.

	float horRatio = 1.0f / _texture->getWidth();  // coords / pixel
	float verRatio = 1.0f / _texture->getHeight(); // coords / pixel

	float horOffset = _textureRegion.getOffsetX() * horRatio; // coords
	float verOffset = _textureRegion.getOffsetY() * verRatio; // coords

	float horCell = _textureRegion.getCellWidth() * horRatio;  // coords / col
	float verCell = _textureRegion.getCellHeight() * verRatio; // coords / row

	GLfloat* vertices = _vertices->getVertices();

	// texture coordinates; lower left
	vertices[02] = (cursorCol + 0) * horCell; // x
	vertices[03] = (cursorRow + 0) * verCell; // y

	// texture coordinates; lower right
	vertices[06] = (cursorCol + 1) * horCell; // x
	vertices[07] = (cursorRow + 0) * verCell; // y

	// texture coordinates; upper right
	vertices[10] = (cursorCol + 1) * horCell; // x
	vertices[11] = (cursorRow + 1) * verCell; // y

	// texture coordinates; upper left
	vertices[14] = (cursorCol + 0) * horCell; // x
	vertices[15] = (cursorRow + 1) * verCell; // y

	//	LOG_D("--- Sprite::render() [ %d, %d ] ( %f, %f : %f, %f )",
	//	      cursorCol, cursorRow, vertices[02], vertices[03], vertices[10], vertices[11]);

	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glTranslatef(horOffset, verOffset, 0);

	Image::render(deltaTime);
}

Vector& Sprite::getPosition() {
	return _position;
}

Region& Sprite::getTextureRegion() {
	return _textureRegion;
}

Animator& Sprite::getTextureRegionAnimator() {
	return _textureRegionAnimator;
}
