cmake_minimum_required(VERSION 3.6)
project(HW05_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Car.h Engine.h Police.h)
add_executable(HW05_2 ${SOURCE_FILES})