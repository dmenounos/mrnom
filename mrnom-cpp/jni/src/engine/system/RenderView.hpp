#ifndef RENDERVIEW_HPP
#define RENDERVIEW_HPP

#include "../../common.h"

namespace engine {

/**
 * Encapsulates OpenGL context management.
 */
class RenderView {

public:

	RenderView(android_app* application);

	virtual ~RenderView();

	virtual void setUp();

	virtual void tearDown();

	virtual void render();

private:

	// shared system pointer
	android_app* mApplication;

	int32_t mWidth;
	int32_t mHeight;

	EGLDisplay mEglDisplay;
	EGLSurface mEglSurface;
	EGLContext mEglContext;
};

}

#endif
