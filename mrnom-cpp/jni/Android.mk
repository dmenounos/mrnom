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

# Basic variables.

empty :=
space := $(empty) $(empty)
comma := ,

# List all ".cpp" files under "$(1)/src".
# $(shell find $(1)/src -name "*.cpp")
#
# Remove the prefix path "$(1)/" in front of "src".
# $(subst $(1)/, $(empty), ...)

LS_CPP = $(subst $(1)/, $(empty), $(shell find $(1)/src -name "*.cpp"))
LOCAL_SRC_FILES := $(call LS_CPP, $(LOCAL_PATH))

# Pre-compiled libraries, i.e.:
# $ANDROID_NDK_HOME/platforms/PLATFORM/ARCHITECTURE/usr/include
# $ANDROID_NDK_HOME/platforms/PLATFORM/ARCHITECTURE/usr/lib

LOCAL_LDLIBS := -landroid -llog -lEGL -lGLESv1_CM

# Compiled libraries, i.e.:
# $ANDROID_NDK_HOME/sources

LOCAL_STATIC_LIBRARIES := android_native_app_glue png

# Launch the compilation process.

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)
$(call import-module,libpng)
