#ifndef ACCUMULATOR_HPP
#define ACCUMULATOR_HPP

#include "Callback.hpp"

namespace engine {

/**
 * Accumulates time intervals.
 */
class Accumulator : public Callback {

public:

	Accumulator();

	virtual ~Accumulator();

	/**
	 * @param deltaTime The elapsed time, in seconds.
	 */
	virtual void update(float deltaTime);

	/**
	 * Are we finished?
	 */
	virtual bool isFinished() const;

	/**
	 * Are we looping?
	 */
	virtual bool isContinuous() const;
	virtual void setContinuous(bool continuous);

	/**
	 * Tick time duration, in seconds.
	 */
	virtual float getTickDuration() const;
	virtual void setTickDuration(float tickDuration);

	/**
	 * Is tick complete?
	 */
	virtual bool isTickComplete() const;

	/**
	 * Tick time progress, in seconds.
	 *
	 * Notice the value is in seconds [zero to tickDuration).
	 * In the future it may change to normalized value [0 to 1).
	 */
	virtual float getTickProgress() const;

	/**
	 * On tick complete call-back.
	 * By default, is set to this.
	 */
	virtual Callback* getCallback() const;
	void setCallback(Callback* callback);

	// override
	virtual void execute();

private:

	// configuration

	bool  _continuous;
	float _tickDuration;

	// computed

	bool  _tickComplete;
	float _tickProgress;

	// shared pointer
	Callback* _callback;
};

}

#endif
