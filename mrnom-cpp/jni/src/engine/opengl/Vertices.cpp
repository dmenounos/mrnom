#include "Vertices.hpp"

using namespace engine;

Vertices::Vertices(bool hasColor, bool hasTexture) :
	mHasColor(hasColor), mHasTexture(hasTexture),
	mVerticesId(0), mIndicesId(0),
	mVertices(0), mIndices(0) {

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


void Vertices::setVertices(GLfloat* data) {
	mVertices = data;
}


void Vertices::loadVertices(GLfloat data[], int32_t dataLength) {
	LOG_D("--> Vertices::loadVertices(dataLength: %d)", dataLength);

	glGenBuffers(1, &mVerticesId);
	glBindBuffer(GL_ARRAY_BUFFER, mVerticesId);

	// upload happens in terms of bytes
	size_t dataBytes = dataLength * sizeof(GLfloat);
	glBufferData(GL_ARRAY_BUFFER, dataBytes, data, GL_STATIC_DRAW);

	if (glGetError() != GL_NO_ERROR) {
		LOG_E("Error uploading vertices into OpenGL.");
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Vertices::setIndices(GLushort* data) {
	mIndices = data;
}

void Vertices::loadIndices(GLushort data[], int32_t dataLength) {
	LOG_D("--> Vertices::loadIndices(dataLength: %d)", dataLength);

	glGenBuffers(1, &mIndicesId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndicesId);

	// upload happens in terms of bytes
	size_t dataBytes = dataLength * sizeof(GLushort);
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
	GLfloat* offset = mVertices;
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, mVertexBytes, offset);
	offset += 2;

	if (mHasColor) {
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(4, GL_FLOAT, mVertexBytes, offset);
		offset += 4;
	}

	if (mHasTexture) {
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, mVertexBytes, offset);
	}

	if (mIndicesId) {
		LOG_D("--- Vertices::rebind() mIndicesId: %d", mIndicesId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndicesId);
	}
	else if (mVerticesId) {
		LOG_D("--- Vertices::rebind() mVerticesId: %d", mVerticesId);
		glBindBuffer(GL_ARRAY_BUFFER, mVerticesId);
	}
}

void Vertices::unbind() {
	if (mIndicesId) {
		LOG_D("--- Vertices::unbind() mIndicesId: %d", mIndicesId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	else if (mVerticesId) {
		LOG_D("--- Vertices::unbind() mVerticesId: %d", mVerticesId);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	if (mHasTexture) {
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}

	if (mHasColor) {
		glDisableClientState(GL_COLOR_ARRAY);
	}

	glDisableClientState(GL_VERTEX_ARRAY);
}

void Vertices::render(int32_t offset, int32_t length) {
	if (mIndicesId) {
		// LOG_D("--- Vertices::render(mIndicesId) offset: %d, length %d", offset, length);
		glDrawElements(GL_TRIANGLES, length, GL_UNSIGNED_SHORT, (GLvoid*) offset);
	}
	else if (mIndices) {
		// LOG_D("--- Vertices::render(mIndices) mIndices: %zu, length %d", mIndices, length);
		glDrawElements(GL_TRIANGLES, length, GL_UNSIGNED_SHORT, mIndices);
	}
	else if (mVerticesId || mVertices) {
		glDrawArrays(GL_TRIANGLES, offset, length);
	}
}
