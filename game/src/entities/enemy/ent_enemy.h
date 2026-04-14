#if !defined(ENT_ENEMY_H)
#define ENT_ENEMY_H

#include "engine/entity/runtime_entity.h"

#define HEALTH_DEPLETE_MASK 0b10000000
#define ENEMY_FIRE_INTERVAL 15000

typedef struct
{
    uint8_t health;
} EnemyVars;

extern const EntityVTable BULLET_VTABLE;
extern const EntityData   BULLET_ENTITY;

void enemy_init(RuntimeEntity *this);
void enemy_destroy(RuntimeEntity *this);
void enemy_update(RuntimeEntity *this);
void enemy_collide(RuntimeEntity *this, RuntimeEntity *collider);

#endif // ENT_ENEMY_H
