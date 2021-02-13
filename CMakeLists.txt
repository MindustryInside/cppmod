cmake_minimum_required(VERSION 3.4)

project(nativeio)

set(CMAKE_BUILD_TYPE Release)

find_package(JNI REQUIRED)

include_directories(${JNI_INCLUDE_DIRS})
include_directories(libs/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES libs/Natives.cpp)

add_library(nativeio SHARED ${SOURCE_FILES})
