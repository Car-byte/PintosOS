#ifndef THREAD_FLOAT_POINT_H
#define THREAD_FLOAT_POINT_H

/*We are using 17.14 float point*/
#define R_BITS 14
#define POINT (1 << R_BITS)

int float_init(int numerator, int denominator);

int float_multiply(int fp_numerator, int fp_denominator);

int float_divide(int fp_numerator, int fp_denominator);

int float_floor(int fp);

int float_round(int fp);

#endif /*THREAD_FLOAT_POINT_H*/
