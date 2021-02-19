#ifndef JAVA_FIELD_H
#define JAVA_FIELD_H

#include "Jni.h"

template <typename R>
class JavaField {
    public:
        R get();

        jobject javaObject;
        jfieldID javaField;
};

template <typename R>
class JavaStaticField {
    public:
        R get();

        jclass javaClass;
        jfieldID javaField;
};

#endif
