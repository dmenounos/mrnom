#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "../common.h"

#include "Animation.hpp"
#include "Vector.hpp"

namespace engine {

class Texture;

class Sprite {

public:

	Sprite(Texture* texture);

	virtual ~Sprite();

	virtual void reload();

	virtual void update(float deltaTime);

	virtual void render(float deltaTime);

	int32_t getFrameWidth() const;

	int32_t getFrameHeight() const;

	int32_t getHorFrames() const;
	void setHorFrames(int32_t horFrames);

	int32_t getVerFrames() const;
	void setVerFrames(int32_t verFrames);

	Animation& getAnimation();

	Vector& getPosition();

private:

	Texture* mTexture;

	int32_t mFrameWidth;
	int32_t mFrameHeight;

	int32_t mHorFrames;
	int32_t mVerFrames;

	Animation mAnimation;

	Vector mPosition;
};

}

#endif
