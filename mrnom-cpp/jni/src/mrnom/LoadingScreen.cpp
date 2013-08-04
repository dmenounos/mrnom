#include "LoadingScreen.hpp"
#include "MainMenuScreen.hpp"

LoadingScreen::LoadingScreen(GameContext* context) :
	GameScreen(context) {

	LOG_D("### LoadingScreen::LoadingScreen()");

	backgroundTexture = new Texture(context, "background.png");
	logoTexture       = new Texture(context, "logo.png");
}

LoadingScreen::~LoadingScreen() {
	LOG_D("### LoadingScreen::~LoadingScreen()");

	delete backgroundTexture;
	delete logoTexture;
}

void LoadingScreen::update(float deltaTime) {
	GameScreen::update(deltaTime);
	mContext->setScreen(new MainMenuScreen(mContext));
}

void LoadingScreen::render(float deltaTime) {
	GameScreen::render(deltaTime);
}

void LoadingScreen::resume() {
	GameScreen::resume();
	LOG_D("--> LoadingScreen::resume()");

	backgroundTexture->reload();
	logoTexture->reload();
}

void LoadingScreen::pause() {
	GameScreen::pause();
	LOG_D("--> LoadingScreen::pause()");
}

void LoadingScreen::dispose() {
	GameScreen::dispose();
	LOG_D("--> LoadingScreen::dispose()");
}
