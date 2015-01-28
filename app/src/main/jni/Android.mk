LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := testn
LOCAL_SRC_FILES := testn.c
LOCAL_LDLIBS    := -llog

include $(BUILD_SHARED_LIBRARY)