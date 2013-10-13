#include "Vertices.hpp"

using namespace engine;

Vertices::Vertices(bool hasColor, bool hasTexture) :
	_hasColor(hasColor), _hasTexture(hasTexture),
	_vertices(0), _verticesLength(0),
	_indices(0), _indicesLength(0),
	_verticesId(0), _indicesId(0) {

	int mVertexComponents = 2;

	if (hasColor) {
		mVertexComponents += 4;
	}

	if (hasTexture) {
		mVertexComponents += 2;
	}

	_vertexBytes = mVertexComponents * sizeof(GLfloat);

	LOG_D("### Vertices::Vertices(mVertexComponents: %d, mVertexBytes: %zu)",
	      mVertexComponents, _vertexBytes);
}

Vertices::~Vertices() {
	LOG_D("### Vertices::~Vertices()");
	unload();
}

void Vertices::copyVertices(GLfloat* data, size_t dataBytes) {
	LOG_D("--> Vertices::copyVertices(dataBytes: %zu)", dataBytes);
	_verticesLength = dataBytes / sizeof(GLfloat);
	_vertices = new GLfloat[_verticesLength];
	memcpy(_vertices, data, dataBytes);
}

void Vertices::copyIndices(GLushort* data, size_t dataBytes) {
	LOG_D("--> Vertices::copyIndices(dataBytes: %zu)", dataBytes);
	_indicesLength = dataBytes / sizeof(GLushort);
	_indices = new GLushort[_indicesLength];
	memcpy(_indices, data, dataBytes);
}

void Vertices::uploadVertices(GLfloat data[], size_t dataBytes) {
	LOG_D("--> Vertices::uploadVertices(dataBytes: %zu)", dataBytes);

	glGenBuffers(1, &_verticesId);
	glBindBuffer(GL_ARRAY_BUFFER, _verticesId);

	// Upload happens in terms of bytes.
	// Notice that OpenGL does not know the data type yet.

	glBufferData(GL_ARRAY_BUFFER, dataBytes, data, GL_STATIC_DRAW);

	if (glGetError() != GL_NO_ERROR) {
		LOG_E("Error uploading vertices into OpenGL.");
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Vertices::uploadIndices(GLushort data[], size_t dataBytes) {
	LOG_D("--> Vertices::uploadIndices(dataBytes: %zu)", dataBytes);

	glGenBuffers(1, &_indicesId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indicesId);

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

	if (_verticesId) {
		glDeleteBuffers(1, &_verticesId);
	}

	if (_indicesId) {
		glDeleteBuffers(1, &_indicesId);
	}
}

void Vertices::rebind() {
	if (_verticesId) {
		LOG_D("--- Vertices::rebind() mVerticesId: %d", _verticesId);
		glBindBuffer(GL_ARRAY_BUFFER, _verticesId);
	}

	if (_indicesId) {
		LOG_D("--- Vertices::rebind() mIndicesId: %d", _indicesId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indicesId);
	}

	// If vertex buffer is bound, "offset" will be used as plain offset,
	// -- in which case "mVertices" should be equal to zero --
	// otherwise, "offset" will be used as a pointer + offset.

	GLfloat* offsetPtr = _vertices;

	// Now OpenGL knows the vertices data type (but still not the indices).

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, _vertexBytes, offsetPtr);
	offsetPtr += 2;

	if (_hasColor) {
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(4, GL_FLOAT, _vertexBytes, offsetPtr);
		offsetPtr += 4;
	}

	if (_hasTexture) {
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, _vertexBytes, offsetPtr);
	}
}

void Vertices::unbind() {
	if (_hasTexture) {
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}

	if (_hasColor) {
		glDisableClientState(GL_COLOR_ARRAY);
	}

	glDisableClientState(GL_VERTEX_ARRAY);

	if (_verticesId) {
		LOG_D("--- Vertices::unbind() mVerticesId: %d", _verticesId);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	if (_indicesId) {
		LOG_D("--- Vertices::unbind() mIndicesId: %d", _indicesId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}

void Vertices::render(int32_t offset, int32_t length) {
	if (_indicesId || _indices) {

		// If indices buffer is bound, "offset" will be used as plain offset,
		// -- in which case "mIndices" should be equal to zero --
		// otherwise, "offset" will be used as a pointer + offset.

		GLushort* offsetPtr = _indices + offset;
		glDrawElements(GL_TRIANGLES, length, GL_UNSIGNED_SHORT, offsetPtr);
	}
	else if (_verticesId || _vertices) {
		glDrawArrays(GL_TRIANGLES, offset, length);
	}
}

GLfloat* Vertices::getVertices() const {
	return _vertices;
}

int32_t Vertices::getVerticesLength() const {
	return _verticesLength;
}

GLushort* Vertices::getIndices() const {
	return _indices;
}

int32_t Vertices::getIndicesLength() const {
	return _indicesLength;
}
