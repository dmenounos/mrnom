#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "Handle.hpp"

namespace engine {

class GameContext;

/**
 * GPU Texture buffer handle.
 */
class Texture : public Handle {

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
	 * Rebinds the texture into OpenGL.
	 */
	virtual void rebind();

	/**
	 * Unbinds the texture from OpenGL.
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
