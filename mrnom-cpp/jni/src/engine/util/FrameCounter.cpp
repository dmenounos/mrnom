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

void FrameCounter::execute() {
	_fps = _fpsCounter;
	_fpsCounter = 0;
}

void FrameCounter::update(float deltaTime) {
	Accumulator::update(deltaTime);

	++_fpsCounter;

	if (isTickComplete()) {
		// execute() will have been called first.

		// Computed, instance frame rate.
		// Remember, deltaTime is ratio: seconds / frame.
		// Question: how many frames, for 1 second?
		float fps = 1.0f / deltaTime;

		// Actual FPS, Calculated FPS, Last Frame Interval
		LOG_D("--- FPS: %d, fps: %f, delta: %f", _fps, fps, deltaTime);
	}
}

uint32_t FrameCounter::getFps() const {
	return _fps;
}
