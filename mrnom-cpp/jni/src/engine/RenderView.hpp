#ifndef RENDERVIEW_HPP
#define RENDERVIEW_HPP

#include "../common.h"

#include <EGL/egl.h>

namespace engine {

class GameContext;

class RenderView {

public:

	RenderView(GameContext* gameContext);

	virtual ~RenderView();

	virtual void setUp();

	virtual void tearDown();

	virtual void render();

private:

	// shared pointer
	GameContext* mGameContext;

	int32_t mWidth;
	int32_t mHeight;

	EGLDisplay mEglDisplay;
	EGLSurface mEglSurface;
	EGLContext mEglContext;
};

}

#endif
