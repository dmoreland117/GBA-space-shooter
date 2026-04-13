#if !defined(RUNTIME_ANIMATION_H)
#define RUNTIME_ANIMATION_H

#include "animation_data.h"
#include "engine/math/math.h"
#include "engine/video/sprites.h"

typedef struct RuntimeAnimation
{
    AniamtionData* animation_data;
    OAMSprite*     sprite;
    uint16_t       current_frame_timer;
    uint16_t       start_tile_offset;
    uint16_t       flags;
    uint8_t        current_frame;
    uint8_t        id;
} RuntimeAnimation;

#define RT_ANIM_FLAG_ACTIVE   BIT(0)
#define RT_ANIM_FLAG_PLAYING  BIT(1)
#define RT_ANIM_FLAG_REVERSE  BIT(2)
#define RT_ANIM_FLAG_LOOPING  BIT(3)
#define RT_ANIM_FLAG_FINISHED BIT(4)

#define RT_ANIM_FLAG_FLIP_X BIT(5)
#define RT_ANIM_FLAG_FLIP_Y BIT(6)

#define RT_ANIM_FLAG_DIRTY      BIT(7)
#define RT_ANIM_FLAG_FLIP_DIRTY BIT(8)

#define RT_ANIM_SET_FLIP_X(a) \
    (a)->flags |= RT_ANIM_FLAG_FLIP_X; \
    (a)->flags |= RT_ANIM_FLAG_FLIP_DIRTY
#define RT_ANIM_SET_FLIP_Y(a) \
    (a)->flags |= RT_ANIM_FLAG_FLIP_Y; \
    (a)->flags |= RT_ANIM_FLAG_FLIP_DIRTY

#endif // RUNTIME_ANIMATION_H
