#ifndef CALC_COMMAND_PROTO_H_
#define CALC_COMMAND_PROTO_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Parcelable.h>
#include <binder/Status.h>
#include <utils/String8.h>
#include <utils/StrongPointer.h>
#include <vector>
#include <cstdint>

namespace test {


struct CalcCommand : public ::android::Parcelable {
  enum Op{
    ADD = 0,
    SUB = 1,
  };
  Op op;
  android::String8 op_name;
  std::vector<int32_t> vars;
  CalcCommand() {}
  virtual android::status_t writeToParcel(android::Parcel* parcel) const;
  virtual android::status_t readFromParcel(const android::Parcel* parcel);
};

struct CalcResult : public ::android::Parcelable {
  int32_t result;
  CalcResult() {}
  virtual android::status_t writeToParcel(android::Parcel* parcel) const;
  virtual android::status_t readFromParcel(const android::Parcel* parcel);
};

}  // namespace test

#endif
