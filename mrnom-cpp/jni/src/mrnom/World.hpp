#ifndef WORLD_HPP
#define WORLD_HPP

#include "../engine.h"

class World
{
	static const int WORLD_WIDTH  = 10;
	static const int WORLD_HEIGHT = 13;

	/* 2 updates per second */
	static const float TICK_INITIAL   = 0.5f;
	static const float TICK_DECREMENT = 0.05f;

	public:

	/**
	 * Constructor.
	 */
	World();

	void update(float deltaTime);

	private:

	/** Time accumulator. */
	float mTime;

	/** Tick interval. */
	float mTick;
};

#endif
