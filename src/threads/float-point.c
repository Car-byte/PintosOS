#include "threads/float-point.h"
#include <inttypes.h>
#include <debug.h>

int float_init(int numerator, int denominator) {
  ASSERT(denominator != 0);
  return (numerator * POINT) / denominator;
}

int float_multiply(int fp_numerator, int fp_denominator) {
  ASSERT(fp_denominator != 0);
  return ((int64_t)fp_numerator * fp_denominator) / POINT;
}

int float_divide(int fp_numerator, int fp_denominator) {
  ASSERT(fp_denominator != 0);
  return ((int64_t)fp_numerator * POINT) / fp_denominator;
}

int float_floor(int fp) {
  return fp / POINT;
}

int float_round(int fp) {
  if (fp >= 0) {
    return (fp + POINT / 2) / POINT;
  }
  return (fp - POINT / 2) / POINT;
}
