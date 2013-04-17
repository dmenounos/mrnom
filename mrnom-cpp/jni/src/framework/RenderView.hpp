#ifndef RENDERVIEW_HPP
#define RENDERVIEW_HPP

#include "../common.h"

#include <EGL/egl.h>

class GameContext;

class RenderView
{
	public:

	RenderView(GameContext* gameContext);

	void setUp();

	void tearDown();

	void render();

	private:

	// shared
	GameContext* mGameContext;

	int32_t mWidth, mHeight;
	EGLDisplay mEglDisplay;
	EGLSurface mEglSurface;
	EGLContext mEglContext;
};

#endif
