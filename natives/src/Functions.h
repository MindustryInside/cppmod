#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "jni/Jni.h"
#include "jni/JavaClass.h"
#include "jni/JavaObject.h"

JavaClass getClass(const char *className);

template <typename... Args>
JavaObject newObject(jclass clazz, jmethodID method, Args... args);

JNIEnv *obtainEnv();

#endif
