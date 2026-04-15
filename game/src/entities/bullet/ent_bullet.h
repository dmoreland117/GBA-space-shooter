#if !defined(ENT_BULLET_H)
#define ENT_BULLET_H

#include "bullet_types.h"
#include "entity_ids.h"
#include "memory_sections.h"

#include "engine/entity/runtime_entity.h"
#include "engine/animation/animations.h"

#define BULLET_DATA(type, damage, speed) ((damage) | (speed) << 8) | (type) << 16
#define BULLET_DATA_GET_DAMAGE(data) ((data) & 0xff)
#define BULLET_DATA_GET_SPEED(data) (((data) >> 8) & 0xff)
#define BULLET_DATA_GET_TYPE(data) (((data) >> 16) & 0xff)

typedef struct
{
    uint8_t damage;
    uint8_t speed;
    uint8_t type;
} BulletVars;

void bullet_init(RuntimeEntity *this);
void bullet_destroy(RuntimeEntity *this);
void bullet_update(RuntimeEntity *this);
void bullet_collide(RuntimeEntity *this, RuntimeEntity *collider);

BulletVars* get_bullet_data(RuntimeEntity* entity);

#endif // ENT_BULLET_H
