#include "JavaMethod.h"
#include "TypedMethods.h"
#include "../Functions.h"

template <typename R, typename... Args>
R JavaMethod<R, Args...>::call(Args... args) {
    JNIEnv env = &obtainEnv();

    env.*(TypedMethods<R>::CallMethod)(javaObject, javaMethod, args...);
}

template <typename R, typename... Args>
R JavaStaticMethod<R, Args...>::call(Args... args) {
    JNIEnv env = &obtainEnv();
    
    env.*(TypedMethods<R>::CallStaticMethod)(javaClass, javaMethod, args...);
}
