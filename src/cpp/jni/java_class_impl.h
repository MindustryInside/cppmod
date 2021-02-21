#ifndef JAVA_CLASS_IMPL_H
#define JAVA_CLASS_IMPL_H

#include "jni/java_class.h"
#include "functions.h"

extern JNIEnv *obtainEnv();

template <typename R, typename... Args>
JavaStaticMethod<R, Args...> JavaClass::getStaticMethod(const char *name, const char *signature) {
    JNIEnv *env = obtainEnv();

    jmethodID javaMethod = env->GetStaticMethodID(javaClass, name, signature);

    JavaStaticMethod<R, Args...> method;
    method.javaClass = javaClass;
    method.javaMethod = javaMethod;

    return method;
}

template <typename R>
JavaStaticField<R> JavaClass::getStaticField(const char *name, const char *signature) {
    JNIEnv *env = obtainEnv();

    jfieldID javaField = env->GetStaticFieldID(javaClass, name, signature);

    JavaStaticField<R> field;
    field.javaClass = javaClass;
    field.javaField = javaField;

    return field;
}

#endif
