#include "LoadingScreen.hpp"
#include "MainMenuScreen.hpp"

LoadingScreen::LoadingScreen(GameContext* context) :
	GameScreen(context) {

	LOG_D("### LoadingScreen::LoadingScreen()");

	_backgroundTexture = new Texture(context, "background.png");
	_logoTexture       = new Texture(context, "logo.png");
}

LoadingScreen::~LoadingScreen() {
	LOG_D("$$$ LoadingScreen::~LoadingScreen()");

	delete _backgroundTexture;
	delete _logoTexture;
}

void LoadingScreen::resume() {
	LOG_D("--> LoadingScreen::resume()");
	GameScreen::resume();

	_backgroundTexture->upload();
	_logoTexture->upload();
}

void LoadingScreen::update(float deltaTime) {
	GameScreen::update(deltaTime);
	_context->setScreen(new MainMenuScreen(_context));
}

void LoadingScreen::render(float deltaTime) {
	GameScreen::render(deltaTime);
}

void LoadingScreen::pause() {
	LOG_D("--> LoadingScreen::pause()");
	GameScreen::pause();
	_backgroundTexture->unload();
	_logoTexture->unload();
}

void LoadingScreen::dispose() {
	LOG_D("--> LoadingScreen::dispose()");
	GameScreen::dispose();
}
