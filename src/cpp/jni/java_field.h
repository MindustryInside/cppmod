#ifndef JAVA_FIELD_H
#define JAVA_FIELD_H

#include "jni/jni.h"
#include "jni/typed_methods.h"
#include "functions.h"

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
