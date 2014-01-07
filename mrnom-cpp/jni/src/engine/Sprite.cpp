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
}

Sprite::~Sprite() {
	LOG_D("$$$ Sprite::~Sprite()");
}

void Sprite::upload() {
	Image::upload();
	LOG_D("--> Sprite::upload()");

	if (_textureRegion.getCellWidth() == 0) {
		// Calculate the region cell width over the whole texture.
		_textureRegion.setCellWidth(getTexture()->getWidth() / _textureRegion.getGridCols());
		LOG_D("--- Sprite::upload() region auto cellWidth: %d", _textureRegion.getCellWidth());
	}
	else if (_textureRegion.getCellWidth() < 0) {
		// Calculate the region cell width over the provided negative value.
		_textureRegion.setCellWidth(- _textureRegion.getCellWidth() / _textureRegion.getGridCols());
		LOG_D("--- Sprite::upload() region auto cellWidth: %d", _textureRegion.getCellWidth());
	}

	if (_textureRegion.getCellHeight() == 0) {
		// Calculate the region cell height over the whole texture.
		_textureRegion.setCellHeight(getTexture()->getHeight() / _textureRegion.getGridRows());
		LOG_D("--- Sprite::upload() region auto cellHeight: %d", _textureRegion.getCellHeight());
	}
	else if (_textureRegion.getCellHeight() < 0) {
		// Calculate the region cell height over the provided negative value.
		_textureRegion.setCellHeight(- _textureRegion.getCellHeight() / _textureRegion.getGridRows());
		LOG_D("--- Sprite::upload() region auto cellHeight: %d", _textureRegion.getCellHeight());
	}

	if (_textureRegionAnimator.getRangeLength() == 0) {
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
	int cursor = _textureRegionAnimator.getRangeCursor();
	int cursorRow = cursor / _textureRegion.getGridCols();
	int cursorCol = cursor % _textureRegion.getGridCols();

	// OpenGL renders image data according to the mapped texture coordinates.

	// If the image data were left at the original order, the image top row would
	// render at the bottom row. The image would end up side down.

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

	// Calculate cell pixels to coordinates:

	// pixels   coords
	// ------ * ------
	// cell     pixel

	float frameWCoords = _textureRegion.getCellWidth()  * getHorTextureRatio(); // coords / col
	float frameHCoords = _textureRegion.getCellHeight() * getVerTextureRatio(); // coords / row

	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glTranslatef(cursorCol * frameWCoords, cursorRow * frameHCoords, 0);

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
