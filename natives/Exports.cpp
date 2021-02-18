#include <jni.h>

#define JAVA_VERSION JNI_VERSION_1_6

JNIEnv *getEnv(JavaVM *vm) {
    void *env;

    if (vm->GetEnv(&env, JAVA_VERSION) != JNI_OK) {
        return NULL;
    }

    return (JNIEnv *) env;
}

jint JNI_OnLoad(JavaVM *vm, void *) {
    return JAVA_VERSION;
}
