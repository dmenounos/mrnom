#include "Accumulator.hpp"

using namespace engine;

Accumulator::Accumulator() :
	_progress(0.0), _duration(0.0),
	_repeatCount(INFINITE), _callback(this) {
	// LOG_D("### Accumulator::Accumulator()");
}

Accumulator::~Accumulator() {
	// LOG_D("### Accumulator::~Accumulator()");
}

void Accumulator::update(float deltaTime) {
	if (isFinished()) {
		return;
	}

	_progress += deltaTime;

	while (_progress >= _duration) {

		// A time period has been completed.

		if (_repeatCount > 0) {
			_repeatCount -= 1;
		}

		if (!isFinished()) {

			// The repeat count is not exhausted (or is infinite).
			// We subtract a time period and let the flow go on.

			_progress -= _duration;
		}
		else {

			// The repeatCount has been exhausted.
			// We cap the progress amount to the duration limit.

			_progress = _duration;
		}

		// Invoke the tick complete call-back.

		_callback->execute();
	}
}

bool Accumulator::isFinished() const {
	return _repeatCount == 0;
}

float Accumulator::getProgress() const {
	return _progress;
}

float Accumulator::getDuration() const {
	return _duration;
}

void Accumulator::setDuration(float tickDuration) {
	_duration = tickDuration;
}

int32_t Accumulator::getRepeatCount() const {
	return _repeatCount;
}

void Accumulator::setRepeatCount(int32_t repeatCount) {
	_repeatCount = repeatCount;
}

Callback* Accumulator::getCallback() const {
	return _callback;
}

void Accumulator::setCallback(Callback* callback) {
	assert(callback);
	this->_callback = callback;
}

void Accumulator::execute() {
}
