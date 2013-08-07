#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "../common.h"

#include "core/Animator.hpp"
#include "core/Region.hpp"
#include "core/Vector.hpp"

namespace engine {

class Texture;
class Vertices;

class Sprite {

public:

	/**
	 * Set the region cell width & height to that of the whole texture.
	 */
	static const int AUTO_SIZE = -1;

	/**
	 * Set the animator range length to the region grid cell count.
	 */
	static const int AUTO_RANGE = -1;

	Sprite(Texture* texture);

	virtual ~Sprite();

	virtual void reload();

	virtual void unload();

	virtual void update(float deltaTime);

	virtual void render(float deltaTime);

	virtual Vector& getPosition();

	/**
	 * A region of the texture to use for rendering.
	 */
	virtual Region& getRegion();

	virtual Animator& getAnimator();

private:

	Vector mPosition;

	Region mRegion;

	Animator mAnimator;

	// owned pointer
	Vertices* mVertices;

	// shared pointer
	Texture* mTexture;
};

}

#endif
