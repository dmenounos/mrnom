#include "GameScreen.hpp"
#include "GameContext.hpp"

namespace engine {

GameScreen::GameScreen(GameContext* context) :
	mContext(context), mFpsTime(0.0), mFpsTick(false) {

	LOG_D("### CREATE SCREEN ----------");
	LOG_D("### GameScreen::GameScreen()");
}

GameScreen::~GameScreen() {
	LOG_D("### GameScreen::~GameScreen()");
	LOG_D("### DELETE SCREEN -----------");
}

void GameScreen::update(float deltaTime) {
	mFpsTime += deltaTime;
	mFpsTick = mFpsTime >= 1;

	if (mFpsTick) {
		mFpsTime = 0;
	}
}

void GameScreen::render(float deltaTime) {
	if (mFpsTick) {
		float fps = 1 / deltaTime;
		// deltaTime is ratio: seconds / frame
		// so fps = 1 second / deltaTime ratio
		LOG_D("--- FPS: %f, delta: %f", fps, deltaTime);
	}
}

void GameScreen::resume() {
	LOG_D("--> GameScreen::resume()");
}

void GameScreen::pause() {
	LOG_D("--> GameScreen::pause()");
}

void GameScreen::dispose() {
	LOG_D("--> GameScreen::dispose()");
}

}
