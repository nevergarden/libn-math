#ifndef _N_MATH_H
#define _N_MATH_H

#ifdef __SSE__
#include <xmmintrin.h>
#endif

static const float n_fmatrix_4x4_identity[4][4] = {
  1,0,0,0,
  0,1,0,0,
  0,0,1,0,
  0,0,0,1
};

void n_fmatrix_4x4_mult(const float a[4][4], const float b[4][4], float c[4][4]);

#endif
