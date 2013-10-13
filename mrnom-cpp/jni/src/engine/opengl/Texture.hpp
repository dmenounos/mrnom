#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "../../common.h"

namespace engine {

class GameContext;

/**
 * GPU Picture buffer handle.
 */
class Texture {

public:

	Texture(GameContext* gameContext, const char* fileName);

	virtual ~Texture();

	/**
	 * Loads the pixel data from storage.
	 * Uploads the pixel buffer into OpenGL.
	 */
	virtual void upload();

	/**
	 * Deletes the pixel buffer from OpenGL.
	 */
	virtual void unload();

	/**
	 * Binds the texture for use with OpenGL.
	 */
	virtual void rebind();

	/**
	 * Unbinds the texture for use with OpenGL.
	 */
	virtual void unbind();

	/**
	 * Horizontal length.
	 */
	int32_t getWidth() const;

	/**
	 * Vertical length.
	 */
	int32_t getHeight() const;

private:

	// shared pointer
	GameContext* _gameContext;

	const char* _fileName;

	uint32_t _textureId;

	int32_t _width;
	int32_t _height;
};

}

#endif
