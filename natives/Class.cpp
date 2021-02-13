#include "Class.h"
#include "TypeSignatures.h"

Class::Class(JNIEnv *jnienv, char *className) : NativeStruct(jnienv) {
    jclass = env->FindClass(className);
}

jfieldID Class::getFieldId(char *fieldName, char *type) {
    return env->GetFieldID(jclass, fieldName, type);
}

jfieldID Class::getBooleanFieldId(char *fieldName) {
    return getFieldId(fieldName, &BOOLEAN);
}

jfieldID Class::getByteFieldId(char *fieldName) {
    return getFieldId(fieldName, &BYTE);
}

jfieldID Class::getCharFieldId(char *fieldName) {
    return getFieldId(fieldName, &CHAR);
}

jfieldID Class::getDoubleFieldId(char *fieldName) {
    return getFieldId(fieldName, &DOUBLE);
}

jfieldID Class::getFloatFieldId(char *fieldName) {
    return getFieldId(fieldName, &FLOAT);
}

jfieldID Class::getIntFieldId(char *fieldName) {
    return getFieldId(fieldName, &INT);
}

jfieldID Class::getLongFieldId(char *fieldName) {
    return getFieldId(fieldName, &LONG);
}

jfieldID Class::getShortFieldId(char *fieldName) {
    return getFieldId(fieldName, &SHORT);
}
