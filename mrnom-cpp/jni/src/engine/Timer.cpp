#include "Timer.hpp"

Timer::Timer() :
	mLastTime(0.0) {
}

void Timer::update() {
	mLastTime = current();
}

float Timer::elapsed(bool update)
{
	double currentTime = current();
	float elapsed = currentTime - mLastTime;
	if (update) mLastTime = currentTime;
	return elapsed;
}

double Timer::current()
{
	timeval timeval;
	gettimeofday(&timeval, NULL);
	return timeval.tv_sec + (timeval.tv_usec / 1000000.0);
}
