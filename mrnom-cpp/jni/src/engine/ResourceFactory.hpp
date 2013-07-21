#ifndef RESOURCEFACTORY_HPP
#define RESOURCEFACTORY_HPP

#include "../common.h"

namespace engine {

class GameContext;
class Bitmap;

/**
 * Encapsulates asset creation.
 */
class ResourceFactory {

public:

	ResourceFactory(GameContext* gameContext);

	Bitmap* createBitmap(const char* path);

private:

	// shared pointer
	GameContext* mGameContext;
};

}

#endif
