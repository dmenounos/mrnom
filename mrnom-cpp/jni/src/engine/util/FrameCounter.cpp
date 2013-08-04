#include "FrameCounter.hpp"

using namespace engine;

FrameCounter::FrameCounter() {
	// LOG_D("### FrameCounter::FrameCounter()");

	setTickDuration(1.0f);
	setContinuous(true);
}

FrameCounter::~FrameCounter() {
	// LOG_D("### FrameCounter::~FrameCounter()");
}

void FrameCounter::update(float deltaTime) {
	Accumulator::update(deltaTime);

	++mFpsCounter;

	if (isTickComplete()) {
		// Computed, instance frame rate.
		// Remember, deltaTime is ratio: seconds / frame.
		// Question: how many frames, for 1 second?
		float fps = 1.0f / deltaTime;

		// Actual FPS, Calculated FPS, Last Frame Interval
		LOG_D("--- FPS: %d, fps: %f, delta: %f", mFps, fps, deltaTime);
	}
}

void FrameCounter::onTick() {
	Accumulator::onTick();

	mFps = mFpsCounter;
	mFpsCounter = 0;
}

uint32_t FrameCounter::getFps() const {
	return mFps;
}
