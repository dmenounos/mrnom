#include "GameScreen.hpp"
#include "GameContext.hpp"

using namespace engine;

GameScreen::GameScreen(GameContext* context) :
	_context(context), _frameCounter() {
	LOG_D("### GameScreen::GameScreen()");
}

GameScreen::~GameScreen() {
	LOG_D("$$$ GameScreen::~GameScreen()");
}

void GameScreen::update(float deltaTime) {
	_frameCounter.update(deltaTime);
}

void GameScreen::render(float deltaTime) {
}

void GameScreen::resume() {
}

void GameScreen::pause() {
}

void GameScreen::dispose() {
}
