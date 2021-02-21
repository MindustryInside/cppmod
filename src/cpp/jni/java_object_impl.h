#ifndef JAVA_OBJECT_IMPL_H
#define JAVA_OBJECT_IMPL_H

#include "java_object.h"
#include "../functions.h"

template <typename R, typename... Args>
JavaMethod<R, Args...> JavaObject::getMethod(const char *name, const char *signature) {
    JNIEnv *env = obtainEnv();
    
    jmethodID javaMethod = env->GetMethodID(javaClass, name, signature);

    JavaMethod<R, Args...> method;
    method.javaClass = javaClass;
    method.javaMethod = javaMethod;

    return method;
}

template <typename R>
JavaField<R> JavaObject::getField(const char *name, const char *signature) {
    JNIEnv *env = obtainEnv();

    jfieldID javaField = env->GetFieldID(javaClass, name, signature);

    JavaField<R> field;
    field.javaObject = javaObject;
    field.javaField = javaField;

    return field;
}

#endif
