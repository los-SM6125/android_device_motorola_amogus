/*
 * Shim bridging android.frameworks.displayservice@1.0 C++ clients (e.g.
 * prebuilt camera HAL blobs) to lineage.frameworks.displayservice@1.0.
 */

#define LOG_TAG "android.frameworks.displayservice@1.0-shim"

#include <android/hidl/base/1.0/IBase.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hidl/manager/1.0/IServiceNotification.h>
#include <hidl/HidlSupport.h>
#include <hidl/ServiceManagement.h>
#include <hidl/Status.h>
#include <lineage/frameworks/displayservice/1.0/IDisplayEventReceiver.h>
#include <lineage/frameworks/displayservice/1.0/IDisplayService.h>
#include <lineage/frameworks/displayservice/1.0/IEventCallback.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

#include <string>

namespace android {
namespace frameworks {
namespace displayservice {
namespace V1_0 {

enum class Status : uint32_t {
    SUCCESS = 0u,
    BAD_VALUE = 1u,
    UNKNOWN = 2u,
};

struct IEventCallback : public ::android::hidl::base::V1_0::IBase {
    typedef ::android::hardware::details::i_tag _hidl_tag;
    static const char* descriptor;

    virtual bool isRemote() const override { return false; }

    virtual ::android::hardware::Return<void> onVsync(uint64_t timestamp, uint32_t count) = 0;
    virtual ::android::hardware::Return<void> onHotplug(uint64_t timestamp, bool connected) = 0;

    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;
    virtual ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;

    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;
    virtual ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;

    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;
    virtual ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> setHALInstrumentation() override;
    virtual ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;
    virtual ::android::hardware::Return<void> ping() override;

    using getDebugInfo_cb = std::function<void(const ::android::hidl::base::V1_0::DebugInfo& info)>;
    virtual ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> notifySyspropsChanged() override;
    virtual ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

    static ::android::hardware::Return<::android::sp<IEventCallback>> castFrom(const ::android::sp<IEventCallback>& parent, bool emitError = false);
    static ::android::hardware::Return<::android::sp<IEventCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    static ::android::sp<IEventCallback> tryGetService(const std::string& serviceName = "default", bool getStub = false);
    static ::android::sp<IEventCallback> getService(const std::string& serviceName = "default", bool getStub = false);
    __attribute__((warn_unused_result)) ::android::status_t registerAsService(const std::string& serviceName = "default");
    static bool registerForNotifications(const std::string& serviceName, const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification>& notification);
};

struct IDisplayEventReceiver : public ::android::hidl::base::V1_0::IBase {
    typedef ::android::hardware::details::i_tag _hidl_tag;
    static const char* descriptor;

    virtual bool isRemote() const override { return false; }

    virtual ::android::hardware::Return<Status> init(const ::android::sp<IEventCallback>& callback) = 0;
    virtual ::android::hardware::Return<Status> setVsyncRate(int32_t count) = 0;
    virtual ::android::hardware::Return<Status> requestNextVsync() = 0;
    virtual ::android::hardware::Return<Status> close() = 0;

    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;
    virtual ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;

    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;
    virtual ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;

    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;
    virtual ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> setHALInstrumentation() override;
    virtual ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;
    virtual ::android::hardware::Return<void> ping() override;

    using getDebugInfo_cb = std::function<void(const ::android::hidl::base::V1_0::DebugInfo& info)>;
    virtual ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> notifySyspropsChanged() override;
    virtual ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

    static ::android::hardware::Return<::android::sp<IDisplayEventReceiver>> castFrom(const ::android::sp<IDisplayEventReceiver>& parent, bool emitError = false);
    static ::android::hardware::Return<::android::sp<IDisplayEventReceiver>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    static ::android::sp<IDisplayEventReceiver> tryGetService(const std::string& serviceName = "default", bool getStub = false);
    static ::android::sp<IDisplayEventReceiver> getService(const std::string& serviceName = "default", bool getStub = false);
    __attribute__((warn_unused_result)) ::android::status_t registerAsService(const std::string& serviceName = "default");
    static bool registerForNotifications(const std::string& serviceName, const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification>& notification);
};

struct IDisplayService : public ::android::hidl::base::V1_0::IBase {
    typedef ::android::hardware::details::i_tag _hidl_tag;
    static const char* descriptor;

    virtual bool isRemote() const override { return false; }

    virtual ::android::hardware::Return<::android::sp<IDisplayEventReceiver>> getEventReceiver() = 0;

    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;
    virtual ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;

    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;
    virtual ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;

    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;
    virtual ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> setHALInstrumentation() override;
    virtual ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;
    virtual ::android::hardware::Return<void> ping() override;

