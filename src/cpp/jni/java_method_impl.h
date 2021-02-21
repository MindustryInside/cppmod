#ifndef JAVA_METHOD_IMPL_H
#define JAVA_METHOD_IMPL_H

#include "jni/java_method.h"
#include "jni/typed_methods.h"
#include "functions.h"

extern JNIEnv *obtainEnv();

template <typename R, typename... Args>
R JavaMethod<R, Args...>::call(Args... args) {
    JNIEnv *env = obtainEnv();

    return (env->*(TypedMethods<R>::CallMethod))(javaObject, javaMethod, args...);
}

template <typename R, typename... Args>
R JavaStaticMethod<R, Args...>::call(Args... args) {
    JNIEnv *env = obtainEnv();
    
    return (env->*(TypedMethods<R>::CallStaticMethod))(javaClass, javaMethod, args...);
}

#endif
