#ifndef LOADINGSCREEN_HPP
#define LOADINGSCREEN_HPP

#include "../engine.h"

using namespace engine;

class LoadingScreen : public GameScreen {

public:

	LoadingScreen(GameContext* context);

	virtual ~LoadingScreen();

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

private:

	Texture* backgroundTexture;
	Texture* logoTexture;
};

#endif
