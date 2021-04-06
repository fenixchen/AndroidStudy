#ifndef CALC_RECTANGLE_H_
#define CALC_RECTANGLE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Parcelable.h>
#include <binder/Status.h>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

#include <cstdint>

namespace test {

struct Rectangle : public ::android::Parcelable {
  int x, y, w, h;
  android::String8 name;
  Rectangle() {}
  virtual android::status_t writeToParcel(android::Parcel* parcel) const;
  virtual android::status_t readFromParcel(const android::Parcel* parcel);
};

}  // namespace test

#endif
