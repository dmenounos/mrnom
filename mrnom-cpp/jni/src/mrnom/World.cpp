#include "World.hpp"

World::World() :
	mTime(0.0),
	mTick(TICK_INITIAL) {
}

void World::update(float deltaTime)
{
	mTime +=deltaTime;

	while (mTime > mTick) {
		LOG_D("mTime: %f FPS: %f", mTime, 1 / deltaTime);
		assert(deltaTime > 0.001f);
		mTime -= mTick;
	}
}
