#include <iostream>
#include <jni.h>
#include "include/nativeio_jni_Natives.h"
#include "include/nativeio_jni_Natives2.h"

JNIEXPORT void JNICALL Java_nativeio_jni_Natives_init
        (JNIEnv *, jclass) {
    std::cout << "Hello, World!" << std::endl;
}

JNIEXPORT void JNICALL Java_nativeio_jni_Natives2_init2
  (JNIEnv *, jclass) {
    std::cout << "Hello, World 2!" << std::endl;
}
