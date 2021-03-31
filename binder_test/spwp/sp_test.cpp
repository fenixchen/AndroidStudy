#include <stdio.h>
#include <utils/RefBase.h>

using namespace android;

class StrongClass : public RefBase
{
    public:
        StrongClass()
        {
            printf("Call %s();\n", __FUNCTION__);
        }
        ~StrongClass()
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

void test_sp()
{
    printf("\n\nStrongClass test!\n");
    {
        StrongClass *pClass = new StrongClass();
        wp<StrongClass> wpClass = pClass;
        pClass->printRefCount();
        {
            // String reference release here
            sp<StrongClass> spClass = pClass;
            spClass->printRefCount();
        }
        sp<StrongClass> sp1 = wpClass.promote();
        printf("sp1:%p\n", sp1.get());
    }
}
