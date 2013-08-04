#include "GameScreen.hpp"
#include "GameContext.hpp"

using namespace engine;

GameScreen::GameScreen(GameContext* context) :
	mContext(context), mFrameCounter() {
	LOG_D("### CREATE SCREEN -------------");
}

GameScreen::~GameScreen() {
	LOG_D("### DELETE SCREEN --------------");
}

void GameScreen::update(float deltaTime) {
	mFrameCounter.update(deltaTime);
}

void GameScreen::render(float deltaTime) {
}

void GameScreen::resume() {
}

void GameScreen::pause() {
}

void GameScreen::dispose() {
}
