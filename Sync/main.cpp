#include <stdio.h>

#define LOG_TAG "Sync"
#include <utils/Log.h>
#include <utils/Mutex.h>
#include <utils/Condition.h>
#include <Barrier.h>

using namespace android;

int main()
{
    ALOGI("Mutex test");
    Mutex m; 
    m.lock();
    m.unlock();
    m.tryLock();
    m.unlock();
    {
        AutoMutex autoLock(m);
    }

    ALOGI("Condition test");
    Condition cond;
    cond.signal();
    cond.waitRelative(m, 1000000);
    
    ALOGI("Barrier test");
    Barrier bar;
    bar.open();
    return 0;
}
