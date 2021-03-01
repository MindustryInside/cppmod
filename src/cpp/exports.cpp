#include "globals.h"
#include "functions.h"
#include <iostream>

EXPORT jint JNI_OnLoad(JavaVM *vm, void *) {
    Globals::init(vm);

    // tests
    jfloat pi = getClass("arc/math/Mathf").getStaticField<jfloat>("PI", "F").get();
    std::cout << pi << std::endl;

    jint integer = getClass("arc/math/Mathf").getStaticMethod<jint, int, int>("random", "(II)I").call(1, 5);
    std::cout << integer << std::endl;

    return JNI_VERSION_1_6;
}
