#if !defined(ANIMATION_H)
#define ANIMATION_H

#include "anim_frame.h"
#include "engine/math/math.h"

/// @brief Animation Data stored in ROM 
typedef struct
{
    AnimationFrame* frames;         /// Pointer to an Array of Frames
    uint16_t        id;             /// the constant id in anim_ids.h
    uint16_t        speed_scale;    /// Fixed point value to increase anim timer by
    uint16_t        tile_offset;    /// An offset in tiles to apply to all frames    
    uint8_t         frame_count;
    uint8_t         flags;
} AniamtionData;

#define ANIM_FLAG_LOOP_ON_CREATE BIT(0)
#define ANIM_FLAG_PLAY_ON_CREATE BIT(1)

#define DEFAULT_ANIM_SPEED_SCALE TO_FIX(1)   // 1.0f
#define HALF_ANIM_SPEED_SCALE    0x80        // 0.5f
#define QUARTER_ANIM_SPEED_SCALE 0x40        // 0.25f

#endif // ANIMATION_H
