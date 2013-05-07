#include "ResourceFactory.hpp"
#include "GameContext.hpp"
#include "Texture.hpp"

ResourceFactory::ResourceFactory(GameContext* gameContext) :
	mGameContext(gameContext) {
}

// private helper function
AAssetManager* getAssetManager(GameContext* gameContex) {
	return gameContex->getApplication()->activity->assetManager;
}

Texture* ResourceFactory::createTexture(const char* path) {
	AAssetManager* assetManager = getAssetManager(mGameContext);
	Resource resource(assetManager, path);
	return new Texture(resource);
}
