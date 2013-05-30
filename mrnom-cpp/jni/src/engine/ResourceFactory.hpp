#ifndef RESOURCEFACTORY_HPP
#define RESOURCEFACTORY_HPP

#include "../common.h"

class GameContext;
class Texture;

/**
 * Encapsulates asset creation.
 */
class ResourceFactory {

public:

	ResourceFactory(GameContext* gameContext);

	Texture* createTexture(const char* path);

private:

	// shared pointer
	GameContext* mGameContext;
};

#endif
