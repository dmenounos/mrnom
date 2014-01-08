#include "FrameCounter.hpp"

using namespace engine;

FrameCounter::FrameCounter() :
	_deltaTime(0.0f), _fpsCounter(0), _fps(0) {
	setDuration(1.0f);
}

FrameCounter::~FrameCounter() {
}

void FrameCounter::execute() {
	Accumulator::execute();

	_fps = _fpsCounter;
	_fpsCounter = 0;

	// Computed, instance frame rate.
	// Remember, deltaTime is ratio: seconds / frame.
	// Question: how many frames, for 1 second?
	float fps = 1.0f / _deltaTime;

	// Actual FPS, Calculated FPS, Last Frame Interval
	LOG_D("--- FPS: %d, fps: %f, delta: %f", _fps, fps, _deltaTime);

}

void FrameCounter::update(float deltaTime) {
	Accumulator::update(deltaTime);

	_deltaTime = deltaTime;
	_fpsCounter += 1;
}

uint32_t FrameCounter::getFps() const {
	return _fps;
}
