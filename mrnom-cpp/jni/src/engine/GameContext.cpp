#include "GameContext.hpp"
#include "GameScreen.hpp"

#include "system/RenderView.hpp"
#include "system/ResourceFactory.hpp"
#include "system/SoundService.hpp"

using namespace engine;

GameContext::GameContext() :
	EventLoop(),
	_screen(0),
	_renderView(0),
	_soundService(0),
	_resourceFactory(0) {
	LOG_D("### GameContext::GameContext()");
}

GameContext::~GameContext() {
	LOG_D("$$$ GameContext::~GameContext()");
}

void GameContext::onUpdate(float deltaTime) {
	getScreen()->update(deltaTime);
	getScreen()->render(deltaTime);
	_renderView->render();
}

void GameContext::onStart() {
	_resourceFactory = new ResourceFactory(getApplication()->activity->assetManager);
	_soundService = new SoundService(getApplication());
	_renderView = new RenderView(getApplication());
	_screen = getStartScreen();
}

void GameContext::onResume() {
	_soundService->setUp();
	_renderView->setUp();
	_screen->resume();
	resumeRender();
}

void GameContext::onPause() {
	pauseRender();
	_screen->pause();
	_renderView->tearDown();
	_soundService->tearDown();
}

void GameContext::onStop() {
	_screen->dispose();
	delete _screen;
	delete _renderView;
	delete _resourceFactory;
}

GameScreen* GameContext::getScreen() const {
	return _screen;
}

void GameContext::setScreen(GameScreen* screen){
	assert(screen);

	if (_screen) {
		LOG_D("--- DELETE SCREEN -------------->");
		_screen->pause();
		_screen->dispose();
		delete _screen;
		LOG_D("--- DELETE SCREEN <--------------");
	}

	screen->resume();
	screen->update(0);
	_screen = screen;
}

ResourceFactory* GameContext::getResourceFactory() const {
	return _resourceFactory;
}
