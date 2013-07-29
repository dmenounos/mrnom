#include "Vertices.hpp"

namespace engine {

Vertices::Vertices(bool hasColor, bool hasTexture) :
	mHasColor(hasColor), mHasTexture(hasTexture),
	mVerticesId(0), mIndicesId(0),
	mDrawOffset(0), mDrawLength(0) {

	mVertexComponents = 2;

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

void Vertices::loadVertices(GLfloat vertices[], int32_t length) {
	LOG_D("--> Vertices::loadVertices(length: %d)", length);

	glGenBuffers(1, &mVerticesId);
	glBindBuffer(GL_ARRAY_BUFFER, mVerticesId);

	size_t arrayBytes = length * sizeof(GLfloat);
	glBufferData(GL_ARRAY_BUFFER, arrayBytes, vertices, GL_STATIC_DRAW);

	if (glGetError() != GL_NO_ERROR) {
		LOG_E("Error uploading vertices into OpenGL.");
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	mDrawLength = length;
}

void Vertices::loadIndices(GLushort indices[], int32_t length) {
	LOG_D("--> Vertices::loadIndices(length: %d)", length);

	glGenBuffers(1, &mIndicesId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndicesId);

	size_t arrayBytes = length * sizeof(GLushort);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, arrayBytes, indices, GL_STATIC_DRAW);

	if (glGetError() != GL_NO_ERROR) {
		LOG_E("Error uploading indices into OpenGL.");
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	mDrawLength = length;
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

void Vertices::render()
{
	size_t offset = 0;
	glEnableClientState (GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, mVerticesId);
	glVertexPointer(2, GL_FLOAT, mVertexBytes, (GLvoid*) offset);
	offset += sizeof(GLfloat) * 2;

	if (mHasColor) {
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(4, GL_FLOAT, mVertexBytes, (GLvoid*) offset);
		offset += sizeof(GLfloat) * 4;
	}

	if (mHasTexture) {
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, mVertexBytes, (GLvoid*) offset);
		// offset += (GLvoid*) (sizeof(GLfloat) * 2);
	}

	if (mIndicesId) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndicesId);
		glDrawElements(GL_TRIANGLES, mDrawLength, GL_UNSIGNED_SHORT, (GLvoid*) mDrawOffset);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	} else {
		glDrawArrays(GL_TRIANGLES,  mDrawOffset, mDrawLength);
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	if (mHasTexture) {
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}

	if (mHasColor) {
		glDisableClientState(GL_COLOR_ARRAY);
	}

	glDisableClientState(GL_VERTEX_ARRAY);
}

}
