LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := Sync 
LOCAL_SRC_FILES := main.cpp
LOCAL_SHARED_LIBRARIES += liblog
LOCAL_C_INCLUDES += frameworks/native/include system/core/include frameworks/native/services/surfaceflinger
include $(BUILD_EXECUTABLE)

