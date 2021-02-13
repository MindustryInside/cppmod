#include <jni.h>
#include <iostream>
#include "include/nativeio_jni_Natives.h"

JNIEXPORT void JNICALL Java_nativeio_jni_Natives_nativeInit(JNIEnv *env, jclass) {
    jclass mainClass = env->FindClass("nativeio/Main");
    jmethodID printMethod = env->GetStaticMethodID(mainClass, "print", "(Ljava/lang/String;)V");

    jstring str = env->NewStringUTF("Hello World from C++ using Main.print!");
    env->CallStaticVoidMethod(mainClass, printMethod, str);
}
