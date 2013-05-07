#include "MainMenuScreen.hpp"

MainMenuScreen::MainMenuScreen(GameContext* context) :
	GameScreen(context),
	mWorld(new World()) {
	LOG_D("MainMenuScreen::MainMenuScreen()");
}

MainMenuScreen::~MainMenuScreen() {
	LOG_D("MainMenuScreen::~MainMenuScreen()");
	delete mWorld;
}

void MainMenuScreen::update(float deltaTime) {
	mWorld->update(deltaTime);
}

void MainMenuScreen::render(float deltaTime) {
}

void MainMenuScreen::resume() {
	LOG_D("MainMenuScreen::resume");
}

void MainMenuScreen::pause() {
	LOG_D("MainMenuScreen::resume");
}

void MainMenuScreen::dispose() {
	LOG_D("MainMenuScreen::resume");
}
