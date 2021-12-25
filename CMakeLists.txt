cmake_minimum_required(VERSION 3.20)
project(CourseWork)

set(CMAKE_CXX_STANDARD 14)
add_executable(CourseWork main.cpp  src/List.cpp include/List.h src/menu.cpp include/menu.h)
