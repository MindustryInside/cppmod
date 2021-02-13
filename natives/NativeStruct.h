#include <jni.h>

#ifndef NATIVESTRUCT_H
#define NATIVESTRUCT_H

class NativeStruct {
    public:
        NativeStruct(JNIEnv *);

    protected:
        JNIEnv *env;
};

#endif
