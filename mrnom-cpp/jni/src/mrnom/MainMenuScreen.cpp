#include "MainMenuScreen.hpp"
#include "World.hpp"

MainMenuScreen::MainMenuScreen(GameContext* context) :
	MrNomScreen(context) {

	LOG_D("### MainMenuScreen::MainMenuScreen()");

	mAnimationTexture = new Texture(context, "anim.png");

	mAnimationSprite = new Sprite(mAnimationTexture);
	mAnimationSprite->getRegion().setGridCols(6);
	mAnimationSprite->getRegion().setGridRows(5);
	mAnimationSprite->getAnimator().setContinuous(true);
	mAnimationSprite->getAnimator().setTickDuration(5.0f);
}

MainMenuScreen::~MainMenuScreen() {
	LOG_D("### MainMenuScreen::~MainMenuScreen()");

	delete mAnimationSprite;
	delete mAnimationTexture;
}

void MainMenuScreen::resume() {
	LOG_D("--> MainMenuScreen::resume()");
	MrNomScreen::resume();
	mAnimationSprite->reload();
}

void MainMenuScreen::update(float deltaTime) {
	MrNomScreen::update(deltaTime);
	mAnimationSprite->update(deltaTime);
}

void MainMenuScreen::render(float deltaTime) {
	MrNomScreen::render(deltaTime);
	mAnimationSprite->render(deltaTime);
}

void MainMenuScreen::pause() {
	LOG_D("--> MainMenuScreen::pause()");
	mAnimationSprite->unload();
	MrNomScreen::pause();
}

void MainMenuScreen::dispose() {
	LOG_D("--> MainMenuScreen::dispose()");
	MrNomScreen::dispose();
}
