#include "World.hpp"

World::World() : Accumulator() {
	// LOG_D("### World::World()");
	setTickDuration(TICK_INITIAL);
	setContinuous(true);
}

World::~World() {
	// LOG_D("$$$ World::~World()");
}
