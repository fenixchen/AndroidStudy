#ifndef CALC_COMMAND_H_
#define CALC_COMMAND_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Parcelable.h>
#include <binder/Status.h>
#include <test/CalcProto.h>
#include <test/CalcProto.pb.h>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

#include <cstdint>

using namespace android;

namespace test {

status_t CalcCommand::writeToParcel(android::Parcel* parcel) const {
  status_t res = 0;
  std::string str;
  command.SerializeToString(&str);
  res = parcel->writeCString(str.c_str());
  return res;
}
status_t CalcCommand::readFromParcel(const android::Parcel* parcel) {
  status_t res = 0;
  const char* r = parcel->readCString();
  command.ParseFromString(r);
  return res;
}

status_t CalcResult::writeToParcel(android::Parcel* parcel) const {
  status_t res = 0;
  std::string str;
  result.SerializeToString(&str);
  res = parcel->writeCString(str.c_str());
  return res;
}
status_t CalcResult::readFromParcel(const android::Parcel* parcel) {
  status_t res = 0;
  const char* r = parcel->readCString();
  result.ParseFromString(r);
  return res;
}

}  // namespace test

#endif
