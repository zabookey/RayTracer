cmake_minimum_required(VERSION 2.8)

project(RayTracer)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-std=c++11")

#add_definitions(-DVERBOSE)

add_subdirectory(src)
