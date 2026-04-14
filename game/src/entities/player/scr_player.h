#if !defined(SCR_PLAYER_H)
#define SCR_PLAYER_H

#include "engine/entity/runtime_entity.h"

#define PLAYER_SIZE_X 16
#define PLAYER_SIZE_Y 16

#define PLAYER_MAX_SPEED 300
#define PLAYER_ACCELERATION 16

#define PLAYER_MIN_X 20
#define PLAYER_MAX_X (240 - 20) - PLAYER_SIZE_X

typedef struct
{
    uint8_t  health;
    uint16_t score;
} PlayerVars;

void player_init(RuntimeEntity *this);
void player_destroy(RuntimeEntity *this);
void player_update(RuntimeEntity *this);
void player_collide(RuntimeEntity *this, RuntimeEntity *collider);

static inline PlayerVars* get_player_data(RuntimeEntity* entity)
{
    return (PlayerVars*)entity->data;
}

extern const EntityVTable SCR_PLAYER_VTABLE;
extern const EntityData   PLAYER_ENTITY;

#endif // SCR_PLAYER_H
