#include "globals.h"
#include "functions.h"
#include <iostream>

jint JNI_OnLoad(JavaVM *vm, void *) {
    Globals::init(vm);

    // jfloat pi = getClass("arc/math/Mathf").getStaticField<jfloat>("PI", "F").get();

    // std::cout << pi << std::endl;

    return JNI_VERSION_1_6;
}
