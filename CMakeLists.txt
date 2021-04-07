cmake_minimum_required(VERSION 3.14)
#set(CMAKE_VERBOSE_MAKEFILE ON)

# Build debug by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type")
endif()

# --- Project name ---
project(magic)
add_subdirectory(main)

# --- Setup Tests ---
enable_testing()
add_subdirectory(test)
