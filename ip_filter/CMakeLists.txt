cmake_minimum_required(VERSION 3.16)
project(ip_filter)

set(SRC ip_filter.cpp helpers.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall")
add_executable(${PROJECT_NAME} ${SRC})