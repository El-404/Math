cmake_minimum_required(VERSION 4.2.3)

project(Math)

add_executable(${PROJECT_NAME} src/main.cpp)
include_directories(eigen/Eigen)
