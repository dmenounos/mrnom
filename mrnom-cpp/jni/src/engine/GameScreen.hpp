#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include "../common.h"

#include "util/FrameCounter.hpp"

namespace engine {

class GameContext;

/**
 * Abstract game screen class.
 */
class GameScreen {

public:

	GameScreen(GameContext* context);

	virtual ~GameScreen();

	virtual void update(float deltaTime);

	virtual void render(float deltaTime);

	virtual void resume();

	virtual void pause();

	virtual void dispose();

protected:

	// shared pointer
	GameContext* _context;

	FrameCounter _frameCounter;
};

}

#endif
