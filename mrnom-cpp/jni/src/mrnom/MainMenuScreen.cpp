#include "MainMenuScreen.hpp"
#include "World.hpp"

MainMenuScreen::MainMenuScreen(GameContext* context) :
	GameScreen(context) {

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
	GameScreen::resume();

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// left, right, bottom, top, near, far
	glOrthof(0.0f, 320.0f, 0.0f, 480.0f, 1.0f, -1.0f);

	mAnimationSprite->reload();
}

void MainMenuScreen::update(float deltaTime) {
	GameScreen::update(deltaTime);
	mAnimationSprite->update(deltaTime);
}

void MainMenuScreen::render(float deltaTime) {
	GameScreen::render(deltaTime);
	mAnimationSprite->render(deltaTime);
}

void MainMenuScreen::pause() {
	LOG_D("--> MainMenuScreen::pause()");
	mAnimationSprite->unload();
	GameScreen::pause();
}

void MainMenuScreen::dispose() {
	LOG_D("--> MainMenuScreen::dispose()");
	GameScreen::dispose();
}
