#include "MainMenuScreen.hpp"
#include "World.hpp"

MainMenuScreen::MainMenuScreen(GameContext* context) :
	GameScreen(context), mWorld(new World()) {

	LOG_D("### MainMenuScreen::MainMenuScreen()");

	mAnimationTexture = new Texture(context, "anim.png");

	mAnimationSprite = new Sprite(mAnimationTexture);
	mAnimationSprite->getRegion().setGridCols(6);
	mAnimationSprite->getRegion().setGridRows(5);
	mAnimationSprite->getAnimation().setContinuous(true);
	mAnimationSprite->getAnimation().setTickDuration(10.0f);
}

MainMenuScreen::~MainMenuScreen() {
	LOG_D("### MainMenuScreen::~MainMenuScreen()");

	delete mAnimationSprite;
	delete mAnimationTexture;
	delete mWorld;
}

void MainMenuScreen::resume() {
	GameScreen::resume();
	LOG_D("--> MainMenuScreen::resume()");

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// left, right, bottom, top, near, far
	glOrthof(0.0f, 320.0f, 0.0f, 480.0f, 1.0f, -1.0f);

	mAnimationSprite->reload();
}

void MainMenuScreen::update(float deltaTime) {
	GameScreen::update(deltaTime);

	mWorld->update(deltaTime);
	mAnimationSprite->update(deltaTime);
}

void MainMenuScreen::render(float deltaTime) {
	GameScreen::render(deltaTime);

	mAnimationSprite->render(deltaTime);
}

void MainMenuScreen::pause() {
	mAnimationSprite->unload();

	GameScreen::pause();
	LOG_D("--> MainMenuScreen::pause()");
}

void MainMenuScreen::dispose() {
	GameScreen::dispose();
	LOG_D("--> MainMenuScreen::dispose()");
}
