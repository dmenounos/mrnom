#include "GameScreen.hpp"
#include "GameContext.hpp"

namespace engine {

GameScreen::GameScreen(GameContext* context) : Accumulator(),
	mContext(context), mFpsCounter(0), mFps(0) {

	LOG_D("### CREATE SCREEN ----------");
	LOG_D("### GameScreen::GameScreen()");

	setTickDuration(1.0f);
	setContinuous(true);
}

GameScreen::~GameScreen() {
	LOG_D("### GameScreen::~GameScreen()");
	LOG_D("### DELETE SCREEN -----------");
}

void GameScreen::onTick() {
	mFps = mFpsCounter;
	mFpsCounter = 0;
}

void GameScreen::render(float deltaTime) {
	++mFpsCounter;

	if (isTickComplete()) {
		// instance frame rate
		float fps = 1.0f / deltaTime;

		// deltaTime is ratio: seconds / frame
		// so fps = 1 second / deltaTime ratio

		LOG_D("--- FPS: %d, fps: %f, delta: %f", mFps, fps, deltaTime);

	}
}

void GameScreen::resume() {
	// LOG_D("--> GameScreen::resume()");
}

void GameScreen::pause() {
	// LOG_D("--> GameScreen::pause()");
}

void GameScreen::dispose() {
	// LOG_D("--> GameScreen::dispose()");
}

}
