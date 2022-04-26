include_directories(../src)
add_executable(nmath-test ./matrixf4_mult.c)
target_link_libraries(nmath-test libn-math)
