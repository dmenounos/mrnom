#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "../common.h"

#include "Animation.hpp"
#include "Vector.hpp"

namespace engine {

class Texture;
class Vertices;

class Sprite {

public:

	Sprite(Texture* texture, Vertices* vertices);

	virtual ~Sprite();

	virtual void reload();

	virtual void unload();

	virtual void update(float deltaTime);

	virtual void render(float deltaTime);

	virtual int32_t getHorFrames() const;
	virtual void setHorFrames(int32_t horFrames);

	virtual int32_t getVerFrames() const;
	virtual void setVerFrames(int32_t verFrames);

	virtual int32_t getFrameWidth() const;
	virtual void setFrameWidth(int32_t frameWidth);

	virtual int32_t getFrameHeight() const;
	virtual void setFrameHeight(int32_t frameHeight);

	virtual Animation& getAnimation();

	virtual Vector& getPosition();

private:

	// shared pointer
	Texture* mTexture;

	// owned pointer
	Vertices* mVertices;

	Animation mAnimation;
	Vector mPosition;

	// configuration

	int32_t mHorFrames;
	int32_t mVerFrames;

	int32_t mFrameWidth;
	int32_t mFrameHeight;
};

}

#endif
