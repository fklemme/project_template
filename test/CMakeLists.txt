# Define target
set(target_name ${PROJECT_NAME}_test)
add_executable(${target_name})

# Set C++ standard
set_property(TARGET ${target_name} PROPERTY CXX_STANDARD 17)

# Enable more warnings
if(MSVC)
    #target_compile_options(${target_name} PRIVATE /W4) # commented to reduce noise in output window
else()
    target_compile_options(${target_name} PRIVATE -Wall -Wextra -pedantic)
endif()

# Add sources and include directory
file(GLOB_RECURSE header CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/../include/*.hpp")
file(GLOB_RECURSE source CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/../source/*.cpp")
file(GLOB_RECURSE local CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
target_sources(${target_name} PRIVATE ${header} PRIVATE ${source} PRIVATE ${local})
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# For Visual Studio filters
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/../include PREFIX "Header Files" FILES ${hdr})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/../source PREFIX "Source Files" FILES ${src})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "Test Files" FILES ${local})

# Configure Google Test
set(BUILD_GMOCK OFF CACHE BOOL "Build Gmock") # We don't need Gmock atm.
if(MSVC)
    # Windows uses shared run-time by default. Also use it in Google Test.
    set(gtest_force_shared_crt ON CACHE BOOL "Use shared (DLL) run-time lib")
endif()

# Get Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG         release-1.10.0
)
FetchContent_MakeAvailable(googletest)
target_link_libraries(${target_name} gtest gtest_main)

# Add tests
include(GoogleTest)
gtest_discover_tests(${target_name})

# Enable coverage (only works for gcc / clang)
option(ENABLE_COVERAGE "Enable coverage reporting" OFF)
if(ENABLE_COVERAGE AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building ${target_name} with coverage enabled!")
    target_compile_options(${target_name} PRIVATE --coverage)
    target_link_options(${target_name} PRIVATE --coverage)
endif()
