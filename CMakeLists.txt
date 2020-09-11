cmake_minimum_required(VERSION 3.14)
#set(CMAKE_VERBOSE_MAKEFILE ON)

# Project name
project(magic)
add_subdirectory(main)

# Setup Tests
include(CTest)
add_subdirectory(test)
