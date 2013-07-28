#include "RenderView.hpp"

#include <GLES/gl.h>
#include <GLES/glext.h>

namespace engine {

RenderView::RenderView(android_app* application) :
	mApplication(application),
	mWidth(0), mHeight(0),
	mEglDisplay(EGL_NO_DISPLAY),
	mEglSurface(EGL_NO_SURFACE),
	mEglContext(EGL_NO_CONTEXT) {
	LOG_D("### RenderView::RenderView()");
}

RenderView::~RenderView() {
	LOG_D("### RenderView::~RenderView()");
}

void RenderView::setUp()
{
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

	ANativeWindow* nativeWindow = mApplication->window;

	if (nativeWindow == NULL) {
		goto ERROR;
	}

	mEglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
	if (mEglDisplay == EGL_NO_DISPLAY) goto ERROR;

	if (!eglInitialize(mEglDisplay, NULL, NULL)) {
		goto ERROR;
	}

	// Here, the application chooses the configuration it desires.
	// we have a very simplified selection process, where we pick
	// the first EGLConfig that matches our criteria.

	if (!eglChooseConfig(mEglDisplay, attributes, &config, 1, &numConfigs)) {
		goto ERROR;
	}

	// EGL_NATIVE_VISUAL_ID is an attribute of the EGLConfig that is
	// guaranteed to be accepted by ANativeWindow_setBuffersGeometry().
	// As soon as we picked a EGLConfig, we can safely reconfigure the
	// ANativeWindow buffers to match, using EGL_NATIVE_VISUAL_ID.

	if (!eglGetConfigAttrib(mEglDisplay, config, EGL_NATIVE_VISUAL_ID, &format)) {
		goto ERROR;
	}

	ANativeWindow_setBuffersGeometry(nativeWindow, 0, 0, format);

	// Continue to create the display surface and context according to the
	// selected configuration. A context contains all data related to OpenGL
	// state (settings, matrix stack and so on).

	mEglSurface = eglCreateWindowSurface(mEglDisplay, config, nativeWindow, NULL);
	if (mEglSurface == EGL_NO_SURFACE) goto ERROR;

	mEglContext = eglCreateContext(mEglDisplay, config, EGL_NO_CONTEXT, NULL);
	if (mEglContext == EGL_NO_CONTEXT) goto ERROR;

	if (!eglMakeCurrent(mEglDisplay, mEglSurface, mEglSurface, mEglContext)) {
		goto ERROR;
	}

	if (!eglQuerySurface(mEglDisplay, mEglSurface, EGL_WIDTH, &mWidth)) {
		goto ERROR;
	}

	if (!eglQuerySurface(mEglDisplay, mEglSurface, EGL_HEIGHT, &mHeight)) {
		goto ERROR;
	}

	return;

	ERROR:
	LOG_E("Error while initializing OpenGL: %d", eglGetError());
}

void RenderView::tearDown()
{
	LOG_D("--> RenderView::tearDown()");

	if (mEglDisplay != EGL_NO_DISPLAY) {
		eglMakeCurrent(mEglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);

		if (mEglContext != EGL_NO_CONTEXT) {
			eglDestroyContext(mEglDisplay, mEglContext);
			mEglContext = EGL_NO_CONTEXT;
		}

		if (mEglSurface != EGL_NO_SURFACE) {
			eglDestroySurface(mEglDisplay, mEglSurface);
			mEglSurface = EGL_NO_SURFACE;
		}

		eglTerminate(mEglDisplay);
		mEglDisplay = EGL_NO_DISPLAY;
	}
}

void RenderView::render()
{
	float clearColor = 0.5f;
	// float clearColor = (float) rand() / (float) RAND_MAX;
	glClearColor(clearColor, clearColor, clearColor, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (!eglSwapBuffers(mEglDisplay, mEglSurface)) {
		LOG_E("Error swapping buffers: %d", eglGetError());
	}
}

}
