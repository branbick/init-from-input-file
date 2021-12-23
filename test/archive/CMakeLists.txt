cmake_minimum_required(VERSION 3.22.1)

set(tester tester_c)

project(
    ${tester}
    LANGUAGES C
)

add_executable(
    ${tester}
    ${tester}.c
    ../../src/init_from_input_file.h
    ../../src/init_from_input_file.c
    ../../src/init_tools.h
    ../../src/init_tools.c
)

target_compile_definitions(${tester} PRIVATE PRINT_ERRORS)
target_compile_options(${tester} PRIVATE -Wall -Wextra -Wpedantic)
target_compile_features(${tester} PRIVATE c_std_90)
