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
	android_app* _application;

	int32_t _width;
	int32_t _height;

	EGLDisplay _eglDisplay;
	EGLSurface _eglSurface;
	EGLContext _eglContext;
};

}

#endif
