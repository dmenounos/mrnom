#include "MainMenuScreen.hpp"
#include "World.hpp"

MainMenuScreen::MainMenuScreen(GameContext* context) :
	MrNomScreen(context) {

	LOG_D("### MainMenuScreen::MainMenuScreen()");

	_animationTexture = new Texture(context, "anim.png");

	_animationSprite = new Sprite(_animationTexture);
	_animationSprite->getRegion().setGridCols(6);
	_animationSprite->getRegion().setGridRows(5);
	_animationSprite->getAnimator().setContinuous(true);
	_animationSprite->getAnimator().setTickDuration(5.0f);
}

MainMenuScreen::~MainMenuScreen() {
	LOG_D("### MainMenuScreen::~MainMenuScreen()");

	delete _animationSprite;
	delete _animationTexture;
}

void MainMenuScreen::resume() {
	LOG_D("--> MainMenuScreen::resume()");
	MrNomScreen::resume();
	_animationSprite->reload();
}

void MainMenuScreen::update(float deltaTime) {
	MrNomScreen::update(deltaTime);
	_animationSprite->update(deltaTime);
}

void MainMenuScreen::render(float deltaTime) {
	MrNomScreen::render(deltaTime);
	_animationSprite->render(deltaTime);
}

void MainMenuScreen::pause() {
	LOG_D("--> MainMenuScreen::pause()");
	_animationSprite->unload();
	MrNomScreen::pause();
}

void MainMenuScreen::dispose() {
	LOG_D("--> MainMenuScreen::dispose()");
	MrNomScreen::dispose();
}
