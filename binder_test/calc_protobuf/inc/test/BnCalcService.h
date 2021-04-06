#ifndef AIDL_GENERATED_TEST_BN_CALC_SERVICE_H_
#define AIDL_GENERATED_TEST_BN_CALC_SERVICE_H_

#include <binder/IInterface.h>
#include <test/ICalcService.h>

namespace test {

class BnCalcService : public ::android::BnInterface<ICalcService> {
public:
::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags = 0) override;
};  // class BnCalcService

}  // namespace test

#endif  // AIDL_GENERATED_TEST_BN_CALC_SERVICE_H_
