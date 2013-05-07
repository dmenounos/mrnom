#ifndef TIMER_HPP
#define TIMER_HPP

#include "../common.h"

class Timer {

public:

	Timer();

	void update();

	/**
	 * Returns the elapsed time, in seconds.
	 */
	float elapsed(bool update);

	/**
	 * Returns the current time, in seconds.
	 */
	double current();

private:

	double mLastTime;
};

#endif
