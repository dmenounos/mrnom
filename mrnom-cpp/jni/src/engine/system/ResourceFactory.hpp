#ifndef RESOURCEFACTORY_HPP
#define RESOURCEFACTORY_HPP

#include "../../common.h"

namespace engine {

class Bitmap;

/**
 * Encapsulates asset creation.
 */
class ResourceFactory {

public:

	ResourceFactory(AAssetManager* assetManager);

	virtual ~ResourceFactory();

	virtual Bitmap* createBitmap(const char* path);

private:

	// shared system pointer
	AAssetManager* mAssetManager;
};

}

#endif
