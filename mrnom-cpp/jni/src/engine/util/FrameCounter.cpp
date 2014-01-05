#include "FrameCounter.hpp"

using namespace engine;

FrameCounter::FrameCounter() :
	_fpsCounter(0), _fps(0) {
	// LOG_D("### FrameCounter::FrameCounter()");
	setTickDuration(1.0f);
	setContinuous(true);
}

FrameCounter::~FrameCounter() {
	// LOG_D("$$$ FrameCounter::~FrameCounter()");
}

void FrameCounter::update(float deltaTime) {
	Accumulator::update(deltaTime);

	++_fpsCounter;

	if (isTickComplete()) {
		// onTick() will have been called first.
		// This block could have been implemented there as
		// well however it is here to test more the Accumulator.

		// Computed, instance frame rate.
		// Remember, deltaTime is ratio: seconds / frame.
		// Question: how many frames, for 1 second?
		float fps = 1.0f / deltaTime;

		// Actual FPS, Calculated FPS, Last Frame Interval
		LOG_D("--- FPS: %d, fps: %f, delta: %f", _fps, fps, deltaTime);
	}
}

void FrameCounter::onTick() {
	Accumulator::onTick();

	_fps = _fpsCounter;
	_fpsCounter = 0;
}

uint32_t FrameCounter::getFps() const {
	return _fps;
}
