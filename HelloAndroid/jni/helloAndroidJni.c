#include <string.h>
#include <jni.h>

jstring Java_com_cch_HelloApp_MainActivity_stringFromJNI( JNIEnv* env, jobject thiz )
{
    return (*env)->NewStringUTF(env, "Hello from JNI !");
}
