#include <stdio.h>

#define LOG_TAG "Helloworld"
#include <utils/Log.h>

int main()
{
    printf("Hello Android\n");
    ALOGV("Verbose log");
    ALOGD("Debug log");
    ALOGI("Info log");
    ALOGW("Warn log");
    ALOGE("Error log");
    return 0;
}
