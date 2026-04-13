#if !defined(FIXED_POINT_H)
#define FIXED_POINT_H

#define FIX_SHIFT 8

#define TO_FIX(x)        ((x) << FIX_SHIFT)
#define FROM_FIX(x)      ((x) >> FIX_SHIFT)

#define FIX_INT_PART(x)  ((x) >> FIX_SHIFT)
#define FIX_FRAC_PART(x) ((x) & ((1 << FIX_SHIFT) - 1))

#endif // FIXED_POINT_H
