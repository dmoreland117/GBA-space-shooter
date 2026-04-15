#if !defined(ANIM_MACROS_H)
#define ANIM_MACROS_H

#include "engine/animation/runtime_animation.h"

#define BEGIN_FRAMES(name) \
    static const AnimationFrame name[] = {

#define FRAME(tile, frame_duration) \ 
    { .tile_id = (tile), .duration = ANIM_FRAME_DURRATION(frame_duration) },

#define END_FRAMES(name) \
    }; \
    static const uint16_t name##_COUNT = sizeof(name) / sizeof(AnimationFrame);

#define ANIM_DATA(name, frames_name, speed, offset, anim_flags) \
    static const AniamtionData name = { \
        .frames = (frames_name), \
        .frame_count = (frames_name##_COUNT), \
        .tile_offset = (offset), \
        .speed_scale = (speed), \
        .flags = (anim_flags) \
    };


#endif // ANIM_MACROS_H
