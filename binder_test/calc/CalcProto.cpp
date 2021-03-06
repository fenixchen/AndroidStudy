#ifndef CALC_COMMAND_H_
#define CALC_COMMAND_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Parcelable.h>
#include <binder/Status.h>
#include <test/CalcProto.h>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

#include <cstdint>

using namespace android;

namespace test {

status_t CalcCommand::writeToParcel(android::Parcel* parcel) const {
  status_t res = 0;
  res = parcel->writeInt32(this->op);
  res = parcel->writeString8(this->op_name);
  res = parcel->writeInt32Vector(this->vars);
  return res;
}
status_t CalcCommand::readFromParcel(const android::Parcel* parcel) {
  status_t res = 0;
  this->op = (CalcCommand::Op)parcel->readInt32();
  this->op_name = parcel->readString8();
  res = parcel->readInt32Vector(&this->vars);
  return res;
}

status_t CalcResult::writeToParcel(android::Parcel* parcel) const {
  status_t res = 0;
  res = parcel->writeInt32(this->result);
  return res;
}
status_t CalcResult::readFromParcel(const android::Parcel* parcel) {
  status_t res = 0;
  this->result = parcel->readInt32();
  return res;
}

}  // namespace test

#endif
