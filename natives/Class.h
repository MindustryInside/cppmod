#include <jni.h>
#include <type_traits>
#include "NativeStruct.h"

#ifndef CLASS_H
#define CLASS_H

class Class : public NativeStruct {
    public:
        Class(JNIEnv *, char *);

        jfieldID getFieldId(char *, char *);

        jfieldID getBooleanFieldId(char *);
        jfieldID getByteFieldId(char *);
        jfieldID getCharFieldId(char *);
        jfieldID getShortFieldId(char *);
        jfieldID getIntFieldId(char *);
        jfieldID getLongFieldId(char *);
        jfieldID getFloatFieldId(char *);
        jfieldID getDoubleFieldId(char *);

    protected:
        jclass jclass;
};

#endif
