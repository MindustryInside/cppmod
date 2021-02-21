#ifndef GLOBALS_H
#define GLOBALS_H

#include "jni/jni.h"

#define JAVA_VERSION JNI_VERSION_1_6
#define EXPORT __declspec(dllexport)

class Globals {
    private:
        Globals();

    public:
        static JavaVM *vm;

    public:
        static void init(JavaVM *vm);
};

#endif
