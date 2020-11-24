cmake_minimum_required(VERSION 3.10)

project(bf)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(bf src/main.cpp src/raii.cpp src/bf.cpp)
