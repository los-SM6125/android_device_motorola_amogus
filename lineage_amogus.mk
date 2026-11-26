# Copyright 2014 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_base_telephony.mk)

# Inherit device makefile
$(call inherit-product, device/motorola/amogus/device.mk)

# Disable LineageOS EPPE because AOSPA qcom_common / sm8150 declare multi-SoC packages
TARGET_DISABLE_EPPE := true

# Exclude unused LineageOS qcom-caf and AOSP qcom SoC trees and GKI-only QCOM libs that depend on Lineage qcom-caf/common defaults/headers
PRODUCT_SOURCE_ROOT_DIRS += \
    -hardware/qcom/audio \
    -hardware/qcom/sdm845 \
    -hardware/qcom/sm7250 \
    -hardware/qcom/sm8150 \
    -hardware/qcom-caf/msm8953 \
    -hardware/qcom-caf/msm8996 \
    -hardware/qcom-caf/msm8998 \
    -hardware/qcom-caf/sdm660 \
    -hardware/qcom-caf/sdm845 \
    -hardware/qcom-caf/sm8150 \
    -hardware/qcom-caf/sm8250 \
    -hardware/qcom-caf/sm8350 \
    -hardware/qcom-caf/sm8450 \
    -hardware/qcom-caf/sm8450-6.6 \
    -hardware/qcom-caf/sm8550 \
    -hardware/qcom-caf/sm8650 \
    -hardware/qcom-caf/sm8750 \
    -hardware/qcom-caf/sm8850 \
    -vendor/qcom/common/vendor/adreno/s \
    -vendor/qcom/common/vendor/adreno/t \
    -vendor/qcom/common/vendor/adreno/u \
    -vendor/qcom/common/vendor/display/4.9 \
    -vendor/qcom/common/vendor/display/5.10 \
    -vendor/qcom/common/vendor/display/5.15 \
    -vendor/qcom/common/vendor/media/5.4 \
    -vendor/qcom/common/vendor/media/5.10 \
    -vendor/qcom/common/vendor/perf \
    -vendor/qcom/opensource/libvmmem

# Inherit some common Lineage stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Device identifiers
DEVICE := amogus
PRODUCT_BRAND := motorola
PRODUCT_DEVICE := amogus
PRODUCT_MANUFACTURER := motorola
PRODUCT_NAME := lineage_amogus

PRODUCT_GMS_CLIENTID_BASE := android-motorola

# UFFD
PRODUCT_ENABLE_UFFD_GC := true

# Libhidl
PLATFORM_PROVIDES_LIBHIDL := true

# GApps (MindTheGapps)
WITH_GAPPS ?= true
ifeq ($(WITH_GAPPS),true)
$(call inherit-product-if-exists, vendor/gapps/arm64/arm64-vendor.mk)
endif
