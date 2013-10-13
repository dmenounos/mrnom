#ifndef TIMER_HPP
#define TIMER_HPP

#include "../../common.h"

namespace engine {

class Timer {

public:

	Timer();

	/**
	 * Updates the current time.
	 */
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

	double _lastTime;
};

}

#endif
