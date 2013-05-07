#include "GameScreen.hpp"
#include "GameContext.hpp"

GameScreen::GameScreen(GameContext* context) :
	mContext(context) {
	LOG_D("GameScreen::GameScreen()");
}

GameScreen::~GameScreen() {
	LOG_D("GameScreen::~GameScreen()");
}
