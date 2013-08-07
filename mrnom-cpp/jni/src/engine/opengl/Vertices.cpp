#include "Vertices.hpp"

using namespace engine;

Vertices::Vertices(bool hasColor, bool hasTexture) :
	mHasColor(hasColor), mHasTexture(hasTexture),
	mVertices(0), mVerticesLength(0),
	mIndices(0), mIndicesLength(0),
	mVerticesId(0), mIndicesId(0) {

	int mVertexComponents = 2;

	if (hasColor) {
		mVertexComponents += 4;
	}

	if (hasTexture) {
		mVertexComponents += 2;
	}

	mVertexBytes = mVertexComponents * sizeof(GLfloat);

	LOG_D("### Vertices::Vertices(mVertexComponents: %d, mVertexBytes: %zu)",
	      mVertexComponents, mVertexBytes);
}

Vertices::~Vertices() {
	LOG_D("### Vertices::~Vertices()");
	unload();
}

void Vertices::copyVertices(GLfloat* data, size_t dataBytes) {
	LOG_D("--> Vertices::copyVertices(dataBytes: %zu)", dataBytes);
	mVerticesLength = dataBytes / sizeof(GLfloat);
	mVertices = new GLfloat[mVerticesLength];
	memcpy(mVertices, data, dataBytes);
}

void Vertices::copyIndices(GLushort* data, size_t dataBytes) {
	LOG_D("--> Vertices::copyIndices(dataBytes: %zu)", dataBytes);
	mIndicesLength = dataBytes / sizeof(GLushort);
	mIndices = new GLushort[mIndicesLength];
	memcpy(mIndices, data, dataBytes);
}

void Vertices::loadVertices(GLfloat data[], size_t dataBytes) {
	LOG_D("--> Vertices::loadVertices(dataBytes: %zu)", dataBytes);

	glGenBuffers(1, &mVerticesId);
	glBindBuffer(GL_ARRAY_BUFFER, mVerticesId);

	// Upload happens in terms of bytes.
	// Notice that OpenGL does not know the data type yet.

	glBufferData(GL_ARRAY_BUFFER, dataBytes, data, GL_STATIC_DRAW);

	if (glGetError() != GL_NO_ERROR) {
		LOG_E("Error uploading vertices into OpenGL.");
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Vertices::loadIndices(GLushort data[], size_t dataBytes) {
	LOG_D("--> Vertices::loadIndices(dataBytes: %zu)", dataBytes);

	glGenBuffers(1, &mIndicesId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndicesId);

	// Upload happens in terms of bytes.
	// Notice that OpenGL does not know the data type yet.

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataBytes, data, GL_STATIC_DRAW);

	if (glGetError() != GL_NO_ERROR) {
		LOG_E("Error uploading indices into OpenGL.");
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Vertices::unload() {
	LOG_D("--> Vertices::unload()");

	if (mVerticesId) {
		glDeleteBuffers(1, &mVerticesId);
	}

	if (mIndicesId) {
		glDeleteBuffers(1, &mIndicesId);
	}
}

void Vertices::rebind() {
	if (mVerticesId) {
		LOG_D("--- Vertices::rebind() mVerticesId: %d", mVerticesId);
		glBindBuffer(GL_ARRAY_BUFFER, mVerticesId);
	}

	if (mIndicesId) {
		LOG_D("--- Vertices::rebind() mIndicesId: %d", mIndicesId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndicesId);
	}

	// If vertex buffer is bound, "offset" will be used as plain offset,
	// -- in which case "mVertices" should be equal to zero --
	// otherwise, "offset" will be used as a pointer + offset.

	GLfloat* offsetPtr = mVertices;

	// Now OpenGL knows the vertices data type (but still not the indices).

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, mVertexBytes, offsetPtr);
	offsetPtr += 2;

	if (mHasColor) {
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(4, GL_FLOAT, mVertexBytes, offsetPtr);
		offsetPtr += 4;
	}

	if (mHasTexture) {
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, mVertexBytes, offsetPtr);
	}
}

void Vertices::unbind() {
	if (mHasTexture) {
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}

	if (mHasColor) {
		glDisableClientState(GL_COLOR_ARRAY);
	}

	glDisableClientState(GL_VERTEX_ARRAY);

	if (mVerticesId) {
		LOG_D("--- Vertices::unbind() mVerticesId: %d", mVerticesId);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	if (mIndicesId) {
		LOG_D("--- Vertices::unbind() mIndicesId: %d", mIndicesId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}

void Vertices::render(int32_t offset, int32_t length) {
	if (mIndicesId || mIndices) {

		// If indices buffer is bound, "offset" will be used as plain offset,
		// -- in which case "mIndices" should be equal to zero --
		// otherwise, "offset" will be used as a pointer + offset.

		GLushort* offsetPtr = mIndices + offset;
		glDrawElements(GL_TRIANGLES, length, GL_UNSIGNED_SHORT, offsetPtr);
	}
	else if (mVerticesId || mVertices) {
		glDrawArrays(GL_TRIANGLES, offset, length);
	}
}

GLfloat* Vertices::getVertices() const {
	return mVertices;
}

int32_t Vertices::getVerticesLength() const {
	return mVerticesLength;
}

GLushort* Vertices::getIndices() const {
	return mIndices;
}

int32_t Vertices::getIndicesLength() const {
	return mIndicesLength;
}
