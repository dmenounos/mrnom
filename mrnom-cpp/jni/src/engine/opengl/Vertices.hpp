#ifndef VERTICES_HPP
#define VERTICES_HPP

#include "../../common.h"

namespace engine {

/**
 * GPU Vertex buffer handle.
 */
class Vertices {

public:

	Vertices(bool hasColor, bool hasTexture);

	virtual ~Vertices();

	/**
	 * Stores vertices buffer.
	 */
	virtual void copyVertices(GLfloat* data, size_t dataBytes);

	/**
	 * Stores indices buffer.
	 */
	virtual void copyIndices(GLushort* data, size_t dataBytes);

	/**
	 * Uploads vertices buffer into OpenGL.
	 */
	virtual void loadVertices(GLfloat data[], size_t dataBytes);

	/**
	 * Uploads indices buffer into OpenGL.
	 */
	virtual void loadIndices(GLushort data[], size_t dataBytes);

	/**
	 * Deletes the buffers from OpenGL.
	 */
	virtual void unload();

	/**
	 * Binds the buffers for use with OpenGL.
	 */
	virtual void rebind();

	/**
	 * Unbinds the texture for use with OpenGL.
	 */
	virtual void unbind();

	virtual void render(int32_t offset, int32_t length);

	/**
	 * The CPU vertices array.
	 */
	GLfloat* getVertices() const;

	/**
	 * The CPU vertices array length.
	 */
	int32_t getVerticesLength() const;

	/**
	 * The CPU indices array.
	 */
	GLushort* getIndices() const;

	/**
	 * The CPU indices array length.
	 */
	int32_t getIndicesLength() const;

private:

	bool mHasColor;
	bool mHasTexture;

	/**
	 * Bytes / Vertex.
	 */
	size_t mVertexBytes;

	// CPU buffers.

	GLfloat* mVertices;
	int32_t mVerticesLength;

	GLushort* mIndices;
	int32_t mIndicesLength;

	// GPU buffers.

	uint32_t mVerticesId;
	uint32_t mIndicesId;
};

}

#endif
