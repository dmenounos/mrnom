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
	virtual void setVertices(GLfloat* data);

	/**
	 * Uploads vertices buffer into OpenGL.
	 *
	 * @param dataLength The array element count.
	 */
	virtual void loadVertices(GLfloat data[], int32_t dataLength);

	/**
	 * Stores indices buffer.
	 */
	virtual void setIndices(GLushort* data);

	/**
	 * Uploads indices buffer into OpenGL.
	 *
	 * @param dataLength The array element count.
	 */
	virtual void loadIndices(GLushort data[], int32_t dataLength);

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

private:

	bool mHasColor;
	bool mHasTexture;

	/**
	 * Bytes / Vertex.
	 */
	size_t mVertexBytes;

	// either gpu buffers

	uint32_t mVerticesId;
	uint32_t mIndicesId;

	// or cpu buffers

	GLfloat* mVertices;
	GLushort* mIndices;
};

}

#endif
