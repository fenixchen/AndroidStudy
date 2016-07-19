LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := spwp
LOCAL_SRC_FILES := main.cpp
LOCAL_SHARED_LIBRARIES += liblog
include $(BUILD_EXECUTABLE)

