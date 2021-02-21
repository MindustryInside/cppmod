#ifndef JAVA_OBJECT_H
#define JAVA_OBJECT_H

#include "jni.h"
#include "java_method.h"
#include "java_field.h"

class JavaObject {
    public:
        template <typename R, typename... Args>
        JavaMethod<R, Args...> getMethod(const char *name, const char *signature);

        template <typename R>
        JavaField<R> getField(const char *name, const char *signature);

        jobject javaObject;
        jclass javaClass;
};

#include "java_object_impl.h"

#endif
