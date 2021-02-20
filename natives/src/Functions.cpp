#include "Functions.h"
#include "Globals.h"

JavaClass getClass(const char *className) {
    JNIEnv *env = obtainEnv();

    jclass clazz = env->FindClass(className);

    JavaClass javaClass;
    javaClass.javaClass = clazz;

    return javaClass;
}

template <typename... Args>
JavaObject newObject(jclass clazz, jmethodID method, Args... args) {
    JNIEnv *env = obtainEnv();

    jobject javaObject = env->NewObject(clazz, method, args...);

    JavaObject object;
    object.javaObject = javaObject;
    object.javaClass = clazz;

    return object;
}

JNIEnv *obtainEnv() {
    JavaVM *vm = Globals::vm;
    void *penv;

    jint response = vm->GetEnv(&penv, JNI_VERSION_1_6);

    if (response != JNI_OK) {
        printf("Failed to GetEnv!");
        return nullptr;
    }

    JNIEnv *env = (JNIEnv *) penv;

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        return nullptr;
    }

    return (JNIEnv *) env;
}
