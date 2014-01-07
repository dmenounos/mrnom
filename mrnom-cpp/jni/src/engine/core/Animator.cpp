#include "Animator.hpp"

using namespace engine;

Animator::Animator() : Accumulator(),
	_rangeOffset(0), _rangeLength(0), _factor(0.0f) {
	// LOG_D("### Animator::Animator()");
}

Animator::~Animator() {
	// LOG_D("### Animator::~Animator()");
}

float Animator::getRangeCursor() const {
	return getTickProgress() * _factor + _rangeOffset;
}

float Animator::getRangeOffset() const {
	return _rangeOffset;
}

void Animator::setRangeOffset(float rangeOffset) {
	_rangeOffset = rangeOffset;
}

float Animator::getRangeLength() const {
	return _rangeLength;
}

void Animator::setRangeLength(float rangeLength) {
	_rangeLength = rangeLength;

	if (getTickDuration() > 0.0f) {
		_factor = _rangeLength / getTickDuration();
	} else {
		_factor = 0.0f;
	}
}
