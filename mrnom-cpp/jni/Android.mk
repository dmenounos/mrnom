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

# $(shell find ...)
# List "*.cpp" files under "$(1)/src".
#
# $(subst ...)
# Remove the prefix path "$(1)/" from each file.

LS_SRC = $(subst $(1)/, , $(shell find $(1)/src -name "*.cpp"))
LOCAL_SRC_FILES := $(call LS_SRC, $(LOCAL_PATH))

# Define pre-compiled dependencies, i.e.:
# $ANDROID_NDK_HOME/platforms/PLATFORM/ARCHITECTURE/usr/lib
# $ANDROID_NDK_HOME/platforms/PLATFORM/ARCHITECTURE/usr/include

LOCAL_LDLIBS := -landroid -llog -lEGL -lGLESv1_CM -lOpenSLES

# Define module dependencies, i.e.:
# $ANDROID_NDK_HOME/sources

LOCAL_STATIC_LIBRARIES := android_native_app_glue png
# LOCAL_SHARED_LIBRARIES := xmp

# Launch the build process.

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)
$(call import-module,libpng)
# $(call import-module,libxmp)
