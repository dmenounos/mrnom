#ifndef EVENTLOOP_HPP
#define EVENTLOOP_HPP

#include "../common.h"
#include "Timer.hpp"

/**
 * Rough equivalent to the Java Activity.
 * Implements the application event loop.
 */
class EventLoop {

public:

	EventLoop();

	virtual ~EventLoop();

	android_app* getApplication() const;

	/**
	 * Fires the event loop.
	 */
	void run(android_app* application);

	/**
	 * Resumes the render loop.
	 */
	void resumeRender();

	/**
	 * Pauses the render loop.
	 */
	void pauseRender();

	/**
	 * Called on each cycle, as long as the render loop is active,
	 * i.e. in-between onResume / onPause system commands.
	 */
	virtual void onUpdate(float delta) {}

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

protected:

	/**
	 * System state change call-back (non object oriented).
	 * Delegates to a framework state call-back.
	 */
	static void systemStateCallback(android_app* app, int32_t cmd);

	/**
	 * System input event call-back (non object oriented).
	 * Delegates to a framework input call-back.
	 */
	static int32_t systemInputCallback(android_app* app, AInputEvent* event);

private:

	// shared pointer
	android_app* mApplication;

	Timer mTimer;
	bool mActive;
	bool mQuit;
};

#endif
