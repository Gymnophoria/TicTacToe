cmake_minimum_required(VERSION 3.8)
project(idontknowcpp)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp TicTacToe.cpp TicTacToe.h functions.cpp functions.h)
add_executable(idontknowcpp ${SOURCE_FILES})