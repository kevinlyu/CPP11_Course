cmake_minimum_required(VERSION 3.6)
project(HW09)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp TRADE_DATE.cpp TRADE_DATE.h)
add_executable(HW09 ${SOURCE_FILES})