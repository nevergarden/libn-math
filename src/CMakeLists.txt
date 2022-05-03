add_library(nv-math SHARED
  nv_matrix4.c
)
# TODO: this won't work in msvc
target_link_libraries(nv-math PUBLIC m)
set_target_properties(nv-math PROPERTIES
  VERSION 0.0.1
  SOVERSION 0
  PUBLIC_HEADER nv_math.h
)
