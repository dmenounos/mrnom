#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include "../common.h"

class Resource {

	public:

	Resource(android_app* application, const char* path);

	const char* getPath();

	void open();

	void close();

	int32_t read(void* buffer, size_t count);

	private:

	const char* mPath;
	AAssetManager* mAAssetManager;
	AAsset* mAAsset;
};

#endif
