#ifndef ACCUMULATOR_HPP
#define ACCUMULATOR_HPP

#include "../common.h"

namespace engine {

/**
 * Base class for time accumulators.
 */
class Accumulator {

public:

	Accumulator();

	virtual ~Accumulator();

	/**
	 * @param deltaTime The elapsed time, in seconds.
	 */
	virtual void update(float deltaTime);

	virtual bool isComplete();

	/**
	 * Is continuous?
	 */
	virtual bool isContinuous() const;
	virtual void setContinuous(bool loop);

	/**
	 * Tick time duration.
	 */
	virtual float getTickDuration() const;
	virtual void setTickDuration(float tickDuration);

protected:

	/**
	 * On tick complete call-back.
	 */
	virtual void onTick() {}

	/**
	 * Is tick complete?
	 */
	virtual bool isTickComplete() const;

	/**
	 * Tick time progress.
	 */
	virtual float getTickProgress() const;

private:

	// configuration

	bool mContinuous;
	float mTickDuration;

	// computed

	bool mTickComplete;
	float mTickProgress;
};

}

#endif
