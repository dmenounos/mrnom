#include "Resource.hpp"

using namespace engine;

Resource::Resource(AAssetManager* assetManager, const char* path) {
	_asset = AAssetManager_open(assetManager, path, AASSET_MODE_UNKNOWN);
	// LOG_D("### Resource::Resource(%s)", path);
}

Resource::~Resource() {
	// LOG_D("$$$ Resource::~Resource()");
	AAsset_close(_asset);
}

int32_t Resource::read(void* buffer, size_t count) {
	return AAsset_read(_asset, buffer, count);
}
