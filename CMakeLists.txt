cmake_minimum_required(VERSION 3.17)
project(matrices_operators)

set(CMAKE_CXX_STANDARD 14)

add_executable(matrices_operators main.cpp matrix.cpp AutoPtr.cpp AutoPtr.h)