#include "World.hpp"

World::World() :
	mTime(0.0),
	mTickTime(TICK_INITIAL) {
	LOG_D("### World::World()");
}

World::~World() {
	LOG_D("### World::~World()");
}

void World::update(float deltaTime) {
	mTime += deltaTime;

	while (mTime > mTickTime) {
		mTime -= mTickTime;
	}
}
