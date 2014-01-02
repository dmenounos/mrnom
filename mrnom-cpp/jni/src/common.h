#ifndef COMMON_H
#define COMMON_H

/* C APIs */

// Process Control
// Memory Allocation
// Random Number Generation
// String to Number Conversion
#include <stdlib.h>

// Core Input and Output
// Formatted Input and Output
#include <stdio.h>

// Exact width integer types
#include <stdint.h>

// Limits: bool, char, short, int, long
#include <limits.h>

// Diagnostics
#include <assert.h>

// Time
#include <time.h>

// POSIX Process Control
#include <unistd.h>

/* C++ APIs */

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

/* OpenGL APIs */

#include <EGL/egl.h>
#include <GLES/gl.h>
#include <GLES/glext.h>

/* OpenSL APIs */

#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>
#include <SLES/OpenSLES_AndroidConfiguration.h>

/* ANDROID APIs */

#include <android/log.h>
#include <android/looper.h>
#include <android_native_app_glue.h>

/* GAME APIs */

#define LOG_TAG "MrNom"

#define LOG_E(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOG_W(...) __android_log_print(ANDROID_LOG_WARN,  LOG_TAG, __VA_ARGS__)
#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO,  LOG_TAG, __VA_ARGS__)
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

#endif
