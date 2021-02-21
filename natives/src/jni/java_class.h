#ifndef JAVA_CLASS_H
#define JAVA_CLASS_H

#include "Jni.h"
#include "java_method.h"
#include "java_field.h"
#include "../functions.h"

extern JNIEnv *obtainEnv();

class JavaClass {
    public:
        template <typename R, typename... Args>
        JavaStaticMethod<R, Args...> getStaticMethod(const char *name, const char *signature);

        template <typename R>
        JavaStaticField<R> getStaticField(const char *name, const char *signature);


        jclass javaClass;
};

#endif
