#ifndef RENDERVIEW_HPP
#define RENDERVIEW_HPP

#include "../../common.h"

namespace engine {

/**
 * Encapsulates EGL / OpenGL context management.
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
	android_app* _application;

	EGLDisplay _eglDisplay;
	EGLSurface _eglSurface;
	EGLContext _eglContext;

	int32_t _width;
	int32_t _height;
};

}

#endif
