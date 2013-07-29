#ifndef VERTICES_HPP
#define VERTICES_HPP

#include "../common.h"

namespace engine {

/**
 * GPU Vertex buffer handle.
 */
class Vertices {

public:

	Vertices(bool hasColor, bool hasTexture);

	virtual ~Vertices();

	/**
	 * Uploads vertices buffer into OpenGL.
	 *
	 * @param length The array element count.
	 */
	virtual void loadVertices(GLfloat vertices[], int32_t length);

	/**
	 * Uploads indices buffer into OpenGL.
	 *
	 * @param length The array element count.
	 */
	virtual void loadIndices(GLushort indices[], int32_t length);

	/**
	 * Deletes vertices and indices buffers from OpenGL.
	 */
	virtual void unload();

	virtual void render();

private:

	bool mHasColor;
	bool mHasTexture;

	/**
	 * Components / Vertex.
	 */
	int mVertexComponents;

	/**
	 * Bytes / Vertex.
	 */
	size_t mVertexBytes;

	uint32_t mVerticesId;
	uint32_t mIndicesId;

	int32_t mDrawOffset;
	int32_t mDrawLength;
};

}

#endif
