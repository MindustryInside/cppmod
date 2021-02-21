#ifndef JAVA_FIELD_H
#define JAVA_FIELD_H

#include "jni.h"
#include "../functions.h"
#include "typed_methods.h"

extern JNIEnv *obtainEnv();

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

#include "java_field_impl.h"

#endif
