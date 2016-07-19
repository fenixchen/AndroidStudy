#include <stdio.h>

#define LOG_TAG "spwp"
#include <utils/Log.h>
#include <utils/RefBase.h>

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
