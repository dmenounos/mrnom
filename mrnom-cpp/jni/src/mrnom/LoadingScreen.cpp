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

void LoadingScreen::resume() {
	LOG_D("--> LoadingScreen::resume()");
	GameScreen::resume();

	backgroundTexture->reload();
	logoTexture->reload();
}

void LoadingScreen::update(float deltaTime) {
	GameScreen::update(deltaTime);
	mContext->setScreen(new MainMenuScreen(mContext));
}

void LoadingScreen::render(float deltaTime) {
	GameScreen::render(deltaTime);
}

void LoadingScreen::pause() {
	LOG_D("--> LoadingScreen::pause()");
	GameScreen::pause();
	backgroundTexture->unload();
	logoTexture->unload();
}

void LoadingScreen::dispose() {
	LOG_D("--> LoadingScreen::dispose()");
	GameScreen::dispose();
}
