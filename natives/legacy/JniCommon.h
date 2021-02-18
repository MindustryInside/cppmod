#ifndef __Common_h_
#define __Common_h_

#include <jni.h>

#define JAVA_VERSION JNI_VERSION_1_6

#define BOOLEAN_SIG "Z"
#define BYTE_SIG "B"
#define CHAR_SIG "C"
#define SHORT_SIG "S"
#define INT_SIG "I"
#define LONG_SIG "J"
#define FLOAT_SIG "F"
#define DOUBLE_SIG "D"
#define OBJECT_SIG "L"

// --
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <iostream>
// --

class JavaMethod {
    public:
        static JavaMethod create(JNIEnv *env, jclass clazz, const char *methodName, const char *signature, bool ztatic);

        template <typename Return, typename... Params>
        Return run(Params...);

        void setClazz(jclass clazz);
        void setMethodID(jmethodID methodID);
        void setStatic(bool ztatic);
        void setName(const char *name);
        void setSignature(const char *signature);

    private:
        JavaMethod(JNIEnv *env);

    private:
        JNIEnv *env;

        jclass _clazz;
        jmethodID _method;

        bool _static;

        const char *_name;
        const char *_signature;
};

class JavaField {
    public:
        static JavaField *create(JNIEnv *env, const char *fieldName, const char *signature);

        template <typename T>
        T get();

    private:
        JavaField(JNIEnv *env);

    private:
        JNIEnv *env;

        jclass _clazz;
        jfieldID _field;

        bool _static;

        const char *_name;
        const char *_signature;
};

class JavaClass {
    public:
        static JavaClass *create(JNIEnv *env, const char *className);

        JavaMethod getMethod(const char *methodName, const char *signature, bool ztatic);
        JavaField getField(const char *methodName, const char *signature, bool ztatic);

        void setClazz(jclass clazz);
        void setName(const char *name);

    private:
        JavaClass(JNIEnv *env);

    private:
        JNIEnv *env;

        jclass _clazz;

        const char *_name;

        std::map<std::string, JavaMethod> _methods;
        std::map<std::string, JavaField> _fields;
};

#endif
