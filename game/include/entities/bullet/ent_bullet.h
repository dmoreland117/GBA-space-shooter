#if !defined(ENT_BULLET_H)
#define ENT_BULLET_H

#include "engine/entity/runtime_entity.h"
#include "engine/animation/animations.h"
#include "bullet_types.h"

#define BULLET_DATA(damage, speed) ((damage) | (speed) << 8)
#define BULLET_DATA_GET_DAMAGE(data) ((data) & 0xff)
#define BULLET_DATA_GET_SPEED(data) (((data) & 0xff00) >> 8)

typedef struct
{
    uint8_t damage;
    uint8_t speed;
    BulletType type;
} BulletVars;

extern const EntityVTable BULLET_VTABLE;
extern const EntityData   BULLET_ENTITY;

void bullet_init(RuntimeEntity *this);
void bullet_destroy(RuntimeEntity *this);
void bullet_update(RuntimeEntity *this);
void bullet_collide(RuntimeEntity *this, RuntimeEntity *collider);

BulletVars* get_bullet_data(RuntimeEntity* entity);

#endif // ENT_BULLET_H
