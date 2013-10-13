#include "Sprite.hpp"

#include "./opengl/Texture.hpp"
#include "./opengl/Vertices.hpp"

using namespace engine;

Sprite::Sprite(Texture* texture) :
	_position(), _region(), _animator(),
	_vertices(0), _texture(texture) {

	LOG_D("### Sprite::Sprite()");

	// Default, use the texture whole area.

	_region.setCellWidth(AUTO_SIZE);
	_region.setCellHeight(AUTO_SIZE);

	// Default, use the grid cell count.

	_animator.setRangeLength(AUTO_RANGE);
}

Sprite::~Sprite() {
	LOG_D("### Sprite::~Sprite()");
}

void Sprite::reload() {
	LOG_D("--> Sprite::reload()");

	_texture->upload();

	if (AUTO_SIZE == _region.getCellWidth()) {
		_region.setCellWidth(_texture->getWidth() / _region.getGridCols());
		LOG_D("--- Sprite::reload() region auto width: %d", _region.getCellWidth());
	}

	if (AUTO_SIZE == _region.getCellHeight()) {
		_region.setCellHeight(_texture->getHeight() / _region.getGridRows());
		LOG_D("--- Sprite::reload() region auto height: %d", _region.getCellHeight());
	}

	if (AUTO_RANGE == _animator.getRangeLength()) {
		_animator.setRangeLength(_region.getGridRows() * _region.getGridCols());
		LOG_D("--- Sprite::reload() animator auto rangeLength: %f", _animator.getRangeLength());
	}

	// VERTEX coordinates are non-normalized
	// and are based on "camera" units, i.e. glOrthof(...).

	float colSize = _region.getCellWidth();
	float rowSize = _region.getCellHeight();

	// TEXTURE coordinates are normalized.

	float horRatio = 1.0f / _texture->getWidth();
	float verRatio = 1.0f / _texture->getHeight();

	float horCell = _region.getCellWidth() * horRatio;
	float verCell = _region.getCellHeight() * verRatio;

	float horOffset = _region.getOffsetX() * horRatio;
	float verOffset = _region.getOffsetY() * verRatio;

	float colText = horCell + horOffset;
	float rowText = verCell + verOffset;

	GLfloat vertices[] = {
		0.0f,    0.0f,     0.0f,    0.0f,     // lower left
		colSize, 0.0f,     colText, 0.0f,     // lower right
		colSize, rowSize,  colText, rowText,  // upper right
		0.0f,    rowSize,  0.0f,    rowText   // upper left
	};

	GLushort indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	_vertices = new Vertices(false, true);
	_vertices->copyVertices(vertices, sizeof(vertices));
	_vertices->copyIndices(indices, sizeof(indices));
}

void Sprite::unload() {
	LOG_D("--> Sprite::unload()");

	_texture->unload();

	delete _vertices;
}

void Sprite::update(float deltaTime) {
	_animator.update(deltaTime);
}

void Sprite::render(float deltaTime) {
	_texture->rebind();

	int cursor = _animator.getCursor();
	int cursorCol = cursor % _region.getGridCols();
	int cursorRow = cursor / _region.getGridCols();

	// We have to flip the row cursor because in OpenGL
	// texture coordinates map to top = 1 and bottom = 0.

	cursorRow = _region.getGridRows() - cursorRow - 1;

	// TEXTURE coordinates are normalized.

	float horRatio = 1.0f / _texture->getWidth();
	float verRatio = 1.0f / _texture->getHeight();

	float horCell = _region.getCellWidth() * horRatio;
	float verCell = _region.getCellHeight() * verRatio;

	float horOffset = _region.getOffsetX() * horRatio;
	float verOffset = _region.getOffsetY() * verRatio;

	GLfloat* vertices = _vertices->getVertices();

	vertices[02] = (cursorCol + 0) * horCell; // lower left x
	vertices[03] = (cursorRow + 0) * verCell; // lower left y

	vertices[06] = (cursorCol + 1) * horCell; // lower right x
	vertices[07] = (cursorRow + 0) * verCell; // lower right y

	vertices[10] = (cursorCol + 1) * horCell; // upper right x
	vertices[11] = (cursorRow + 1) * verCell; // upper right y

	vertices[14] = (cursorCol + 0) * horCell; // upper left x
	vertices[15] = (cursorRow + 1) * verCell; // upper left y

//	LOG_D("--- Sprite::render() [ %d, %d ] ( %f, %f : %f, %f )",
//	      cursorCol, cursorRow, vertices[02], vertices[03], vertices[10], vertices[11]);

	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glTranslatef(horOffset, verOffset, 0);

	_vertices->rebind();
	_vertices->render(0, 6);
	_vertices->unbind();

	_texture->unbind();
}

Vector& Sprite::getPosition() {
	return _position;
}

Region& Sprite::getRegion() {
	return _region;
}

Animator& Sprite::getAnimator() {
	return _animator;
}
