#include "ent_bullet.h"

#include "bullet_anims.h"

#include "engine/input/input.h"
#include "engine/entity/entities.h"

const char* const BULLET_NAMES[] = {
    "LAZER",
    "PLAZMA",
    "MISSILE"
};
const EntityData* const BULLET_ENTITIES[] = {
    &BULLET_LAZER_ENTITY,
    &BULLET_PLAZMA_ENTITY,
    &BULLET_MISSILE_ENTITY,
};

const AniamtionData* const BULLET_ANIMS[] = {
    &BULLET_LAZER_ANIMATION,
    &BULLET_PLAZMA_ANIMATION,
    &BULLET_MISSILE_ANIMATION,
};

void bullet_init(RuntimeEntity* this)
{
    entities_set_flags(
        this, 
        RT_ENTITY_FLAG_DRAW | 
        RT_ENTITY_FLAG_PROCESS_PHYSICS | 
        RT_ENTITY_FLAG_PROCESS_UPDATE | 
        RT_ENTITY_FLAG_DRAW | 
        RT_ENTITY_FLAG_COLLISION
    );
    
    Vec2_uint8 sp;
    sp.x = FROM_FIX(this->screen_position.x);
    sp.y = FROM_FIX(this->screen_position.y);
    
    
    BulletVars* vars = (BulletVars*)this->data;
    vars->damage = BULLET_DATA_GET_DAMAGE(this->entity->data);
    vars->speed = BULLET_DATA_GET_SPEED(this->entity->data);
    vars->type = BULLET_DATA_GET_TYPE(this->entity->data);
    
    this->oam_attribs = spr_init_sprite(0, 0, &sp, OAM_SPR_SIZE_8x8);
    this->animation = anims_create_animation(BULLET_ANIMS[vars->type], this->oam_attribs);

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

ENTITY_VTABLE( BULLET_VTABLE,
    bullet_init,
    bullet_update,
    nullptr,
    bullet_collide,
    bullet_destroy
)

ENTITY_DATA(
    BULLET_ID, BULLET_LAZER_ENTITY, BULLET_VTABLE, 
    8, 8, 
    BULLET_DATA(BULLET_TYPE_LAZER, 24, 200)
)
ENTITY_DATA(
    BULLET_ID, BULLET_PLAZMA_ENTITY, BULLET_VTABLE, 
    8, 8, 
    BULLET_DATA(BULLET_TYPE_PLAZMA, 36, 120)
)
ENTITY_DATA(
    BULLET_ID, BULLET_MISSILE_ENTITY, BULLET_VTABLE, 
    8, 8, 
    BULLET_DATA(BULLET_TYPE_MISSILE, 55, 90)
)