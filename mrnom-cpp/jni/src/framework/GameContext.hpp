#ifndef GAMECONTEXT_HPP
#define GAMECONTEXT_HPP

#include "EventLoop.hpp"
#include "GameScreen.hpp"
#include "RenderView.hpp"

/**
 * Abstract game context class.
 */
class GameContext : public EventLoop
{
	public:

	virtual ~GameContext();

	virtual void onUpdate(float delta);

	virtual void onStart();

	virtual void onResume();

	virtual void onPause();

	virtual void onStop();

	GameScreen* getScreen() const;

	void setScreen(GameScreen* screen);

	virtual GameScreen* getStartScreen() = 0;

	private:

	RenderView* mRenderView;
	GameScreen* mScreen;
};

#endif
