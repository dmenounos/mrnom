#include "World.hpp"

World::World() : Accumulator() {
	// LOG_D("### World::World()");
	setDuration(TICK_INITIAL);
}

World::~World() {
	// LOG_D("$$$ World::~World()");
}
