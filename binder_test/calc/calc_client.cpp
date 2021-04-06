#include <binder/Binder.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/Parcel.h>
#include <binder/ProcessState.h>
#include <stdio.h>
#include <utils/RefBase.h>

#include "test/BnCalcCallback.h"
#include "test/ICalcCallback.h"
#include "test/ICalcService.h"

using namespace android;
using namespace test;

class MyCalcCallback : public test::BnCalcCallback {
 public:
  MyCalcCallback() {}
  ::android::binder::Status done(int32_t result) {
    printf("Callback result: %d\n", result);
    return ::android::binder::Status::ok();
  }
};

int main() {
  sp<IServiceManager> sm = defaultServiceManager();
  sp<IBinder> binder = sm->getService(String16("test.ICalcService"));
  sp<test::ICalcService> service = interface_cast<test::ICalcService>(binder);

  

  printf("CONST_C:%d\n", (int)test::ICalcService::CONST_C);

  int32_t ret = 0;
  service->add(1, 2, 3, &ret);
  printf("ret=%d\n", ret);

  service->basicTypes(1, 2, true, 1.0, 2.0, String16("你好"));

  sp<MyCalcCallback> callback = new MyCalcCallback();
  service->addAsync(2, 4, 6, callback);

  Rectangle rect;
  service->getRect(&rect);
  printf("Rect(x=%d, y=%d, w=%d, h=%d)\n", rect.x, rect.y, rect.w, rect.h);

  CalcCommand command;
  CalcResult result;  
  command.op = CalcCommand::ADD;
  command.op_name = "Do Add";
  command.vars.push_back(100);
  command.vars.push_back(200);
  command.vars.push_back(300);
  command.vars.push_back(400);
  service->InvokeCommand(command, &result);
  printf("InvokeCommand Result:%d\n", result.result);

  android::ProcessState::self()->startThreadPool();
  IPCThreadState::self()->joinThreadPool();


  return 0;
}
