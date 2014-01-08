#ifndef ACCUMULATOR_HPP
#define ACCUMULATOR_HPP

#include "Callback.hpp"

namespace engine {

/**
 * Accumulates time intervals.
 */
class Accumulator : public Callback {

public:

	/**
	 * Repeat indefinitely.
	 */
	static const int32_t INFINITE = -1;

public:

	Accumulator();

	virtual ~Accumulator();

	/**
	 * @param deltaTime The elapsed time, in seconds.
	 */
	virtual void update(float deltaTime);

	/**
	 * Are we past the interval?
	 */
	virtual bool isFinished() const;

	/**
	 * Returns the interval progress, in seconds.
	 */
	virtual float getProgress() const;

	/**
	 * Defines the interval duration, in seconds.
	 */
	virtual float getDuration() const;
	virtual void setDuration(float duration);

	/**
	 * Defines how many times the animation should repeat.
	 */
	virtual int32_t getRepeatCount() const;
	virtual void setRepeatCount(int32_t repeatCount);

	/**
	 * On tick complete call-back.
	 * By default, is set to this.
	 */
	virtual Callback* getCallback() const;
	virtual void setCallback(Callback* callback);

	// override
	virtual void execute();

private:

	float _progress;
	float _duration;
	int32_t _repeatCount;

	// shared pointer
	Callback* _callback;
};

}

#endif
