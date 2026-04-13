#if !defined(ANIMATION_FRAME_H)
#define ANIMATION_FRAME_H

#include "dsgbalib/types.h"

typedef struct
{
    uint16_t tile_id;
    uint16_t durration; // this time will be bit shifted left one byte
} AnimationFrame;

#define ANIM_FRAME_DURRATION(d) TO_FIX((d))

#endif // ANIMATION_FRAME_H
