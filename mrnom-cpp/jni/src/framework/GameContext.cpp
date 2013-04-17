#include "GameContext.hpp"

GameContext::~GameContext() {
	LOG_D("GameContext::~GameContext");
	delete mRenderView;
	delete mScreen;
}

void GameContext::onUpdate(float delta) {
	getScreen()->update(delta);
	getScreen()->render(delta);
	mRenderView->render();
}

void GameContext::onStart() {
	mRenderView = new RenderView(this);
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
}

GameScreen* GameContext::getScreen() const {
	return mScreen;
}

void GameContext::setScreen(GameScreen* screen)
{
	if (mScreen) {
		mScreen->pause();
		mScreen->dispose();
		delete mScreen;
	}

	assert(screen);
	screen->resume();
	screen->update(0);
	mScreen = screen;
}
