#include "java_field.h"
#include "typed_methods.h"
#include "../functions.h"

extern JNIEnv *obtainEnv();

template <typename R>
R JavaField<R>::get() {
    JNIEnv *env = obtainEnv();

    return (env->*(TypedMethods<R>::GetField))(javaObject, javaField);
}

template <typename R>
R JavaStaticField<R>::get() {
    JNIEnv *env = obtainEnv();
    
    return (env->*(TypedMethods<R>::GetStaticField))(javaClass, javaField);
}
