#include "RenderView.hpp"

using namespace engine;

RenderView::RenderView(android_app* application) :
	_application(application),
	_eglDisplay(EGL_NO_DISPLAY),
	_eglSurface(EGL_NO_SURFACE),
	_eglContext(EGL_NO_CONTEXT),
	_width(0), _height(0) {
	LOG_D("### RenderView::RenderView()");
}

RenderView::~RenderView() {
	LOG_D("$$$ RenderView::~RenderView()");
}

void RenderView::setUp() {
	LOG_D("--> RenderView::setUp()");

	EGLint format;
	EGLint numConfigs;
	EGLint errorResult;
	EGLConfig config;

	// Here specify the attributes of the desired configuration.
	// Below, we select an EGLConfig with at least 16bit color.

	EGLint attributes[] = {
		EGL_RENDERABLE_TYPE, EGL_OPENGL_ES_BIT,
		EGL_BLUE_SIZE, 5, EGL_GREEN_SIZE, 6, EGL_RED_SIZE, 5,
		EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
		EGL_NONE
	};

	ANativeWindow* nativeWindow = _application->window;

	if (nativeWindow == NULL) {
		goto ERROR;
	}

	_eglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
	if (_eglDisplay == EGL_NO_DISPLAY) goto ERROR;

	if (!eglInitialize(_eglDisplay, NULL, NULL)) {
		goto ERROR;
	}

	// Here, the application chooses the configuration it desires.
	// we have a very simplified selection process, where we pick
	// the first EGLConfig that matches our criteria.

	if (!eglChooseConfig(_eglDisplay, attributes, &config, 1, &numConfigs)) {
		goto ERROR;
	}

	// EGL_NATIVE_VISUAL_ID is an attribute of the EGLConfig that is
	// guaranteed to be accepted by ANativeWindow_setBuffersGeometry().
	// As soon as we picked a EGLConfig, we can safely reconfigure the
	// ANativeWindow buffers to match, using EGL_NATIVE_VISUAL_ID.

	if (!eglGetConfigAttrib(_eglDisplay, config, EGL_NATIVE_VISUAL_ID, &format)) {
		goto ERROR;
	}

	ANativeWindow_setBuffersGeometry(nativeWindow, 0, 0, format);

	// Continue to create the display surface and context according to the
	// selected configuration. A context contains all data related to OpenGL
	// state (settings, matrix stack and so on).

	_eglSurface = eglCreateWindowSurface(_eglDisplay, config, nativeWindow, NULL);
	if (_eglSurface == EGL_NO_SURFACE) goto ERROR;

	_eglContext = eglCreateContext(_eglDisplay, config, EGL_NO_CONTEXT, NULL);
	if (_eglContext == EGL_NO_CONTEXT) goto ERROR;

	if (!eglMakeCurrent(_eglDisplay, _eglSurface, _eglSurface, _eglContext)) {
		goto ERROR;
	}

	if (!eglQuerySurface(_eglDisplay, _eglSurface, EGL_WIDTH, &_width) || _width <= 0) {
		goto ERROR;
	}

	if (!eglQuerySurface(_eglDisplay, _eglSurface, EGL_HEIGHT, &_height) || _height <= 0) {
		goto ERROR;
	}

	LOG_D("--- glViewport(0, 0, %d, %d)", _width, _height);
	glViewport(0, 0, _width, _height);

	return;

	ERROR:
	LOG_E("Error while initializing OpenGL: %d", eglGetError());
}

void RenderView::tearDown() {
	LOG_D("--> RenderView::tearDown()");

	if (_eglDisplay != EGL_NO_DISPLAY) {
		eglMakeCurrent(_eglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);

		if (_eglContext != EGL_NO_CONTEXT) {
			eglDestroyContext(_eglDisplay, _eglContext);
			_eglContext = EGL_NO_CONTEXT;
		}

		if (_eglSurface != EGL_NO_SURFACE) {
			eglDestroySurface(_eglDisplay, _eglSurface);
			_eglSurface = EGL_NO_SURFACE;
		}

		eglTerminate(_eglDisplay);
		_eglDisplay = EGL_NO_DISPLAY;
	}
}

void RenderView::render() {
	if (!eglSwapBuffers(_eglDisplay, _eglSurface)) {
		LOG_E("Error swapping buffers: %d", eglGetError());
	}
}
