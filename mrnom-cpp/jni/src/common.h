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
// NOTICE: TOOLCHAINS / GCC
#include <stdio.h>

// Exact width integer types
// NOTICE: TOOLCHAINS / GCC
#include <stdint.h>

// bool, char, short, int, long limits
// NOTICE: TOOLCHAINS / GCC
#include <limits.h>

#include <assert.h>
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
