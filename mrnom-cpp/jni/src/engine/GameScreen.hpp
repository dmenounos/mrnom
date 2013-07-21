#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include "../common.h"

namespace engine {

class GameContext;

/**
 * Abstract game screen class.
 */
class GameScreen {

public:

	GameScreen(GameContext* context);

	virtual ~GameScreen();

	/**
	 * @param deltaTime The elapsed time, in seconds.
	 */
	virtual void update(float deltaTime);

	/**
	 * @param deltaTime The elapsed time, in seconds.
	 */
	virtual void render(float deltaTime);

	virtual void resume();

	virtual void pause();

	virtual void dispose();

protected:

	// shared pointer
	GameContext* mContext;

	/** FPS time accumulator. */
	float mFpsTime;

	/** FPS tick flag. */
	bool mFpsTick;
};

}

#endif
