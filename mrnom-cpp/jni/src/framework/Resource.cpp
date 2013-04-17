#include "Resource.hpp"

Resource::Resource(android_app* application, const char* path) :
	mPath(path),
	mAAssetManager(application->activity->assetManager),
	mAAsset(NULL) {
}

const char* Resource::getPath() {
	return mPath;
}

void Resource::open() {
	mAAsset = AAssetManager_open(mAAssetManager, mPath, AASSET_MODE_UNKNOWN);
}

void Resource::close() {
	AAsset_close(mAAsset);
	mAAsset = NULL;
}

int32_t Resource::read(void* buffer, size_t count) {
	return AAsset_read(mAAsset, buffer, count);
}
