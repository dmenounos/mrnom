#ifndef RESOURCEREADER_HPP
#define RESOURCEREADER_HPP

#include "../common.h"

/**
 * Encapsulates asset input / output.
 */
class ResourceReader {

public:

	ResourceReader(AAssetManager* assetManager, const char* path);

	virtual ~ResourceReader();

	int32_t read(void* buffer, size_t count);

private:

	AAsset* mAsset;
};

#endif
