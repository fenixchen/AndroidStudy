#include "test/Rectangle.h"

using namespace test;
using namespace android;

status_t Rectangle::writeToParcel(android::Parcel* parcel) const {
  status_t res;
  res = parcel->writeInt32(x);
  res = parcel->writeInt32(y);
  res = parcel->writeInt32(w);
  res = parcel->writeInt32(h);
  res = parcel->writeString8(name);
  printf("write:%d, %d, %d, %d, %s\n", x, y, w, h, name.string());
  return res;
}
status_t Rectangle::readFromParcel(const android::Parcel* parcel) {
  status_t res;
  res = parcel->readInt32(&x);
  res = parcel->readInt32(&y);
  res = parcel->readInt32(&w);
  res = parcel->readInt32(&h);
  name = parcel->readString8();
  printf("read:%d, %d, %d, %d, %s\n", x, y, w, h, name.string());
  return res;
}