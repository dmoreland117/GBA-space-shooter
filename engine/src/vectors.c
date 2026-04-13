#include "engine/math/vectors.h"

Vec2_int16 *add_vec2_i16(Vec2_int16 *v1, Vec2_int16 *v2)
{
    Vec2_int16 v;
    v.x = v1->x + v2->x;
    v.y = v1->y + v2->y;

    return &v;
}
Vec2_uint16 *add_vec2_u16(Vec2_uint16 *v1, Vec2_uint16 *v2)
{
    Vec2_uint16 v;
    v.x = v1->x + v2->x;
    v.y = v1->y + v2->y;

    return &v;
}
Vec2_int8 *add_vec2_i8(Vec2_int8 *v1, Vec2_int8 *v2)
{
    Vec2_int8 v;
    v.x = v1->x + v2->x;
    v.y = v1->y + v2->y;

    return &v;
}

Vec2_uint8 *add_vec2_u8(Vec2_uint8 *v1, Vec2_uint8 *v2)
{
    Vec2_uint8 v;
    v.x = v1->x + v2->x;
    v.y = v1->y + v2->y;

    return &v;
}
