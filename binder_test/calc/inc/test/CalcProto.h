#ifndef CALC_COMMAND_PROTO_H_
#define CALC_COMMAND_PROTO_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Parcelable.h>
#include <binder/Status.h>
#include <test/CalcProto.pb.h>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

#include <cstdint>

namespace test {

struct CalcCommand : public ::android::Parcelable {
  CalcCommandProto command;
  CalcCommand() {}
  virtual android::status_t writeToParcel(android::Parcel* parcel) const;
  virtual android::status_t readFromParcel(const android::Parcel* parcel);
};

struct CalcResult : public ::android::Parcelable {
  CalcResultProto result;
  CalcResult() {}
  virtual android::status_t writeToParcel(android::Parcel* parcel) const;
  virtual android::status_t readFromParcel(const android::Parcel* parcel);
};

}  // namespace test

#endif
