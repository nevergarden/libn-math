cmake_minimum_required(VERSION 3.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(libnv_math)

add_subdirectory(src)
add_subdirectory(test)
enable_testing()
add_test(NAME main-test COMMAND nmath-test)
