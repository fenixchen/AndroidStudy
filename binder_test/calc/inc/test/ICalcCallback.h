#ifndef AIDL_GENERATED_TEST_I_CALC_CALLBACK_H_
#define AIDL_GENERATED_TEST_I_CALC_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace test {

class ICalcCallback : public ::android::IInterface {
public:
DECLARE_META_INTERFACE(CalcCallback)
virtual ::android::binder::Status done(int32_t result) = 0;
enum Call {
  DONE = ::android::IBinder::FIRST_CALL_TRANSACTION + 0,
};
};  // class ICalcCallback

}  // namespace test

#endif  // AIDL_GENERATED_TEST_I_CALC_CALLBACK_H_
