#ifndef MAINMENUSCREEN_HPP
#define MAINMENUSCREEN_HPP

#include "../engine.h"

using namespace engine;

class World;

class MainMenuScreen : public GameScreen {

public:

	MainMenuScreen(GameContext* context);

	virtual ~MainMenuScreen();

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

	Vertices* mAnimationVertices;
	Texture*  mAnimationTexture;
	Sprite*   mAnimationSprite;

	World*    mWorld;
};

#endif
