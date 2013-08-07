#include "Sprite.hpp"

#include "./opengl/Texture.hpp"
#include "./opengl/Vertices.hpp"

using namespace engine;

Sprite::Sprite(Texture* texture) :
	mPosition(), mRegion(), mAnimator(),
	mVertices(0), mTexture(texture) {

	LOG_D("### Sprite::Sprite()");

	// Default, use the texture whole area.

	mRegion.setCellWidth(AUTO_SIZE);
	mRegion.setCellHeight(AUTO_SIZE);

	// Default, use the grid cell count.

	mAnimator.setRangeLength(AUTO_RANGE);
}

Sprite::~Sprite() {
	LOG_D("### Sprite::~Sprite()");
}

void Sprite::reload() {
	LOG_D("--> Sprite::reload()");

	mTexture->reload();

	if (AUTO_SIZE == mRegion.getCellWidth()) {
		mRegion.setCellWidth(mTexture->getWidth() / mRegion.getGridCols());
		LOG_D("--- Sprite::reload() region auto width: %d", mRegion.getCellWidth());
	}

	if (AUTO_SIZE == mRegion.getCellHeight()) {
		mRegion.setCellHeight(mTexture->getHeight() / mRegion.getGridRows());
		LOG_D("--- Sprite::reload() region auto height: %d", mRegion.getCellHeight());
	}

	if (AUTO_RANGE == mAnimator.getRangeLength()) {
		mAnimator.setRangeLength(mRegion.getGridRows() * mRegion.getGridCols());
		LOG_D("--- Sprite::reload() animator auto rangeLength: %f", mAnimator.getRangeLength());
	}

	// VERTEX coordinates are non-normalized
	// and are based on "camera" units, i.e. glOrthof(...).

	float colSize = mRegion.getCellWidth();
	float rowSize = mRegion.getCellHeight();

	// TEXTURE coordinates are normalized.

	float horRatio = 1.0f / mTexture->getWidth();
	float verRatio = 1.0f / mTexture->getHeight();

	float horCell = mRegion.getCellWidth() * horRatio;
	float verCell = mRegion.getCellHeight() * verRatio;

	float horOffset = mRegion.getOffsetX() * horRatio;
	float verOffset = mRegion.getOffsetY() * verRatio;

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

	mVertices = new Vertices(false, true);
	mVertices->copyVertices(vertices, sizeof(vertices));
	mVertices->copyIndices(indices, sizeof(indices));
}

void Sprite::unload() {
	LOG_D("--> Sprite::unload()");

	mTexture->unload();

	delete mVertices;
}

void Sprite::update(float deltaTime) {
	mAnimator.update(deltaTime);
}

void Sprite::render(float deltaTime) {
	mTexture->rebind();

	int cursor = mAnimator.getCursor();
	int cursorCol = cursor % mRegion.getGridCols();
	int cursorRow = cursor / mRegion.getGridCols();

	// We have to flip the row cursor because in OpenGL
	// texture coordinates map to top = 1 and bottom = 0.

	cursorRow = mRegion.getGridRows() - cursorRow - 1;

	// TEXTURE coordinates are normalized.

	float horRatio = 1.0f / mTexture->getWidth();
	float verRatio = 1.0f / mTexture->getHeight();

	float horCell = mRegion.getCellWidth() * horRatio;
	float verCell = mRegion.getCellHeight() * verRatio;

	float horOffset = mRegion.getOffsetX() * horRatio;
	float verOffset = mRegion.getOffsetY() * verRatio;

	GLfloat* vertices = mVertices->getVertices();

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

	mVertices->rebind();
	mVertices->render(0, 6);
	mVertices->unbind();

	mTexture->unbind();
}

Vector& Sprite::getPosition() {
	return mPosition;
}

Region& Sprite::getRegion() {
	return mRegion;
}

Animator& Sprite::getAnimator() {
	return mAnimator;
}
