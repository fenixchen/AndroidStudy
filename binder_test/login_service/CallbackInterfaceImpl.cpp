#include <iostream>
#include "CallbackInterfaceImpl.h"

CallbackInterfaceImpl::CallbackInterfaceImpl()
{
    callback_ = NULL;
}

CallbackInterfaceImpl::~CallbackInterfaceImpl()
{
    callback_ = NULL;
}

void CallbackInterfaceImpl::setCallback(LoginCallback *cb) {
    callback_ = cb;
}

int CallbackInterfaceImpl::OnGetQrcode(const std::string& qrcode) {
    if (callback_) {
        callback_->OnGetQrcode(qrcode);
    }
    return 0;
}

int CallbackInterfaceImpl::OnLoginStateChange(int state, const std::string& message) {
    if (callback_) {
        callback_->OnLoginStateChange(state, message);
    }
    return 0;
}

