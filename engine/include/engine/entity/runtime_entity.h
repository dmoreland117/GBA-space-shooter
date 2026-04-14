#if !defined(RUNTIME_ENTITY_H)
#define RUNTIME_ENTITY_H

#include "dsgbalib/types.h"
#include "engine/math/math.h"
#include "engine/entity/entity.h"
#include "engine/animation/runtime_animation.h"
#include "engine/video/sprites.h"

#define ENTITY_VERIABLE_MAX_DATA_SIZE 16

typedef struct RuntimeEntity
{
    uint8_t data[ENTITY_VERIABLE_MAX_DATA_SIZE]; // variable data
    RuntimeAnimation* animation;
    EntityData* entity;
    OAMSprite*  oam_attribs;
    Vec2_int16  velocity;
    Vec2_uint16 screen_position;
    uint16_t    flags;
    uint8_t     id;
    uint8_t     vtable_id;
} RuntimeEntity; // 40 B

#define RT_ENTITY_FLAG_ACTIVE          BIT(0)
#define RT_ENTITY_FLAG_PROCESS_UPDATE  BIT(1)
#define RT_ENTITY_FLAG_PROCESS_PHYSICS BIT(2)
#define RT_ENTITY_FLAG_DRAW            BIT(3)
#define RT_ENTITY_FLAG_COLLISION       BIT(4)

#endif // RUNTIME_ENTITY_h
