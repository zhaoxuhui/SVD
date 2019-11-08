cmake_minimum_required(VERSION 3.12)
project(svd_eigen)

set(CMAKE_CXX_STANDARD 11)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

add_executable(svd_eigen main.cpp)