#include "Resource.hpp"

Resource::Resource(AAssetManager* assetManager, const char* path) :
	mPath(path),
	mAssetManager(assetManager),
	mAsset(NULL) {
}

void Resource::open() {
	mAsset = AAssetManager_open(mAssetManager, mPath, AASSET_MODE_UNKNOWN);
}

void Resource::close() {
	AAsset_close(mAsset);
	mAsset = NULL;
}

int32_t Resource::read(void* buffer, size_t count) {
	return AAsset_read(mAsset, buffer, count);
}
