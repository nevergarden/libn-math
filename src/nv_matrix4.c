#include <stdio.h>
#include <xmmintrin.h>
#include "nv_matrix4.h"

static inline void n_fmatrix_4x4_mult_sse(const float a[4][4], const float b[4][4], float c[4][4]) {
  __m128 row1 = _mm_load_ps(&b[0][0]);
  __m128 row2 = _mm_load_ps(&b[1][0]);
  __m128 row3 = _mm_load_ps(&b[2][0]);
  __m128 row4 = _mm_load_ps(&b[3][0]);
  for (unsigned int i = 0; i<4; i++) {
    __m128 brod1 = _mm_set1_ps(a[i][0]);
    __m128 brod2 = _mm_set1_ps(a[i][1]);
    __m128 brod3 = _mm_set1_ps(a[i][2]);
    __m128 brod4 = _mm_set1_ps(a[i][3]);

    __m128 row = _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(brod1, row1), _mm_mul_ps(brod2, row2)),
        _mm_add_ps(_mm_mul_ps(brod3, row3), _mm_mul_ps(brod4, row4))
    );
    _mm_store_ps(&c[i][0], row);
  }
}

static inline void n_fmatrix_4x4_mult_norm(const float a[4][4], const float b[4][4], float c[4][4]) {
  for(unsigned int i=0; i < 4; i++) {
    for(unsigned int j=0; j < 4; j++) {
      c[i][j] = 
        a[i][0] * b[0][j] +
        a[i][1] * b[1][j] +
        a[i][2] * b[2][j] +
        a[i][3] * b[3][j];
    }
  }
}

void n_fmatrix_4x4_mult(const float a[4][4], const float b[4][4], float c[4][4]) {
#ifdef __SSE__
  n_fmatrix_4x4_mult_sse(a, b, c);
#else
  n_fmatrix_4x4_mult_norm(a, b, c);
#endif
}

void n_fmatrix_4x4_print(const float a[4][4]) {
  for (unsigned int i = 0; i < 4; i++) {
    printf("%f %f %f %f\n", a[i][0], a[i][1], a[i][2], a[i][3]);
  }
}
