#include <stdio.h>
#include <utils/RefBase.h>

using namespace android;

class LightClass : public LightRefBase<LightClass>
{
    public:
        LightClass()
        {
            printf("LightClass()\n");
        }
        ~LightClass()
        {
            printf("~LightClass()\n");
        }
};

class WeightClass : public RefBase
{
    public:
        void printRefCount()
        {
            int32_t strong = getStrongCount();
            int32_t weak = getWeakRefs()->getWeakCount();
            printf("Strong:%d, Weak:%d\n", strong, weak);
        }
};

class StrongClass : public WeightClass
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
};

class WeakClass : public WeightClass
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
};

int main()
{
    printf("\n\nLightClass test!\n");
    {
        LightClass *pLightClass = new LightClass();
        sp<LightClass> lpOut = pLightClass;
        printf("RefCount:%d\n", pLightClass->getStrongCount());
        {
            sp<LightClass> lpInner = lpOut;
            printf("RefCount:%d\n", pLightClass->getStrongCount());
        }
        printf("RefCount:%d\n", pLightClass->getStrongCount());
    }
    printf("\n\nStrongClass test!\n");
    {
        StrongClass *pClass = new StrongClass();
        wp<StrongClass> wpClass = pClass;
        pClass->printRefCount();
        {
            sp<StrongClass> spClass = pClass;
            spClass->printRefCount();
        }
        sp<StrongClass> sp1 = wpClass.promote();
        printf("sp1:%p\n", sp1.get());
    }
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
    return 0;
}
