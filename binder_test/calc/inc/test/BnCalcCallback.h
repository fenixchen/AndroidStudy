#ifndef AIDL_GENERATED_TEST_BN_CALC_CALLBACK_H_
#define AIDL_GENERATED_TEST_BN_CALC_CALLBACK_H_

#include <binder/IInterface.h>
#include <test/ICalcCallback.h>

namespace test {

class BnCalcCallback : public ::android::BnInterface<ICalcCallback> {
public:
::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags = 0) override;
};  // class BnCalcCallback

}  // namespace test

#endif  // AIDL_GENERATED_TEST_BN_CALC_CALLBACK_H_
