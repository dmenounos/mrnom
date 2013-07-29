#ifndef LOADINGSCREEN_HPP
#define LOADINGSCREEN_HPP

#include "../engine.h"

using namespace engine;

class LoadingScreen : public GameScreen {

public:

	LoadingScreen(GameContext* context);

	virtual ~LoadingScreen();

	// override
	virtual void update(float deltaTime);

	// override
	virtual void render(float deltaTime);

	// override
	virtual void resume();

	// override
	virtual void pause();

	// override
	virtual void dispose();

private:

	Texture* backgroundTexture;
	Texture* logoTexture;
};

#endif
