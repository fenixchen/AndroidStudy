#include <stdio.h>
#include <utils/RefBase.h>

using namespace android;

class WeakClass : public RefBase
{
    public:
        WeakClass()
        {
            extendObjectLifetime(OBJECT_LIFETIME_WEAK);
            printf("Call %s();\n", __FUNCTION__);
        }
        ~WeakClass()
        {
            printf("Call %s();\n", __FUNCTION__);
        }
        void printRefCount()
        {
            int32_t strong = getStrongCount();
            int32_t weak = getWeakRefs()->getWeakCount();
            printf("Strong:%#x, Weak:%d\n", strong, weak);
        }        
};

void test_wp()
{
    printf("\n\nWeakClass test!\n");
    {
        WeakClass *pClass = new WeakClass();
        wp<WeakClass> wpClass = pClass;
        pClass->printRefCount();
        {
            sp<WeakClass> spClass = pClass;
            spClass->printRefCount();
        }
        sp<WeakClass> sp1 = wpClass.promote();
        printf("sp1:%p\n", sp1.get());
    }
}
