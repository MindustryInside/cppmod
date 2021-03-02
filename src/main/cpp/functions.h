#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "jni/jni.h"
#include "jni/java_class.h"
#include "jni/java_object.h"

JavaClass getClass(const char *className);

template <typename... Args>
JavaObject newObject(jclass clazz, jmethodID method, Args... args);

JNIEnv *obtainEnv();

#endif
