#include "JniCommon.h"

/* TODO
template <typename Return, typename... Params>
Return JavaMethod::run(Params... pparams) {
    auto params = (pparams, ...);

    if (_static) {
        if (_signature == BOOLEAN_SIG) {
            env->CallStaticBooleanMethod(_clazz, _method, params);
        } else if (_signature == BYTE_SIG) {
            env->CallStaticByteMethod(_clazz, _method, params);
        } else if (_signature == CHAR_SIG) {
            env->CallStaticCharMethod(_clazz, _method, params);
        } else if (_signature == SHORT_SIG) {
            env->CallStaticShortMethod(_clazz, _method, params);
        } else if (_signature == INT_SIG) {
            env->CallStaticIntMethod(_clazz, _method, params);
        } else if (_signature == LONG_SIG) {
            env->CallStaticLongMethod(_clazz, _method, params);
        } else if (_signature == FLOAT_SIG) {
            env->CallStaticFloatMethod(_clazz, _method, params);
        } else if (_signature == DOUBLE_SIG) {
            env-> CallStaticDoubleMethod(_clazz, _method, params);
        } else if (_signature == OBJECT_SIG) {
            env->CallStaticObjectMethod(_clazz, _method, params);
        }
    } else {
        if (_signature == BOOLEAN_SIG) {
            env->CallBooleanMethod(_clazz, _method, params);
        } else if (_signature == BYTE_SIG) {
            env->CallByteMethod(_clazz, _method, params);
        } else if (_signature == CHAR_SIG) {
            env->CallCharMethod(_clazz, _method, params);
        } else if (_signature == SHORT_SIG) {
            env->CallShortMethod(_clazz, _method, params);
        } else if (_signature == INT_SIG) {
            env->CallIntMethod(_clazz, _method, params);
        } else if (_signature == LONG_SIG) {
            env->CallLongMethod(_clazz, _method, params);
        } else if (_signature == FLOAT_SIG) {
            env->CallFloatMethod(_clazz, _method, params);
        } else if (_signature == DOUBLE_SIG) {
            env->CallDoubleMethod(_clazz, _method, params);
        } else if (_signature == OBJECT_SIG) {
            env->CallObjectMethod(_clazz, _method, params);
        }
    }
}

template <typename T>
T JavaField::get() {
    if (_static) {
        if (_signature == BOOLEAN_SIG) {
            env->GetStaticBooleanField(_clazz, _field);
        } else if (_signature == BYTE_SIG) {
            env->GetStaticByteField(_clazz, _field);
        } else if (_signature == CHAR_SIG) {
            env->GetStaticCharField(_clazz, _field);
        } else if (_signature == SHORT_SIG) {
            env->GetStaticShortField(_clazz, _field);
        } else if (_signature == INT_SIG) {
            env->GetStaticIntField(_clazz, _field);
        } else if (_signature == LONG_SIG) {
            env->GetStaticLongField(_clazz, _field);
        } else if (_signature == FLOAT_SIG) {
            env->GetStaticFloatField(_clazz, _field);
        } else if (_signature == DOUBLE_SIG) {
            env-> GetStaticDoubleField(_clazz, _field);
        } else if (_signature == OBJECT_SIG) {
            env->GetStaticObjectField(_clazz, _field);
        }
    } else {
        if (_signature == BOOLEAN_SIG) {
            env->GetBooleanField(_clazz, _field);
        } else if (_signature == BYTE_SIG) {
            env->GetByteField(_clazz, _field);
        } else if (_signature == CHAR_SIG) {
            env->GetCharField(_clazz, _field);
        } else if (_signature == SHORT_SIG) {
            env->GetShortField(_clazz, _field);
        } else if (_signature == INT_SIG) {
            env->GetIntField(_clazz, _field);
        } else if (_signature == LONG_SIG) {
            env->GetLongField(_clazz, _field);
        } else if (_signature == FLOAT_SIG) {
            env->GetFloatField(_clazz, _field);
        } else if (_signature == DOUBLE_SIG) {
            env->GetDoubleField(_clazz, _field);
        } else if (_signature == OBJECT_SIG) {
            env->GetObjectField(_clazz, _field);
        }
    }
}
*/