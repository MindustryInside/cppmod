cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(nativeio CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

include(GNUInstallDirs)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

include_directories(src/cpp)

file(GLOB_RECURSE SRC
    src/cpp/*.h
    src/cpp/*.cpp
)

add_library(nativeio SHARED SRC)

install(TARGETS nativeio
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

set_target_properties(nativeio PROPERTIES
    PREFIX ""
    LINKER_LANGUAGE CXX
)

target_include_directories(nativeio PRIVATE src/cpp)
