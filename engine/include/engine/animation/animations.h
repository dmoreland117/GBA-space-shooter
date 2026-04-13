#if !defined(ANIMATIONS_H)
#define ANIMATIONS_H

#include "runtime_animation.h"
#include "engine/video/sprites.h"

#define MAX_RUNTIME_ANIMATIONS 64

void anims_init(AniamtionData* animations);

/// @brief Create an Animation in memory
/// @param anim A pointer to the (Usally in ROM) AnimationData
/// @param sprite A pointer to the OAM Attribute to use for this animation
/// @return A pointer to the in memory animation data
RuntimeAnimation* anims_create_animation(AniamtionData* anim, OAMSprite* sprite);
void              anims_destroy_animation(RuntimeAnimation* animation);

void anims_update();
void anims_draw();

static inline void anims_set_anim_clean(RuntimeAnimation *anim)
{
    anim->flags &= ~RT_ANIM_FLAG_DIRTY;
}
static inline void anims_reset_anim(RuntimeAnimation *anim)
{
    anim->current_frame = 0;
    anim->current_frame_timer = 0;
    anim->flags &= ~RT_ANIM_FLAG_FINISHED;
    anim->flags |= RT_ANIM_FLAG_DIRTY;
}

#endif // ANIMATIONS_H
