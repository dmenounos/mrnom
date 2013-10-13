#include "Timer.hpp"

using namespace engine;

Timer::Timer() :
	_lastTime(0.0) {
}

void Timer::update() {
	_lastTime = current();
}

float Timer::elapsed(bool update)
{
	double currentTime = current();
	float elapsed = currentTime - _lastTime;
	if (update) _lastTime = currentTime;
	return elapsed;
}

double Timer::current()
{
	timeval timeval;
	gettimeofday(&timeval, NULL);
	return timeval.tv_sec + (timeval.tv_usec / 1000000.0);
}
