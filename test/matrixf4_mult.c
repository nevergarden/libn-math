#include <assert.h>
#include <nv_math.h>

int main() {
  float a[4][4] = {
    1,2,3,4,
    1,2,3,4,
    1,2,3,4,
    1,2,3,4
  };

  float b[4][4] = {
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1
  };

  float c[4][4];

  n_fmatrix_4x4_mult(a, b, c);
  assert(c[2][2] == 3);
}
