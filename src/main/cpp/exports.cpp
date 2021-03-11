#include "exports.h"
#include "globals.h"
#include "functions.h"
#include <iostream>

#define info(message) getClass("arc/util/Log") \
                     .getStaticMethod<void, jstring>("info", "(Ljava/lang/Object;)V") \
                     .call(obtainEnv()->NewStringUTF(message));

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *) {
    Globals::init(vm);

    // tests
    // jfloat pi = getClass("arc/math/Mathf").getStaticField<jfloat>("PI", "F").get();
    // std::cout << pi << std::endl;

    // jint integer = getClass("arc/math/Mathf").getStaticMethod<jint, int, int>("random", "(II)I").call(1, 5);
    // std::cout << integer << std::endl;

    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL Java_nativeio_jni_Natives_init(JNIEnv *, jclass) {
    info("[C++] Natives loaded.");
}

JNIEXPORT void JNICALL Java_nativeio_jni_Natives_loadContent(JNIEnv *, jclass) {
    info("[C++] Content loaded.");
}
