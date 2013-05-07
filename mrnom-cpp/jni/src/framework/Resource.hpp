#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include "../common.h"

/**
 * Encapsulates asset loading.
 */
class Resource {

public:

	Resource(AAssetManager* assetManager, const char* path);

	void open();

	void close();

	int32_t read(void* buffer, size_t count);

private:

	const char* mPath;

	// shared pointer
	AAssetManager* mAssetManager;

	AAsset* mAsset;
};

#endif
