#include "LoadingScreen.hpp"
#include "MainMenuScreen.hpp"

LoadingScreen::LoadingScreen(GameContext* context) :
	GameScreen(context) {
	LOG_D("LoadingScreen::LoadingScreen()");
}

LoadingScreen::~LoadingScreen() {
	LOG_D("LoadingScreen::~LoadingScreen()");
}

void LoadingScreen::update(float deltaTime) {
	ResourceFactory* resourceFactory = mContext->getResourceFactory();

	resourceFactory->createTexture("background.png");
	resourceFactory->createTexture("logo.png");

	mContext->setScreen(new MainMenuScreen(mContext));
}

void LoadingScreen::render(float deltaTime) {
}

void LoadingScreen::resume() {
	LOG_D("LoadingScreen::resume");
}

void LoadingScreen::pause() {
	LOG_D("LoadingScreen::pause");
}

void LoadingScreen::dispose() {
	LOG_D("LoadingScreen::dispose");
}
