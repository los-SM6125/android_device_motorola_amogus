ifeq ($(TARGET_DEVICE),amogus)

LOCAL_PATH := $(call my-dir)

LIBION_HEADER_PATHS := system/memory/libion/include system/memory/libion/kernel-headers

include $(call all-subdir-makefiles)

ifneq ($(PRODUCT_VENDOR_KERNEL_HEADERS),)
$(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr: $(wildcard $(PRODUCT_VENDOR_KERNEL_HEADERS)/*)
	rm -rf $@
	mkdir -p $@/include
	cp -a $(PRODUCT_VENDOR_KERNEL_HEADERS)/. $@/include
else
GENERATED_KERNEL_INCLUDES_DIR := $(SOONG_OUT_DIR)/.intermediates/vendor/lineage/build/soong/generated_kernel_includes/gen
$(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr: $(GENERATED_KERNEL_INCLUDES_DIR)/.dummy_dep
	mkdir -p $@/techpack/audio
	ln -sfn $(abspath $(GENERATED_KERNEL_INCLUDES_DIR)/usr/include) $@/include
	ln -sfn $(abspath $(GENERATED_KERNEL_INCLUDES_DIR)/usr/audio/include/uapi) $@/techpack/audio/include
	touch $@
endif

include $(CLEAR_VARS)
LOCAL_MODULE := amogus_folders
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)

LOCAL_POST_INSTALL_CMD := mkdir -p \
    $(TARGET_OUT_VENDOR)/etc/sensors/config

include $(BUILD_PHONY_PACKAGE)

endif
