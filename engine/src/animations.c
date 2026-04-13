#include "engine/animation/animations.h"

#include "dsgbalib/gba.h"

EWRAM_BSS AniamtionData* _animations_ptr;
IWRAM_BSS RuntimeAnimation _rt_animations_pool[MAX_RUNTIME_ANIMATIONS];

void _increment_frame(RuntimeAnimation *anim)
{
    anim->current_frame++;
    if (anim->current_frame >= anim->animation_data->frame_count)
    {
        if (!(anim->flags & RT_ANIM_FLAG_LOOPING)) return;
        
        anim->current_frame = 0;
    }
}

void _decrement_frame(RuntimeAnimation* anim)
{
    
}

void anims_init(AniamtionData *animations)
{
    _animations_ptr = animations;
}

RuntimeAnimation *anims_create_animation(AniamtionData* animation, OAMSprite* sprite) 
{
    for (uint8_t i = 0; i < MAX_RUNTIME_ANIMATIONS; i++)
    {
        RuntimeAnimation* current_anim = &_rt_animations_pool[i];
        if(current_anim->flags & RT_ANIM_FLAG_ACTIVE) continue;

        current_anim->id = animation->id;
        current_anim->animation_data  = animation;
        
        current_anim->current_frame = 0;
        current_anim->current_frame_timer = 0;
        
        current_anim->start_tile_offset = animation->tile_offset;

        current_anim->flags = RT_ANIM_FLAG_ACTIVE;
        
        if (animation->flags & ANIM_FLAG_PLAY_ON_CREATE)
            current_anim->flags |= RT_ANIM_FLAG_PLAYING;
        if (animation->flags & ANIM_FLAG_LOOP_ON_CREATE)
            current_anim->flags |= RT_ANIM_FLAG_LOOPING;

        current_anim->sprite = sprite;
        
        return current_anim;
    }

    return nullptr;
}
void anims_destroy_animation(RuntimeAnimation *animation)
{
    animation->flags = 0;
}

void anims_set_anim_clean(AniamtionData *anim)
{
    anim->flags &= ~RT_ANIM_FLAG_DIRTY;
}
void anims_update()
{
    for (uint8_t i = 0; i < MAX_RUNTIME_ANIMATIONS; i++)
    {
        RuntimeAnimation* current_anim = &_rt_animations_pool[i];
        if(!(current_anim->flags & RT_ANIM_FLAG_ACTIVE)) continue;
        if(!(current_anim->flags & RT_ANIM_FLAG_PLAYING)) continue;

        uint16_t new_frame_time = current_anim->current_frame_timer + current_anim->animation_data->speed_scale;
        AnimationFrame* current_frame = &current_anim->animation_data->frames[current_anim->current_frame];
        if(new_frame_time > current_frame->durration)
        {
            _increment_frame(current_anim);
            new_frame_time = 0;
            current_anim->flags |= RT_ANIM_FLAG_DIRTY; // redraw
        }

        current_anim->current_frame_timer = new_frame_time;
    }
}

void anims_draw()
{
    for (uint8_t i = 0; i < MAX_RUNTIME_ANIMATIONS; i++)
    {
        RuntimeAnimation* current_anim = &_rt_animations_pool[i];
        if(!(current_anim->flags & RT_ANIM_FLAG_ACTIVE)) continue;
        OAMSprite* sprite = current_anim->sprite;
        
        if ((current_anim->flags & RT_ANIM_FLAG_FLIP_DIRTY))
        {
            spr_flip_h(sprite, current_anim->flags & RT_ANIM_FLAG_FLIP_X);
            spr_flip_v(sprite, current_anim->flags & RT_ANIM_FLAG_FLIP_Y);
            current_anim->flags &= ~RT_ANIM_FLAG_FLIP_DIRTY;
        }
        if(!(current_anim->flags & RT_ANIM_FLAG_PLAYING)) continue;


        if (!(current_anim->flags & RT_ANIM_FLAG_DIRTY)) continue;

        AnimationFrame* frame = &current_anim->animation_data->frames[current_anim->current_frame];
        spr_update_sprite_tile(sprite, frame->tile_id + current_anim->start_tile_offset);

        current_anim->flags &= ~RT_ANIM_FLAG_DIRTY;
    }
}