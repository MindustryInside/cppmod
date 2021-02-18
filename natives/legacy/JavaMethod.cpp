#include "JniCommon.h"

JavaMethod::JavaMethod(JNIEnv *env) {
    this->env = env;
}

JavaMethod JavaMethod::create(JNIEnv *env, jclass clazz, const char *methodName, const char *signature, bool ztatic) {
    JavaMethod javaMethod(env);

    // jmethodID methodID;

    // if (ztatic) {
    //     methodID = env->GetStaticMethodID(clazz, methodName, signature);
    // } else {
    //     methodID = env->GetMethodID(clazz, methodName, signature);
    // }

    // if (methodID == NULL) {
    //     printf("Method is not defined: %s", methodName);
    //     return nullptr;
    // }

    // javaMethod.setClazz(clazz);
    // javaMethod.setMethodID(methodID);
    // javaMethod.setStatic(ztatic);
    // javaMethod.setName(methodName);
    // javaMethod.setSignature(signature);

    return javaMethod;
}

void JavaMethod::setClazz(jclass clazz) {
    _clazz = clazz;
}

void JavaMethod::setMethodID(jmethodID methodID) {
    _method = methodID;
}

void JavaMethod::setStatic(bool ztatic) {
    _static = ztatic;
}

void JavaMethod::setName(const char *methodName) {
    _name = methodName;
}

void JavaMethod::setSignature(const char *signature) {
    _signature = signature;
}
