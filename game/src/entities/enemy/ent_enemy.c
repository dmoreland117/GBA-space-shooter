#include "ent_enemy.h"
#include "../bullet/ent_bullet.h"
#include "../player/scr_player.h"



#include "engine/input/input.h"
#include "engine/animation/animations.h"
#include "engine/entity/entities.h"

#include "enemy_anims.h"

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
    this->flags |= RT_ENTITY_FLAG_COLLISION;

    
    Vec2_uint8 sp;
    sp.x = FROM_FIX(this->screen_position.x);
    sp.y = FROM_FIX(this->screen_position.y);
    
    this->oam_attribs = spr_init_sprite(ENEMY_TILES_OFFSET, ENEMY_PALETTE_SLOT, &sp, OAM_SPR_SIZE_16x16);
    spr_flip_v(this->oam_attribs, true);
    
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

ENTITY_VTABLE(
    ENEMY_VTABLE,
    enemy_init,
    enemy_update,
    0x00,
    enemy_collide,
    enemy_destroy
)
ENTITY_DATA(
    ENEMY_ID, ENEMY_ENTITY, ENEMY_VTABLE,
    16, 16,
    0
)