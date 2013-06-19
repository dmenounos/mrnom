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

	void setAnimation(int32_t startFrame, int32_t frameCount, float speed, bool loop);

	bool hasAnimationEnded();

	void update(float deltaTime);

	void render(float deltaTime);
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

	/** Animation offset frame. */
	int32_t mAnimStartFrame;

	/** Animation total frames. */
	int32_t mAnimFrameCount;

	/** Animation current frame. */
	int32_t mAnimCurrentFrame;

	/** Animation time accumulator. */
	float mAnimProgress;

	/** Animation time duration. */
	float mAnimDuration;

	/** Animation frames / second. */
	float mAnimFactor;

	bool mAnimLoop;
};

#endif
