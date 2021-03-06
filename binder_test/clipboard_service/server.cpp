#include "ipc/gen_clipboard_service_comm.h"
#include "ipc/gen_clipboard_service_svr_impl.h"

int main() {
    android::sp<android::IServiceManager> sm = android::defaultServiceManager();
    sm->addService(android::String16("service.ClipboardService"), new ClipboardServiceImpl());
    android::ProcessState::self()->startThreadPool();
    android::IPCThreadState::self()->joinThreadPool();
    return 0;
}
