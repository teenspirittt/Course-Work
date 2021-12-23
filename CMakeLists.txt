cmake_minimum_required(VERSION 3.20)
project(CourseWork)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)
add_executable(CourseWork main.cpp googletest/test.cpp src/List.inl include/List.h)
target_link_libraries(CourseWork gtest gtest_main)