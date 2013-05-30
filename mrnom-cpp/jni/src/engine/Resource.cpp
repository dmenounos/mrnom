#include "Resource.hpp"

Resource::Resource(AAssetManager* assetManager, const char* path) {
	mAsset = AAssetManager_open(assetManager, path, AASSET_MODE_UNKNOWN);
	LOG_D("Resource::Resource(%s)", path);
}

Resource::~Resource() {
	LOG_D("Resource::~Resource()");
	AAsset_close(mAsset);
	mAsset = NULL;
}

int32_t Resource::read(void* buffer, size_t count) {
	return AAsset_read(mAsset, buffer, count);
}
