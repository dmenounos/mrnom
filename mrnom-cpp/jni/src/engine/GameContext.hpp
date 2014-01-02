#ifndef GAMECONTEXT_HPP
#define GAMECONTEXT_HPP

#include "system/EventLoop.hpp"

namespace engine {

class GameScreen;
class RenderView;
class SoundService;
class ResourceFactory;

/**
 * Abstract game context class.
 */
class GameContext : public EventLoop {

public:

	GameContext();

	virtual ~GameContext();

	virtual GameScreen* getScreen() const;

	virtual void setScreen(GameScreen* screen);

	virtual ResourceFactory* getResourceFactory() const;

protected:

	virtual GameScreen* getStartScreen() = 0;

	// override
	virtual void onUpdate(float deltaTime);

	// override
	virtual void onStart();

	// override
	virtual void onResume();

	// override
	virtual void onPause();

	// override
	virtual void onStop();

private:

	GameScreen* _screen;
	RenderView* _renderView;
	SoundService* _soundService;
	ResourceFactory* _resourceFactory;
};

}

#endif
