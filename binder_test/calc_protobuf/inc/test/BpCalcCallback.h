#ifndef AIDL_GENERATED_TEST_BP_CALC_CALLBACK_H_
#define AIDL_GENERATED_TEST_BP_CALC_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <test/ICalcCallback.h>

namespace test {

class BpCalcCallback : public ::android::BpInterface<ICalcCallback> {
public:
explicit BpCalcCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
virtual ~BpCalcCallback() = default;
::android::binder::Status done(int32_t result) override;
};  // class BpCalcCallback

}  // namespace test

#endif  // AIDL_GENERATED_TEST_BP_CALC_CALLBACK_H_
