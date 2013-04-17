#include "LoadingScreen.hpp"

LoadingScreen::LoadingScreen(GameContext* context) :
	GameScreen(context),
	mWorld(new World()) {
	LOG_D("LoadingScreen::LoadingScreen");
}

LoadingScreen::~LoadingScreen() {
	LOG_D("LoadingScreen::~LoadingScreen");
	delete mWorld;
}

void LoadingScreen::update(float deltaTime) {
	mWorld->update(deltaTime);
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
