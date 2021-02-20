#include "JavaField.h"
#include "TypedMethods.h"
#include "../Functions.h"

template <typename R>
R JavaField<R>::get() {
    JNIEnv env = &obtainEnv();

    return env.*(TypedMethods<R>::GetField)(javaObject, javaField);
}

template <typename R>
R JavaStaticField<R>::get() {
    JNIEnv env = &obtainEnv();
    
    return env.*(TypedMethods<R>::GetStaticField)(javaClass, javaField);
}
