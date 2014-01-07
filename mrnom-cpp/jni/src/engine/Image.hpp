#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "../common.h"

namespace engine {

class Texture;
class Vertices;

/**
 * Combines texture and vertices into an image rectangle.
 */
class Image {

public:

	Image(Texture* texture);

	virtual ~Image();

	/**
	 * Initialize the vertices from an area of the texture.
	 */
	virtual void init(int32_t x, int32_t y, int32_t w, int32_t h);

	/**
	 * Should be called on application resume.
	 */
	virtual void upload();

	/**
	 * Should be called on application pause.
	 */
	virtual void unload();

	virtual void render(float deltaTime);

public:

	Texture* getTexture() const;

	Vertices* getVertices() const;

	float getHorTextureRatio() const;

	float getVerTextureRatio() const;

private:

	// shared pointer
	Texture*  _texture;

	// owned pointer
	Vertices* _vertices;

	float _horTextureRatio;
	float _verTextureRatio;
};

}

#endif
