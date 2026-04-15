#if !defined(ENT_ENEMY_H)
#define ENT_ENEMY_H

#include "memory_sections.h"
#include "entity_ids.h"

#include "engine/entity/runtime_entity.h"

#define ENEMY_PALETTE_SLOT 1
#define ENEMY_TILES_CHAR_BLOCK 0
#define ENEMY_TILES_OFFSET 21

#define HEALTH_DEPLETE_MASK 0b10000000
#define ENEMY_FIRE_INTERVAL 15000

typedef struct
{
    uint8_t health;
} EnemyVars;

extern const EntityData ENEMY_ENTITY;

void enemy_init(RuntimeEntity *this);
void enemy_destroy(RuntimeEntity *this);
void enemy_update(RuntimeEntity *this);
void enemy_collide(RuntimeEntity *this, RuntimeEntity *collider);



#endif // ENT_ENEMY_H
