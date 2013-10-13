#ifndef MAINMENUSCREEN_HPP
#define MAINMENUSCREEN_HPP

#include "MrNomScreen.hpp"

class MainMenuScreen : public MrNomScreen {

public:

	MainMenuScreen(GameContext* context);

	virtual ~MainMenuScreen();

	// override
	virtual void resume();

	// override
	virtual void update(float deltaTime);

	// override
	virtual void render(float deltaTime);

	// override
	virtual void pause();

	// override
	virtual void dispose();

private:

	Texture*  _animationTexture;
	Sprite*   _animationSprite;
};

#endif
