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
	 * Stores the vertices buffer.
	 */
	virtual void copyVertices(GLfloat* data, size_t dataBytes);

	/**
	 * Stores the indices buffer.
	 */
	virtual void copyIndices(GLushort* data, size_t dataBytes);

	/**
	 * Uploads the vertices buffer into OpenGL.
	 */
	virtual void uploadVertices(GLfloat data[], size_t dataBytes);

	/**
	 * Uploads the indices buffer into OpenGL.
	 */
	virtual void uploadIndices(GLushort data[], size_t dataBytes);

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

	bool _hasColor;
	bool _hasTexture;

	/**
	 * Bytes / Vertex.
	 */
	size_t _vertexBytes;

	// CPU buffers.

	GLfloat* _vertices;
	int32_t _verticesLength;

	GLushort* _indices;
	int32_t _indicesLength;

	// GPU buffers.

	uint32_t _verticesId;
	uint32_t _indicesId;
};

}

#endif
