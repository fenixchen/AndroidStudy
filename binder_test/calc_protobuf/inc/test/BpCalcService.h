#ifndef AIDL_GENERATED_TEST_BP_CALC_SERVICE_H_
#define AIDL_GENERATED_TEST_BP_CALC_SERVICE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <test/ICalcService.h>

namespace test {

class BpCalcService : public ::android::BpInterface<ICalcService> {
public:
explicit BpCalcService(const ::android::sp<::android::IBinder>& _aidl_impl);
virtual ~BpCalcService() = default;
::android::binder::Status getRect(::test::Rectangle* _aidl_return) override;
::android::binder::Status add(int32_t a, int32_t b, int32_t c, int32_t* _aidl_return) override;
::android::binder::Status basicTypes(int32_t anInt, int64_t aLong, bool aBoolean, float aFloat, double aDouble, const ::android::String16& aString) override;
::android::binder::Status addAsync(int32_t a, int32_t b, int32_t c, const ::android::sp<::test::ICalcCallback>& callback) override;
::android::binder::Status InvokeCommand(const ::test::CalcCommand& command, ::test::CalcResult* result) override;
};  // class BpCalcService

}  // namespace test

#endif  // AIDL_GENERATED_TEST_BP_CALC_SERVICE_H_
