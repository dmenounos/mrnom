#include "ResourceReader.hpp"

ResourceReader::ResourceReader(AAssetManager* assetManager, const char* path) {
	mAsset = AAssetManager_open(assetManager, path, AASSET_MODE_UNKNOWN);
	LOG_D("ResourceReader::ResourceReader(%s)", path);
}

ResourceReader::~ResourceReader() {
	LOG_D("ResourceReader::~ResourceReader()");
	AAsset_close(mAsset);
	mAsset = NULL;
}

int32_t ResourceReader::read(void* buffer, size_t count) {
	return AAsset_read(mAsset, buffer, count);
}
