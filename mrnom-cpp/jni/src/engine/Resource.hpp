#ifndef Resource_HPP
#define Resource_HPP

#include "../common.h"

/**
 * Asset input / output.
 */
class Resource {

public:

	Resource(AAssetManager* assetManager, const char* path);

	virtual ~Resource();

	int32_t read(void* buffer, size_t count);

private:

	AAsset* mAsset;
};

#endif
