#if !defined(ENTITY_H)
#define ENTITY_H

#include "dsgbalib/types.h"
#include "engine/math/vectors.h"

typedef struct RuntimeEntity RuntimeEntity;

typedef void(*RuntimeEntityCallbackFn)(RuntimeEntity*);
typedef void(*RuntimeEntityCollideFn)(RuntimeEntity*, RuntimeEntity*);

typedef struct EntityVTable
{
    RuntimeEntityCallbackFn init_callback;
    RuntimeEntityCallbackFn destroy_callback;
    RuntimeEntityCallbackFn update_callback;
    RuntimeEntityCallbackFn draw_callback;
    RuntimeEntityCollideFn  collide_callback;
} EntityVTable;

typedef struct EntityData
{
    EntityVTable* vtable;
    uint32_t      data;     // custom data usally defined through macros.
    Vec2_uint8    size;
    uint16_t      id;
    uint16_t      start_animation_id;
} EntityData;

#endif // ENTITY_H
