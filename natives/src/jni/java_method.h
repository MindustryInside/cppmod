#ifndef JAVA_METHOD_H
#define JAVA_METHOD_H

#include "jni.h"

template <typename R, typename... Args>
class JavaMethod {
    public:
        R call(Args... args);

        jobject javaObject;
        jmethodID javaMethod;
};


template <typename R, typename... Args>
class JavaStaticMethod {
    public:
        R call(Args... args);

        jclass javaClass;
        jmethodID javaMethod;
};

#endif
