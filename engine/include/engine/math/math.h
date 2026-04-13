#if !defined(MATH_H)
#define MATH_H

#include "vectors.h"
#include "fixed_point_macros.h"

extern int _divide_signed(int numerator, int denominator, int* remainder, int* abs);
#define devide_signed _divide_signed

#endif // MATH_H
