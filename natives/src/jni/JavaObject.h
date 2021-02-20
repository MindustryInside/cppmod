#ifndef JAVA_OBJECT_H
#define JAVA_OBJECT_H

#include "Jni.h"
#include "JavaMethod.h"
#include "JavaField.h"

class JavaObject {
    public:
        template <typename R, typename... Args>
        JavaMethod<R, Args...> getMethod(const char *name, const char *signature);

        template <typename R>
        JavaField<R> getField(const char *name, const char *signature);

        jobject javaObject;
        jclass javaClass;
};

#endif
