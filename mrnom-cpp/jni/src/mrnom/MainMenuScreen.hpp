#ifndef MAINMENUSCREEN_HPP
#define MAINMENUSCREEN_HPP

#include "../engine.h"

using namespace engine;

class World;

class MainMenuScreen : public GameScreen {

public:

	MainMenuScreen(GameContext* context);

	virtual ~MainMenuScreen();

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

	Sprite* mAnimationSprite;

	World* mWorld;
};

#endif
