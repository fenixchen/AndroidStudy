#ifndef AIDL_GENERATED_TEST_I_CALC_SERVICE_H_
#define AIDL_GENERATED_TEST_I_CALC_SERVICE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <test/CalcProto.h>
#include <test/ICalcCallback.h>
#include <test/Rectangle.h>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace test {

class ICalcService : public ::android::IInterface {
public:
DECLARE_META_INTERFACE(CalcService)
enum  : int32_t {
  CONST_A = 1,
  CONST_B = 2,
  CONST_C = 3,
};
virtual ::android::binder::Status getRect(::test::Rectangle* _aidl_return) = 0;
virtual ::android::binder::Status add(int32_t a, int32_t b, int32_t c, int32_t* _aidl_return) = 0;
virtual ::android::binder::Status basicTypes(int32_t anInt, int64_t aLong, bool aBoolean, float aFloat, double aDouble, const ::android::String16& aString) = 0;
virtual ::android::binder::Status addAsync(int32_t a, int32_t b, int32_t c, const ::android::sp<::test::ICalcCallback>& callback) = 0;
virtual ::android::binder::Status InvokeCommand(const ::test::CalcCommand& command, ::test::CalcResult* result) = 0;
enum Call {
  GETRECT = ::android::IBinder::FIRST_CALL_TRANSACTION + 0,
  ADD = ::android::IBinder::FIRST_CALL_TRANSACTION + 1,
  BASICTYPES = ::android::IBinder::FIRST_CALL_TRANSACTION + 2,
  ADDASYNC = ::android::IBinder::FIRST_CALL_TRANSACTION + 3,
  INVOKECOMMAND = ::android::IBinder::FIRST_CALL_TRANSACTION + 4,
};
};  // class ICalcService

}  // namespace test

#endif  // AIDL_GENERATED_TEST_I_CALC_SERVICE_H_
