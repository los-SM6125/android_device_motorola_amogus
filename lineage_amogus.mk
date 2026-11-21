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
PRODUCT_ENABLE_UFFD_GC := false

# Libhidl
PLATFORM_PROVIDES_LIBHIDL := true
