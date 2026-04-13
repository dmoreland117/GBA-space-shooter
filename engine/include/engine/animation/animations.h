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
void              destroy_animation(RuntimeAnimation* animation);

void anims_set_anim_clean(AniamtionData* anim);

void anims_update();
void anims_draw();

#endif // ANIMATIONS_H
