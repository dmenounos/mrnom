#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Image.hpp"
#include "core/Animator.hpp"
#include "core/Region.hpp"
#include "core/Vector.hpp"

namespace engine {

class Sprite : public Image {

public:

	/**
	 * Set the region cell width & height to that of the whole texture.
	 */
	static const int GRID_CELL_SIZE_AUTO = -1;

	/**
	 * Set the animator range length to the region grid cell count.
	 */
	static const int ANIM_RANGE_FULL_GRID = -1;

	Sprite(Texture* texture);

	virtual ~Sprite();

	/**
	 * Should be called on application resume.
	 */
	virtual void upload();

	/**
	 * Should be called on application pause.
	 */
	virtual void unload();

	virtual void update(float deltaTime);

	virtual void render(float deltaTime);

	virtual Vector& getPosition();

	/**
	 * A region within the texture to use for rendering.
	 * By default the texture area will be split over the cell count,
	 * which also by default is 1. So the cell size ends up being
	 * equal to that of the whole texture.
	 */
	virtual Region& getTextureRegion();

	/**
	 * An animator over the region cells.
	 * By default the range is set to cover all region cells.
	 */
	virtual Animator& getTextureRegionAnimator();

private:

	Vector    _position;

	Region    _textureRegion;

	Animator  _textureRegionAnimator;
};

}

#endif
