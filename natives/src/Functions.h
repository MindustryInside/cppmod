#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "jni/Jni.h"
#include "jni/JavaClass.h"

JavaClass getClass(const char *className);

JNIEnv *obtainEnv();

#endif
