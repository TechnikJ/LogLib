cmake_minimum_required(VERSION 3.21)

project(LogLibTest)

add_executable(LogLibTest Test.cpp)

if(MSVC)
    target_compile_options(LogLibTest INTERFACE /arch:SSE2)
else()
    target_compile_options(LogLibTest INTERFACE -msse2)
endif()