#include "entities/bullet/ent_bullet.h"
#include "memory_sections.h"
#include "engine/input/input.h"
#include "engine/entity/entities.h"
#include "entity_ids.h"

const AnimationFrame BULLET_PLAZMA_ANIM_FRAMES[] = {
    {
        .tile_id   = 9,
        .durration = ANIM_FRAME_DURRATION(10)
    },
    {
        .tile_id   = 10,
        .durration = ANIM_FRAME_DURRATION(10)
    },
};

const AniamtionData BULLET_PLAZMA_ANIMATION = {
    .frames = BULLET_PLAZMA_ANIM_FRAMES,
    .frame_count = 2,
    .speed_scale = DEFAULT_ANIM_SPEED_SCALE,
    .flags = ANIM_FLAG_LOOP_ON_CREATE | ANIM_FLAG_PLAY_ON_CREATE
};

const AniamtionData BULLET_LAZER_ANIMATION = {
    .frames = BULLET_PLAZMA_ANIM_FRAMES,
    .frame_count = 2,
    .tile_offset = 2,
    .speed_scale = DEFAULT_ANIM_SPEED_SCALE,
    .flags = ANIM_FLAG_LOOP_ON_CREATE | ANIM_FLAG_PLAY_ON_CREATE
};


const EntityVTable BULLET_VTABLE = {
    .init_callback    = bullet_init,
    .update_callback  = bullet_update,
    .collide_callback = bullet_collide,
    .destroy_callback = bullet_destroy,
    .draw_callback = 0x00
};

ENTITIES_TABLE EntityData BULLET_ENTITY = {
    .id                 = BULLET_ID,
    .start_animation_id = 1,
    .vtable             = &BULLET_VTABLE,
    .size               = {8, 8},
    .data               = BULLET_DATA(BULLET_TYPE_LAZER, 24, 120)
};

void bullet_init(RuntimeEntity* this)
{
    this->flags |= RT_ENTITY_FLAG_DRAW;
    this->flags |= RT_ENTITY_FLAG_PROCESS_PHYSICS;
    this->flags |= RT_ENTITY_FLAG_PROCESS_UPDATE;
    this->flags |= RT_ENTITY_FLAG_DRAW;

    
    Vec2_uint8 sp;
    sp.x = FROM_FIX(this->screen_position.x);
    sp.y = FROM_FIX(this->screen_position.y);
    
    
    BulletVars* vars = (BulletVars*)this->data;
    vars->damage = BULLET_DATA_GET_DAMAGE(this->entity->data);
    vars->speed = BULLET_DATA_GET_SPEED(this->entity->data);
    vars->type = BULLET_DATA_GET_TYPE(this->entity->data);
    
    this->oam_attribs = spr_init_sprite(11, 0, &sp, OAM_SPR_SIZE_8x8);
    this->animation = anims_create_animation(&BULLET_LAZER_ANIMATION, this->oam_attribs);

    this->velocity.y = -vars->speed << 2;
}

void bullet_destroy(RuntimeEntity *this)
{

}

void bullet_update(RuntimeEntity* this)
{
    if (FROM_FIX(this->screen_position.y) > 150)
    {
        entities_free_entity(this);
    }
    
}
void bullet_collide(RuntimeEntity* this, RuntimeEntity* that)
{
    if (that->id == ENEMY_ID)
    {
        entities_free_entity(this);
    }
}
BulletVars *get_bullet_data(RuntimeEntity *entity)
{
    return (BulletVars*)entity->data;
}