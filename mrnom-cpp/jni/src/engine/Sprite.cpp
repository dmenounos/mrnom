#include "Sprite.hpp"

#include "./opengl/Texture.hpp"
#include "./opengl/Vertices.hpp"

using namespace engine;

Sprite::Sprite(Texture* texture) :
	mPosition(), mRegion(), mAnimation(),
	mTexture(texture) {

	LOG_D("### Sprite::Sprite()");

	// Default, use the texture whole area.

	mRegion.setWidth(AUTO_SIZE);
	mRegion.setHeight(AUTO_SIZE);

	// Default, use the grid cell count.

	mAnimation.setRangeLength(AUTO_RANGE);
}

Sprite::~Sprite() {
	LOG_D("### Sprite::~Sprite()");
}

void Sprite::reload() {
	LOG_D("--> Sprite::reload()");

	mTexture->reload();

	if (AUTO_SIZE == mRegion.getWidth()) {
		mRegion.setWidth(mTexture->getWidth());
		LOG_D("--- Sprite::reload() region auto width: %d", mRegion.getWidth());
	}

	if (AUTO_SIZE == mRegion.getHeight()) {
		mRegion.setHeight(mTexture->getHeight());
		LOG_D("--- Sprite::reload() region auto height: %d", mRegion.getHeight());
	}

	if (AUTO_RANGE == mAnimation.getRangeLength()) {
		mAnimation.setRangeLength(mRegion.getGridRows() * mRegion.getGridCols());
		LOG_D("--- Sprite::reload() animations auto rangeLength: %f", mAnimation.getRangeLength());
	}

	// NOTICE, we map the coordinates to the grid-cell width & height
	// and not to the full width & height.

	// VERTEX coordinates are non-normalized
	// and are based on "camera" units, i.e. glOrthof(...).

	float colSize = mRegion.getCellWidth();
	float rowSize = mRegion.getCellHeight();

	// TEXTURE coordinates are normalized.

	float colRatio = 1.0f / mRegion.getGridCols();
	float rowRatio = 1.0f / mRegion.getGridRows();

	GLfloat vertices[] = {
		0.0f,    0.0f,      0.0f,     0.0f,
		colSize, 0.0f,      colRatio, 0.0f,
		colSize, rowSize,   colRatio, rowRatio,
		0.0f,    rowSize,   0.0f,     rowRatio
	};

	size_t verticesBytes = sizeof(vertices);
	size_t verticesLength = verticesBytes / sizeof(GLfloat);

	GLfloat* verticesHeap = new GLfloat[verticesLength];
	memcpy(verticesHeap, vertices, verticesBytes);

	GLushort indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	size_t indicesBytes = sizeof(indices);
	size_t indicesLength = indicesBytes / sizeof(GLfloat);

	GLushort* indicesHeap = new GLushort[indicesLength];
	memcpy(indicesHeap, indices, indicesBytes);

	mVertices = new Vertices(false, true);
	mVertices->setVertices(verticesHeap);
	mVertices->setIndices(indicesHeap);
}

void Sprite::unload() {
	LOG_D("--> Sprite::unload()");

	mTexture->unload();

	delete mVertices;
}

void Sprite::update(float deltaTime) {
	mAnimation.update(deltaTime);
}

void Sprite::render(float deltaTime) {
	mTexture->rebind();

	// TEXTURE coordinates are normalized.

	float colRatio = 1.0f / mRegion.getGridCols();
	float rowRatio = 1.0f / mRegion.getGridRows();

	int cursor = mAnimation.getCursor();
	int cursorCol = cursor % mRegion.getGridCols();
	int cursorRow = cursor / mRegion.getGridCols();

	LOG_D("--- Sprite::render() col: %d row: %d", cursorCol, cursorRow);

	mVertices->rebind();
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glTranslatef(cursorCol * colRatio, cursorRow * rowRatio, 0);
	mVertices->render(0, 6);
	mVertices->unbind();

	mTexture->unbind();
}

Region& Sprite::getRegion() {
	return mRegion;
}

Animation& Sprite::getAnimation() {
	return mAnimation;
}


Vector& Sprite::getPosition() {
	return mPosition;
}