    using getDebugInfo_cb = std::function<void(const ::android::hidl::base::V1_0::DebugInfo& info)>;
    virtual ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> notifySyspropsChanged() override;
    virtual ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

    static ::android::hardware::Return<::android::sp<IDisplayService>> castFrom(const ::android::sp<IDisplayService>& parent, bool emitError = false);
    static ::android::hardware::Return<::android::sp<IDisplayService>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    static ::android::sp<IDisplayService> tryGetService(const std::string& serviceName = "default", bool getStub = false);
    static ::android::sp<IDisplayService> getService(const std::string& serviceName = "default", bool getStub = false);
    __attribute__((warn_unused_result)) ::android::status_t registerAsService(const std::string& serviceName = "default");
    static bool registerForNotifications(const std::string& serviceName, const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification>& notification);
};

namespace {

using AndroidDisplayService = ::android::frameworks::displayservice::V1_0::IDisplayService;
using AndroidDisplayEventReceiver = ::android::frameworks::displayservice::V1_0::IDisplayEventReceiver;
using AndroidEventCallback = ::android::frameworks::displayservice::V1_0::IEventCallback;
using AndroidStatus = ::android::frameworks::displayservice::V1_0::Status;
using LineageDisplayService = ::lineage::frameworks::displayservice::V1_0::IDisplayService;
using LineageDisplayEventReceiver = ::lineage::frameworks::displayservice::V1_0::IDisplayEventReceiver;
using LineageEventCallback = ::lineage::frameworks::displayservice::V1_0::IEventCallback;
using LineageStatus = ::lineage::frameworks::displayservice::V1_0::Status;

::android::hardware::Return<AndroidStatus> toAndroidStatus(::android::hardware::Return<LineageStatus>&& ret) {
    if (!ret.isOk()) {
        return ::android::hardware::details::StatusOf<LineageStatus, AndroidStatus>(ret);
    }
    LineageStatus val = ret;
    return static_cast<AndroidStatus>(static_cast<uint32_t>(val));
}

class ShimEventCallback : public LineageEventCallback {
   public:
    explicit ShimEventCallback(const ::android::sp<AndroidEventCallback>& cb) : mCb(cb) {}

    ::android::hardware::Return<void> onVsync(uint64_t timestamp, uint32_t count) override {
        if (mCb != nullptr) {
            return mCb->onVsync(timestamp, count);
        }
        return ::android::hardware::Void();
    }

    ::android::hardware::Return<void> onHotplug(uint64_t timestamp, bool connected) override {
        if (mCb != nullptr) {
            return mCb->onHotplug(timestamp, connected);
        }
        return ::android::hardware::Void();
    }

   private:
    ::android::sp<AndroidEventCallback> mCb;
};

class ShimDisplayEventReceiver : public AndroidDisplayEventReceiver {
   public:
    explicit ShimDisplayEventReceiver(const ::android::sp<LineageDisplayEventReceiver>& impl)
        : mImpl(impl) {}

    bool isRemote() const override { return mImpl->isRemote(); }

    ::android::hardware::Return<AndroidStatus> init(const ::android::sp<AndroidEventCallback>& callback) override {
        if (callback == nullptr) {
            return AndroidStatus::BAD_VALUE;
        }
        ::android::sp<LineageEventCallback> cb = new ShimEventCallback(callback);
        return toAndroidStatus(mImpl->init(cb));
    }

    ::android::hardware::Return<AndroidStatus> setVsyncRate(int32_t count) override {
        return toAndroidStatus(mImpl->setVsyncRate(count));
    }

    ::android::hardware::Return<AndroidStatus> requestNextVsync() override {
        return toAndroidStatus(mImpl->requestNextVsync());
    }

    ::android::hardware::Return<AndroidStatus> close() override {
        return toAndroidStatus(mImpl->close());
    }

    ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override {
        return mImpl->linkToDeath(recipient, cookie);
    }

    ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override {
        return mImpl->unlinkToDeath(recipient);
    }

    ::android::hardware::Return<void> ping() override {
        return mImpl->ping();
    }

   private:
    ::android::sp<LineageDisplayEventReceiver> mImpl;
};

class ShimDisplayService : public AndroidDisplayService {
   public:
    explicit ShimDisplayService(const ::android::sp<LineageDisplayService>& impl)
        : mImpl(impl) {}

    bool isRemote() const override { return mImpl->isRemote(); }

