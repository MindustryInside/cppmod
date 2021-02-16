#include "JniCommon.h"

JavaClass::JavaClass(JNIEnv *env) {
    this->env = env;
}

JavaClass *JavaClass::create(JNIEnv *env, const char *className) {
    JavaClass javaClass(env);

    jclass clazz = env->FindClass(className);

    if (clazz == NULL) {
        printf("Class is not defined: %s", className);
        return nullptr;
    }

    javaClass.setClazz(clazz);
    javaClass.setName(className);

    return &javaClass;
}

void JavaClass::setClazz(jclass clazz) {
    _clazz = clazz;
}

void JavaClass::setName(const char *className) {
    _name = className;
}

JavaMethod JavaClass::getMethod(char *methodName, char *signature, bool ztatic) {
    JavaMethod *method = JavaMethod::create(env, _clazz, methodName, signature, ztatic);

    // TODO: Cache methods
    // std::string methodSignature(methodName);
    // methodSignature.append(signature);

    // auto mapProperty = _methods.find(methodSignature);

    // if (mapProperty == _methods.end()) {
    // }
    // else
    // {
    //     method = mapProperty->second;
    // }

    return *method;
}
