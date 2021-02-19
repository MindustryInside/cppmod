#ifndef JAVA_CLASS_H
#define JAVA_CLASS_H

#include "Jni.h"
#include "JavaMethod.h"
#include "JavaField.h"

class JavaClass {
    public:
        template <typename R, typename... Args>
        JavaStaticMethod<R, Args...> getStaticMethod();

        template <typename R>
        JavaStaticField<R> getStaticField();

        jclass javaClass;
};

#endif
