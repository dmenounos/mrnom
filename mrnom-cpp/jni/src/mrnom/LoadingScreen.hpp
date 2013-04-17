#ifndef LOADINGSCREEN_HPP
#define LOADINGSCREEN_HPP

#include "../framework.h"
#include "World.hpp"

class LoadingScreen : public GameScreen
{
	public:

	LoadingScreen(GameContext* context);

	virtual ~LoadingScreen();

	virtual void update(float deltaTime);

	virtual void render(float deltaTime);

	virtual void resume();

	virtual void pause();

	virtual void dispose();

	private:

	World* mWorld;
};

#endif
