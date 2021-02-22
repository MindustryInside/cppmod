cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(nativeio CXX)

include(GNUInstallDirs)

add_library(nativeio SHARED
    src/cpp/exports.cpp
    src/cpp/functions.cpp
    src/cpp/functions.h
    src/cpp/globals.cpp
    src/cpp/globals.h
    src/cpp/jni/java_class_impl.h
    src/cpp/jni/java_class.h
    src/cpp/jni/java_field_impl.h
    src/cpp/jni/java_field.h
    src/cpp/jni/java_method_impl.h
    src/cpp/jni/java_method.h
    src/cpp/jni/java_object_impl.h
    src/cpp/jni/java_object.h
    src/cpp/jni/jni.h
    src/cpp/jni/typed_methods.h
)

set_target_properties(nativeio PROPERTIES PREFIX "")

target_include_directories(nativeio PRIVATE src/cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

include_directories(src/cpp)

install(TARGETS nativeio
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
