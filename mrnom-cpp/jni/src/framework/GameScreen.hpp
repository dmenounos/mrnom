#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "../common.h"

class GameContext;

/**
 * Abstract game screen class.
 */
class GameScreen {

public:

	GameScreen(GameContext* context);

	virtual ~GameScreen();

	virtual void update(float deltaTime) = 0;

	virtual void render(float deltaTime) = 0;

	virtual void resume() = 0;

	virtual void pause() = 0;

	virtual void dispose() = 0;

protected:

	// shared pointer
	GameContext* mContext;
};

#endif
