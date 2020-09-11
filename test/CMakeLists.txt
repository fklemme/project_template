# Define target
set(target_name ${PROJECT_NAME}_test)
add_executable(${target_name})

# Set C++ standard
set_property(TARGET ${target_name} PROPERTY CXX_STANDARD 17)

# Enable more warnings
if(MSVC)
    target_compile_options(${target_name} PRIVATE /W4)
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
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "${target_name}" FILES ${local})

# Get GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG         release-1.10.0
)
set(BUILD_GMOCK OFF CACHE BOOL "Build Gmock") # Don't need it atm.
FetchContent_MakeAvailable(googletest)
target_link_libraries(${target_name} gtest gtest_main)

# Add tests
include(GoogleTest)
gtest_discover_tests(${target_name})
