#include "MainMenuScreen.hpp"
#include "World.hpp"

MainMenuScreen::MainMenuScreen(GameContext* context) :
	GameScreen(context), mWorld(new World()) {

	LOG_D("### MainMenuScreen::MainMenuScreen()");

	mAnimationSprite = new Sprite(new Texture(context, "anim_512x512.png"));
	mAnimationSprite->getAnimation().setContinuous(true);  // continuous
	mAnimationSprite->getAnimation().setTickDuration(30);  // 30 seconds
	mAnimationSprite->getAnimation().setLength(30);        // 30 frames
}

MainMenuScreen::~MainMenuScreen() {
	LOG_D("### MainMenuScreen::~MainMenuScreen()");

	delete mAnimationSprite;
	delete mWorld;
}

void MainMenuScreen::update(float deltaTime) {
	GameScreen::update(deltaTime);

	mWorld->update(deltaTime);
	mAnimationSprite->update(deltaTime);
}

void MainMenuScreen::render(float deltaTime) {
	GameScreen::render(deltaTime);

	if (isTickComplete()) {
		LOG_D("--- animation cursor: %d", mAnimationSprite->getAnimation().getCursor());
	}
}

void MainMenuScreen::resume() {
	GameScreen::resume();
	LOG_D("--> MainMenuScreen::resume()");
}

void MainMenuScreen::pause() {
	LOG_D("--> MainMenuScreen::pause()");
	GameScreen::pause();
}

void MainMenuScreen::dispose() {
	LOG_D("--> MainMenuScreen::dispose()");
	GameScreen::dispose();
}
