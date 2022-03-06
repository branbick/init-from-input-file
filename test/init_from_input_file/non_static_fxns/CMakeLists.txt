cmake_minimum_required(VERSION 3.22.1)

set(project_name init_from_input_file_non_static_fxns_test)

set(CMAKE_CXX_STANDARD 17)  # GoogleTest requires at least C++11

project(
    ${project_name}
    LANGUAGES C CXX
    DESCRIPTION "Testing the non-static functions declared in \
                 src/init_from_input_file.h"
)

# Use GoogleTest without having it installed locally beforehand
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    ${project_name}
    ${project_name}.cpp
    ../../../src/init_from_input_file.c
    ../../../src/init_tools.c
)

target_compile_definitions(${project_name} PRIVATE PRINT_ERRORS)
target_compile_options(${project_name} PRIVATE -Wall -Wextra -Wpedantic)

target_link_libraries(
    ${project_name}
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(${project_name})
