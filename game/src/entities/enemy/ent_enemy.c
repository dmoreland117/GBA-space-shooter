#include "ent_enemy.h"
#include "../bullet/ent_bullet.h"
#include "../player/scr_player.h"

#include "memory_sections.h"
#include "entity_ids.h"

#include "engine/input/input.h"
#include "engine/animation/animations.h"
#include "engine/entity/entities.h"

const AnimationFrame ENEMY_ANIM_FRAMES[] = {
    {
        .tile_id   = 6,
        .durration = ANIM_FRAME_DURRATION(10)
    },
    {
        .tile_id   = 7,
        .durration = ANIM_FRAME_DURRATION(10)
    },
};

const AniamtionData ENEMY_ANIMATION = {
    .frames = ENEMY_ANIM_FRAMES,
    .frame_count = 2,
    .tile_offset = 0,
    .speed_scale = DEFAULT_ANIM_SPEED_SCALE,
};

const EntityVTable ENEMY_VTABLE = {
    .init_callback    = enemy_init,
    .update_callback  = enemy_update,
    .collide_callback = enemy_collide,
    .destroy_callback = enemy_destroy
};

ENTITIES_TABLE EntityData ENEMY_ENTITY = {
    .id                 = ENEMY_ID,
    .start_animation_id = 1,
    .vtable             = &ENEMY_VTABLE,
    .size               = {16, 16}
};

void _take_damage(RuntimeEntity* this, uint8_t damage)
{
    EnemyVars* vars = (EnemyVars*)this->data;
    vars->health -= damage;

    if (vars->health & HEALTH_DEPLETE_MASK)
    {
        PlayerVars* v = get_player_data(entities_get_player());
        v->score += 10;
        entities_free_entity(this);
    }
}

void _kill()
{

}

void enemy_init(RuntimeEntity* this)
{
    this->flags |= RT_ENTITY_FLAG_DRAW;
    this->flags |= RT_ENTITY_FLAG_PROCESS_PHYSICS;
    this->flags |= RT_ENTITY_FLAG_PROCESS_UPDATE;
    this->flags |= RT_ENTITY_FLAG_DRAW;

    
    Vec2_uint8 sp;
    sp.x = FROM_FIX(this->screen_position.x);
    sp.y = FROM_FIX(this->screen_position.y);
    
    this->oam_attribs = spr_init_sprite(5, 0, &sp, OAM_SPR_SIZE_16x16);
    this->animation = anims_create_animation(&ENEMY_ANIMATION, this->oam_attribs);
    RT_ANIM_SET_FLIP_Y(this->animation);

    
    EnemyVars* vars = (EnemyVars*)this->data;
    vars->health = 100;
    
    this->velocity.y = 40;
}
void enemy_destroy(RuntimeEntity *this)
{

}

void enemy_update(RuntimeEntity* this)
{
    if (FROM_FIX(this->screen_position.y) > 150)
    {
        entities_free_entity(this);
    }
}
void enemy_collide(RuntimeEntity* this, RuntimeEntity* that)
{

    if (that->id == BULLET_ID)
    {
        _take_damage(this, get_bullet_data(that)->damage);
    }
}

