# Native library building is orchestrated by a Makefile named Android.mk.
# By convension, Android.mk is in folder jni, located inside project's root.
# That way, ndk-build command can find this file automatically when invoked.

# Instruction $(call <function>) allows evaluating a function.
# Function my-dir returns the directory path of the last executed Makefile.

LOCAL_PATH := $(call my-dir)

# Makes sure no "parasite" configuration dirsupts compilation. When compiling
# an application a few LOCAL_XXX variables need to be defined. The problem is
# that one module may define additional configuration settings (like macros or
# flags) through these variables which may not be needed by another module.

include $(CLEAR_VARS)

# Defines the module name. After compilation, the output library is named
# according to the LOCAL_MODULE variable with "lib" prefix and ".so" suffix.
# The LOCAL_MODULE name is also used when a module depends on another module.

LOCAL_MODULE := mrnom

LOCAL_SRC_FILES := src/engine/EventLoop.cpp \
                   src/engine/GameContext.cpp \
                   src/engine/GameScreen.cpp \
                   src/engine/Location.cpp \
                   src/engine/RenderView.cpp \
                   src/engine/ResourceFactory.cpp \
                   src/engine/Resource.cpp \
                   src/engine/Sprite.cpp \
                   src/engine/Texture.cpp \
                   src/engine/Timer.cpp \
                   src/mrnom/LoadingScreen.cpp \
                   src/mrnom/MainMenuScreen.cpp \
                   src/mrnom/MrNomGame.cpp \
                   src/mrnom/World.cpp

LOCAL_LDLIBS := -landroid -llog -lEGL -lGLESv1_CM

LOCAL_STATIC_LIBRARIES := android_native_app_glue png

# This last command launches the compilation process and indicates which type
# of library to generate

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)
$(call import-module,libpng)
