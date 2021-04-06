
#include <binder/Binder.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/Parcel.h>
#include <binder/ProcessState.h>
#include <stdio.h>
#include <unistd.h>
#include <utils/RefBase.h>

#include <cstdlib>
#include <iostream>

#include "test/BnCalcService.h"
#include "test/CalcProto.h"
#include "test/Rectangle.h"

using namespace android;
using namespace test;

class MyCalcService : public BnCalcService {
  ::android::sp<::test::ICalcCallback> m_callback;
 public:
  virtual ~MyCalcService() {}
  ::android::binder::Status getRect(::test::Rectangle *_aidl_return) {
    _aidl_return->x = 100;
    _aidl_return->y = 200;
    _aidl_return->w = 50;
    _aidl_return->h = 80;
    _aidl_return->name = "test_rect";
    return ::android::binder::Status::ok();
  }
  ::android::binder::Status add(int32_t a, int32_t b, int32_t c,
                                int32_t *_aidl_return) {
    printf("Add %d, %d, %d\n", a, b, c);
    *_aidl_return = a + b + c;
    return ::android::binder::Status::ok();
  }
  virtual ::android::binder::Status basicTypes(
      int32_t anInt, int64_t aLong, bool aBoolean, float aFloat, double aDouble,
      const ::android::String16 &aString) {
    String8 str(aString);
    printf("Called:%s\n", (const char *)str);
    return ::android::binder::Status::ok();
  }
  virtual ::android::binder::Status addAsync(
      int32_t a, int32_t b, int32_t c,
      const ::android::sp<::test::ICalcCallback> &callback) {
        printf("before sleep\n");        
    for (int i = 0; i < 10; i ++){
      sleep(2);
    if (callback.get()) {      
      printf("async call\n");
      callback->done(a + b + c + i);    
    }
    }
    return ::android::binder::Status::ok();
  }
  virtual ::android::binder::Status incArray(const ::std::vector<int32_t> &a,
                                             ::std::vector<int32_t> *b) {
    for (auto it = a.begin(); it != a.end(); ++it) {
      b->push_back(*it);
    }
    return ::android::binder::Status::ok();
  }
  virtual ::android::binder::Status InvokeCommand(
      const ::test::CalcCommand &command, ::test::CalcResult *result) {
    const CalcCommandProto &cmd = command.command;
    if (cmd.op_type() == CalcCommandProto::ADD) {
      printf("Do command:%s\n", cmd.command_name().c_str());
      int32_t sum = cmd.var1() + cmd.var2();
      for (int i = 0; i < cmd.var_more_size(); i++) {
        sum += cmd.var_more(i);
      }
      result->result.set_result(sum);
    }
    return ::android::binder::Status::ok();
  }
};

int main() {
  sp<IServiceManager> sm = defaultServiceManager();
  sm->addService(String16("test.ICalcService"), new MyCalcService());
  ProcessState::self()->startThreadPool();
  IPCThreadState::self()->joinThreadPool();
  return 0;
}