    ::android::hardware::Return<::android::sp<AndroidDisplayEventReceiver>> getEventReceiver() override {
        auto ret = mImpl->getEventReceiver();
        if (!ret.isOk()) {
            return ::android::hardware::details::StatusOf<
                ::android::sp<LineageDisplayEventReceiver>,
                ::android::sp<AndroidDisplayEventReceiver>>(ret);
        }
        ::android::sp<LineageDisplayEventReceiver> recv = ret;
        return recv != nullptr ? ::android::sp<AndroidDisplayEventReceiver>(new ShimDisplayEventReceiver(recv)) : nullptr;
    }

    ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override {
        return mImpl->linkToDeath(recipient, cookie);
    }

    ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override {
        return mImpl->unlinkToDeath(recipient);
    }

    ::android::hardware::Return<void> ping() override {
        return mImpl->ping();
    }

   private:
    ::android::sp<LineageDisplayService> mImpl;
};

::android::hidl::base::V1_0::DebugInfo makeDefaultDebugInfo() {
    ::android::hidl::base::V1_0::DebugInfo info = {};
    info.pid = -1;
    info.ptr = 0;
#if defined(__LP64__)
    info.arch = ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_64BIT;
#else
    info.arch = ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_32BIT;
#endif
    return info;
}

}  // namespace

// IEventCallback
const char* IEventCallback::descriptor("android.frameworks.displayservice@1.0::IEventCallback");

::android::hardware::Return<void> IEventCallback::interfaceChain(interfaceChain_cb _hidl_cb) {
    _hidl_cb({descriptor, ::android::hidl::base::V1_0::IBase::descriptor});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEventCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) {
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEventCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) {
    _hidl_cb(descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEventCallback::getHashChain(getHashChain_cb _hidl_cb) {
    _hidl_cb({
        (uint8_t[32]){24,151,6,13,13,157,159,96,196,94,62,245,122,229,15,243,226,206,38,71,76,108,33,125,127,246,94,46,207,163,9,31},
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76},
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEventCallback::setHALInstrumentation() { return ::android::hardware::Void(); }
::android::hardware::Return<bool> IEventCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) {
    (void)cookie;
    return (recipient != nullptr);
}
::android::hardware::Return<void> IEventCallback::ping() { return ::android::hardware::Void(); }
::android::hardware::Return<void> IEventCallback::getDebugInfo(getDebugInfo_cb _hidl_cb) {
    _hidl_cb(makeDefaultDebugInfo());
    return ::android::hardware::Void();
}
::android::hardware::Return<void> IEventCallback::notifySyspropsChanged() {
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}
::android::hardware::Return<bool> IEventCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) {
    return (recipient != nullptr);
}
::android::hardware::Return<::android::sp<IEventCallback>> IEventCallback::castFrom(const ::android::sp<IEventCallback>& parent, bool) { return parent; }
::android::hardware::Return<::android::sp<IEventCallback>> IEventCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>&, bool) { return nullptr; }
::android::sp<IEventCallback> IEventCallback::tryGetService(const std::string&, bool) { return nullptr; }
::android::sp<IEventCallback> IEventCallback::getService(const std::string&, bool) { return nullptr; }
::android::status_t IEventCallback::registerAsService(const std::string&) { return ::android::INVALID_OPERATION; }
bool IEventCallback::registerForNotifications(const std::string&, const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification>&) { return false; }

// IDisplayEventReceiver
const char* IDisplayEventReceiver::descriptor("android.frameworks.displayservice@1.0::IDisplayEventReceiver");

::android::hardware::Return<void> IDisplayEventReceiver::interfaceChain(interfaceChain_cb _hidl_cb) {
    _hidl_cb({descriptor, ::android::hidl::base::V1_0::IBase::descriptor});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDisplayEventReceiver::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) {
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDisplayEventReceiver::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) {
    _hidl_cb(descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDisplayEventReceiver::getHashChain(getHashChain_cb _hidl_cb) {
    _hidl_cb({
        (uint8_t[32]){172,46,47,60,54,109,200,236,189,71,51,254,222,225,203,234,165,225,52,194,48,165,136,224,200,227,178,219,225,9,57,94},
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76},
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDisplayEventReceiver::setHALInstrumentation() { return ::android::hardware::Void(); }
::android::hardware::Return<bool> IDisplayEventReceiver::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) {
    (void)cookie;
    return (recipient != nullptr);
}
::android::hardware::Return<void> IDisplayEventReceiver::ping() { return ::android::hardware::Void(); }
::android::hardware::Return<void> IDisplayEventReceiver::getDebugInfo(getDebugInfo_cb _hidl_cb) {
    _hidl_cb(makeDefaultDebugInfo());
    return ::android::hardware::Void();
}
::android::hardware::Return<void> IDisplayEventReceiver::notifySyspropsChanged() {
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}
::android::hardware::Return<bool> IDisplayEventReceiver::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) {
    return (recipient != nullptr);
}
::android::hardware::Return<::android::sp<IDisplayEventReceiver>> IDisplayEventReceiver::castFrom(const ::android::sp<IDisplayEventReceiver>& parent, bool) { return parent; }
::android::hardware::Return<::android::sp<IDisplayEventReceiver>> IDisplayEventReceiver::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    auto ret = LineageDisplayEventReceiver::castFrom(parent, emitError);
    if (!ret.isOk()) {
        return ::android::hardware::details::StatusOf<
            ::android::sp<LineageDisplayEventReceiver>,
            ::android::sp<IDisplayEventReceiver>>(ret);
    }
    ::android::sp<LineageDisplayEventReceiver> recv = ret;
    return recv != nullptr ? ::android::sp<IDisplayEventReceiver>(new ShimDisplayEventReceiver(recv)) : nullptr;
}
::android::sp<IDisplayEventReceiver> IDisplayEventReceiver::tryGetService(const std::string&, bool) { return nullptr; }
::android::sp<IDisplayEventReceiver> IDisplayEventReceiver::getService(const std::string&, bool) { return nullptr; }
::android::status_t IDisplayEventReceiver::registerAsService(const std::string&) { return ::android::INVALID_OPERATION; }
bool IDisplayEventReceiver::registerForNotifications(const std::string&, const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification>&) { return false; }

// IDisplayService
const char* IDisplayService::descriptor("android.frameworks.displayservice@1.0::IDisplayService");

::android::hardware::Return<void> IDisplayService::interfaceChain(interfaceChain_cb _hidl_cb) {
    _hidl_cb({descriptor, ::android::hidl::base::V1_0::IBase::descriptor});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDisplayService::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) {
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDisplayService::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) {
    _hidl_cb(descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDisplayService::getHashChain(getHashChain_cb _hidl_cb) {
    _hidl_cb({
        (uint8_t[32]){126,130,173,14,104,0,92,21,190,107,148,36,126,75,36,10,151,139,170,132,241,127,177,15,8,35,201,93,107,245,70,220},
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76},
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDisplayService::setHALInstrumentation() { return ::android::hardware::Void(); }
::android::hardware::Return<bool> IDisplayService::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) {
    (void)cookie;
    return (recipient != nullptr);
}
::android::hardware::Return<void> IDisplayService::ping() { return ::android::hardware::Void(); }
::android::hardware::Return<void> IDisplayService::getDebugInfo(getDebugInfo_cb _hidl_cb) {
    _hidl_cb(makeDefaultDebugInfo());
    return ::android::hardware::Void();
}
::android::hardware::Return<void> IDisplayService::notifySyspropsChanged() {
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}
::android::hardware::Return<bool> IDisplayService::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) {
    return (recipient != nullptr);
}
::android::hardware::Return<::android::sp<IDisplayService>> IDisplayService::castFrom(const ::android::sp<IDisplayService>& parent, bool) { return parent; }
::android::hardware::Return<::android::sp<IDisplayService>> IDisplayService::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    auto ret = LineageDisplayService::castFrom(parent, emitError);
    if (!ret.isOk()) {
        return ::android::hardware::details::StatusOf<
            ::android::sp<LineageDisplayService>,
            ::android::sp<IDisplayService>>(ret);
    }
    ::android::sp<LineageDisplayService> svc = ret;
    return svc != nullptr ? ::android::sp<IDisplayService>(new ShimDisplayService(svc)) : nullptr;
}

::android::sp<IDisplayService> IDisplayService::tryGetService(const std::string& serviceName, const bool getStub) {
    auto svc = LineageDisplayService::tryGetService(serviceName, getStub);
    return svc != nullptr ? new ShimDisplayService(svc) : nullptr;
}

::android::sp<IDisplayService> IDisplayService::getService(const std::string& serviceName, const bool getStub) {
    auto svc = LineageDisplayService::getService(serviceName, getStub);
    return svc != nullptr ? new ShimDisplayService(svc) : nullptr;
}

::android::status_t IDisplayService::registerAsService(const std::string&) { return ::android::INVALID_OPERATION; }
bool IDisplayService::registerForNotifications(const std::string& serviceName, const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification>& notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success = sm->registerForNotifications(
        LineageDisplayService::descriptor, serviceName, notification);
    return success.isOk() && success;
}

}  // namespace V1_0
}  // namespace displayservice
}  // namespace frameworks
}  // namespace android
