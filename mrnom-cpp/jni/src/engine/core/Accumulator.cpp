#include "Accumulator.hpp"

using namespace engine;

Accumulator::Accumulator() :
	_tickDuration(0.0), _continuous(false),
	_tickProgress(0.0), _tickComplete(false),
	_callback(this) {
	// LOG_D("### Accumulator::Accumulator()");
}

Accumulator::~Accumulator() {
	// LOG_D("### Accumulator::~Accumulator()");
}

void Accumulator::update(float deltaTime) {
	if (!isFinished()) {
		_tickProgress += deltaTime;
		_tickComplete = false;
	}

	if (!isContinuous() && isFinished()) {
		_tickProgress = 0.0f;
		_tickComplete = true;
		_callback->execute();
	}

	while (isContinuous() && isFinished()) {
		_tickProgress -= _tickDuration;
		_tickComplete = true;
		_callback->execute();
	}
}

bool Accumulator::isFinished() const {
	return _tickProgress >= _tickDuration;
}

bool Accumulator::isContinuous() const {
	return _continuous;
}

void Accumulator::setContinuous(bool continuous) {
	_continuous = continuous;
}

float Accumulator::getTickDuration() const {
	return _tickDuration;
}

void Accumulator::setTickDuration(float tickDuration) {
	_tickDuration = tickDuration;
}

bool Accumulator::isTickComplete() const {
	return _tickComplete;
}

float Accumulator::getTickProgress() const {
	return _tickProgress;
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
