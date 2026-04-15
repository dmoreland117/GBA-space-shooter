#if !defined(ENT_BULLET_H)
#define ENT_BULLET_H

#include "bullet_types.h"
#include "entity_ids.h"
#include "memory_sections.h"

#include "engine/entity/runtime_entity.h"
#include "engine/animation/animations.h"

#define BULLET_DATA(type, damage, speed) ((damage) | (speed) << 7) | (type) << 14
#define BULLET_DATA_GET_DAMAGE(data) ((data) & 0xff)
#define BULLET_DATA_GET_SPEED(data) (((data) >> 7) & 0xff)
#define BULLET_DATA_GET_TYPE(data) (((data) >> 14) & 0xff)

typedef struct
{
    uint8_t damage;
    uint8_t speed;
    BulletType type;
} BulletVars;

void bullet_init(RuntimeEntity *this);
void bullet_destroy(RuntimeEntity *this);
void bullet_update(RuntimeEntity *this);
void bullet_collide(RuntimeEntity *this, RuntimeEntity *collider);

BulletVars* get_bullet_data(RuntimeEntity* entity);

ENTITY_VTABLE(
    BULLET_VTABLE,
    bullet_init,
    bullet_update,
    0x00,
    bullet_collide,
    bullet_destroy
)

ENTITY_DATA(
    BULLET_ID, BULLET_ENTITY, BULLET_VTABLE, 
    16, 16, 
    BULLET_DATA(BULLET_TYPE_LAZER, 24, 120)
)

#endif // ENT_BULLET_H
