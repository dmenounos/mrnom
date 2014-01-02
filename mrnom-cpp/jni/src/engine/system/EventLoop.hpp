#ifndef EVENTLOOP_HPP
#define EVENTLOOP_HPP

#include "../../common.h"
#include "Timer.hpp"

namespace engine {

/**
 * Rough equivalent to the Java Activity.
 * Implements the application event loop.
 */
class EventLoop {

public:

	EventLoop();

	virtual ~EventLoop();

	/**
	 * Triggers the event loop.
	 */
	virtual void init(android_app* application);

	/**
	 * Returns the NDK application structure.
	 */
	virtual android_app* getApplication() const;

protected:

	/**
	 * Resumes the render loop.
	 */
	virtual void resumeRender();

	/**
	 * Pauses the render loop.
	 */
	virtual void pauseRender();

	/**
	 * Called on each cycle, as long as the render loop is active,
	 * i.e. in-between onResume() / onPause() system states.
	 *
	 * @param deltaTime The elapsed time, in seconds.
	 */
	virtual void onUpdate(float deltaTime) {}

	/** State change call-back. */
	virtual void onStart() {}

	/** State change call-back. */
	virtual void onResume() {}

	/** State change call-back. */
	virtual void onPause() {}

	/** State change call-back. */
	virtual void onStop() {}

	/** State change call-back. */
	virtual void onDestroy() {}

	/**
	 * System state change call-back (non object oriented).
	 * Delegates to our state call-backs.
	 */
	static void systemStateCallback(android_app* app, int32_t cmd);

	/**
	 * System input event call-back (non object oriented).
	 * Delegates to our input call-back (not implemented yet).
	 */
	static int32_t systemInputCallback(android_app* app, AInputEvent* event);

private:

	// shared system pointer
	android_app* _application;

	Timer _timer;
	bool _active;
};

}

#endif
