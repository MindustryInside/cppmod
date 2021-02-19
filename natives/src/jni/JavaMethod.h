#ifndef JAVA_METHOD_H
#define JAVA_METHOD_H

#include "Jni.h"

template <typename R, typename... Args>
class JavaMethod {
    public:
        R run(Args... args);

        jobject javaObject;
        jmethodID javaMethod;
};


template <typename R, typename... Args>
class JavaStaticMethod {
    public:
        R run(Args... args);

        jclass javaClass;
        jmethodID javaMethod;
};

#endif
