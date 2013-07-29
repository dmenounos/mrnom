#include "GameContext.hpp"
#include "GameScreen.hpp"

#include "system/RenderView.hpp"
#include "system/ResourceFactory.hpp"

namespace engine {

GameContext::GameContext() : EventLoop() {
	LOG_D("### GameContext::GameContext()");
}

GameContext::~GameContext() {
	LOG_D("### GameContext::~GameContext()");
}

void GameContext::onUpdate(float deltaTime) {
	getScreen()->update(deltaTime);
	getScreen()->render(deltaTime);
	mRenderView->render();
}

void GameContext::onStart() {
	mResourceFactory = new ResourceFactory(getApplication()->activity->assetManager);
	mRenderView = new RenderView(getApplication());
	mScreen = getStartScreen();
}

void GameContext::onResume() {
	mRenderView->setUp();
	mScreen->resume();
	resumeRender();
}

void GameContext::onPause() {
	pauseRender();
	mScreen->pause();
	mRenderView->tearDown();
}

void GameContext::onStop() {
	mScreen->dispose();
	delete mScreen;
	delete mRenderView;
	delete mResourceFactory;
}

GameScreen* GameContext::getScreen() const {
	return mScreen;
}

void GameContext::setScreen(GameScreen* screen){
	assert(screen);

	if (mScreen) {
		mScreen->pause();
		mScreen->dispose();
		delete mScreen;
	}

	screen->resume();
	screen->update(0);
	mScreen = screen;
}

ResourceFactory* GameContext::getResourceFactory() const {
	return mResourceFactory;
}

}
