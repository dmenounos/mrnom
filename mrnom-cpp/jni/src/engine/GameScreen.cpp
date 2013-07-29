#include "GameScreen.hpp"
#include "GameContext.hpp"

namespace engine {

GameScreen::GameScreen(GameContext* context) : Accumulator(),
	mContext(context), mFpsCounter(0), mFps(0) {

	LOG_D("### CREATE SCREEN -------------");

	setTickDuration(1.0f);
	setContinuous(true);
}

GameScreen::~GameScreen() {
	LOG_D("### DELETE SCREEN --------------");
}

void GameScreen::update(float deltaTime) {
	Accumulator::update(deltaTime);
	++mFpsCounter;
}

void GameScreen::onTick() {
	Accumulator::onTick();
	mFps = mFpsCounter;
	mFpsCounter = 0;
}

void GameScreen::render(float deltaTime) {
	if (isTickComplete()) {
		// computed, instance frame rate
		// remember, deltaTime is ratio: seconds / frame
		float fps = 1.0f / deltaTime;

		// Actual FPS, Calculated FPS, Last Frame Interval
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
