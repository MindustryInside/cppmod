#include "Globals.h"

Globals::Globals() {}

JavaVM *Globals::vm = nullptr;

void Globals::init(JavaVM *vm) {
    Globals::vm = vm;
}
