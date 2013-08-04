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
	 * Uploads pixel buffer into OpenGL.
	 */
	virtual void reload();

	/**
	 * Deletes pixel buffer from OpenGL.
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
	GameContext* mGameContext;

	const char* mFileName;

	uint32_t mTextureId;

	int32_t mWidth;
	int32_t mHeight;
};

}

#endif
