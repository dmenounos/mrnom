#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include "../common.h"

#include "Accumulator.hpp"

namespace engine {

class GameContext;

/**
 * Abstract game screen class.
 */
class GameScreen : public Accumulator {

public:

	GameScreen(GameContext* context);

	virtual ~GameScreen();

	// override
	virtual void update(float deltaTime);

	virtual void render(float deltaTime);

	virtual void resume();

	virtual void pause();

	virtual void dispose();

protected:

	// override
	virtual void onTick();

protected:

	// shared pointer
	GameContext* mContext;

	uint32_t mFpsCounter;
	uint32_t mFps;
};

}

#endif
