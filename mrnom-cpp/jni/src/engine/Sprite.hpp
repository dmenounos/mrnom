#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "../common.h"
#include "Location.hpp"

class Texture;

class Sprite {

public:

	Sprite(Location location, Texture* texture, int32_t width, int32_t height);

	virtual ~Sprite();

	void load();

	void draw(float deltaTime);

	void setAnimation(int32_t startFrame, int32_t frameCount, float speed, bool loop);

	bool hasAnimationEnded();

private:

	Location mLocation;

	Texture* mTexture;

	int32_t mWidth;
	int32_t mHeight;

	/** Horizontal texture frames. */
	int32_t mFrameXCount;

	/** Vertical texture frames. */
	int32_t mFrameYCount;

	/** Total texture frames. */
	int32_t mFrameCount;

	/** The animation starting frame. */
	int32_t mAnimStartFrame;

	/** The animation total frames. */
	int32_t mAnimFrameCount;

	/** The animation time accumulator. */
	float mAnimFrame;

	float mAnimSpeed;

	bool mAnimLoop;
};

#endif
