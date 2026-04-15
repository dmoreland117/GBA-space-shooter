#include "ent_bullet.h"

#include "bullet_anims.h"

#include "engine/input/input.h"
#include "engine/entity/entities.h"

void bullet_init(RuntimeEntity* this)
{
    this->flags |= RT_ENTITY_FLAG_DRAW;
    this->flags |= RT_ENTITY_FLAG_PROCESS_PHYSICS;
    this->flags |= RT_ENTITY_FLAG_PROCESS_UPDATE;
    this->flags |= RT_ENTITY_FLAG_DRAW;
    this->flags |= RT_ENTITY_FLAG_COLLISION;
    
    Vec2_uint8 sp;
    sp.x = FROM_FIX(this->screen_position.x);
    sp.y = FROM_FIX(this->screen_position.y);
    
    
    BulletVars* vars = (BulletVars*)this->data;
    vars->damage = BULLET_DATA_GET_DAMAGE(this->entity->data);
    vars->speed = BULLET_DATA_GET_SPEED(this->entity->data);
    vars->type = BULLET_DATA_GET_TYPE(this->entity->data);
    
    this->oam_attribs = spr_init_sprite(11, 0, &sp, OAM_SPR_SIZE_8x8);
    this->animation = anims_create_animation(&BULLET_MISSILE_ANIMATION, this->oam_attribs);

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