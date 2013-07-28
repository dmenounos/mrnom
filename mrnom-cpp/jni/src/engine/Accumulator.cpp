#include "Accumulator.hpp"

namespace engine {

Accumulator::Accumulator() :
	mTickDuration(0.0), mContinuous(false),
	mTickProgress(0.0), mTickComplete(false) {
	// LOG_D("### Accumulator::Accumulator()");
}

Accumulator::~Accumulator() {
	// LOG_D("### Accumulator::~Accumulator()");
}

void Accumulator::update(float deltaTime) {
	if (!hasEnded()) {
		mTickProgress += deltaTime;
		mTickComplete = false;
	}

	while (mContinuous && hasEnded()) {
		mTickProgress -= mTickDuration;
		mTickComplete = true;
		onTick();
	}

	if (!mContinuous && hasEnded()) {
		mTickProgress = 0.0f;
		mTickComplete = true;
		onTick();
	}
}

bool Accumulator::hasEnded() {
	return mTickProgress >= mTickDuration;
}

bool Accumulator::isContinuous() const {
	return mContinuous;
}

void Accumulator::setContinuous(bool continuous) {
	mContinuous = continuous;
}

float Accumulator::getTickDuration() const {
	return mTickDuration;
}

void Accumulator::setTickDuration(float tickDuration) {
	mTickDuration = tickDuration;
}

bool Accumulator::isTickComplete() const {
	return mTickComplete;
}

float Accumulator::getTickProgress() const {
	return mTickProgress;
}

}
