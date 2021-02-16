#include "JniCommon.h"

JNIEnv *getEnv(JavaVM *vm) {
    void *env;

    if (vm->GetEnv(&env, JAVA_VERSION) != JNI_OK) {
        std::cout << "pizdec";
        return NULL;
    }

    return (JNIEnv *) env;
}

jint JNI_OnLoad(JavaVM *vm, void *) {
    JNIEnv *env = getEnv(vm);

    JavaClass *clazz = JavaClass::create(env, "arc/math/Mathf");
    
    // jint result = clazz->getMethod("random", "(II)I").run<jint, int>(5, 10);
    // std::cout << (int) result << std::endl;

    JavaMethod method = clazz->getMethod("random", "(II)I", true);

    return JAVA_VERSION;
}
