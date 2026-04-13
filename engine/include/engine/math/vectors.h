#if !defined(VECTORS_H)
#define VECTORS_H

#include "dsgbalib/types.h"

// Set a bit at n index.
#define BIT(n) (1 << (n))

typedef struct Vec2_uint16
{
    uint16_t x, y;
} Vec2_uint16;

typedef struct Vec2_uint8
{
    uint8_t x, y;
} Vec2_uint8;

typedef struct Vec2_int16
{
    int16_t x, y;
} Vec2_int16;

typedef struct Vec2_int8
{
    int8_t x, y;
} Vec2_int8;


// Add vectors ========================================


Vec2_int16*  add_vec2_i16(Vec2_int16* v1, Vec2_int16* v2);
Vec2_uint16* add_vec2_u16(Vec2_uint16* v1, Vec2_uint16* v2);

Vec2_int8*  add_vec2_i8(Vec2_int8* v1, Vec2_int8* v2);
Vec2_uint8* add_vec2_u8(Vec2_uint8* v1, Vec2_uint8* v2);


#endif // VECTORS_H
