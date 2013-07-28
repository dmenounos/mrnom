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

	virtual bool hasEnded();

	virtual bool isContinuous() const;
	virtual void setContinuous(bool loop);

	virtual float getTickDuration() const;
	virtual void setTickDuration(float tickDuration);

protected:

	virtual void onTick() {}

	virtual bool isTickComplete() const;

	virtual float getTickProgress() const;

private:

	/**
	 * Configuration;
	 * Is continuous?
	 */
	bool mContinuous;

	/**
	 * Configuration;
	 * Tick time duration.
	 */
	float mTickDuration;

	/**
	 * Computed;
	 * Is tick complete?
	 */
	bool mTickComplete;

	/**
	 * Computed;
	 * Tick time progress.
	 */
	float mTickProgress;
};

}

#endif
