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

void test_light_ref_base()
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
}
