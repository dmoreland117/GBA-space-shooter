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

void enemy_init(RuntimeEntity *this);
void enemy_destroy(RuntimeEntity *this);
void enemy_update(RuntimeEntity *this);
void enemy_collide(RuntimeEntity *this, RuntimeEntity *collider);

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

#endif // ENT_ENEMY_H
