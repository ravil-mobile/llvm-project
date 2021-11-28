cmake_minimum_required(VERSION 3.9)
project(meters)


add_library(meters ./src/timer.c)
target_include_directories(meters PUBLIC ./include)
target_compile_options(meters PRIVATE -pedantic)


option(WITH_TEST "build with tests" OFF)
if (WITH_TEST)
    add_executable(test ./test/main.cpp)
    target_link_libraries(test PRIVATE meters)
endif()