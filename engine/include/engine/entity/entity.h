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
} EntityVTable; // 20b

typedef struct EntityData
{
    EntityVTable* vtable;
    uint32_t      data;     // custom data and flags usally defined through macros.
    Vec2_uint8    size;     // size used for collisions
    uint16_t      id;       // custom id for later reference
    uint16_t      start_animation_id;
} EntityData; // 32b


#define ENTITY_VTABLE(name, init, update, draw, collide, destroy) \
const EntityVTable name = { \
    .init_callback    = (init), \       
    .update_callback  = (update), \     
    .collide_callback = (collide), \        
    .destroy_callback = (destroy), \        
    .draw_callback    = (draw) \        
};

#define ENTITY_DATA(ent_id, name, vtable_name, sx, sy, ent_data) \
    const EntityData name = { \
        .id                 = (ent_id), \
        .vtable             = &(vtable_name), \
        .size               = {(sx), (sy)}, \
        .data               = (ent_data) \
    };

#endif // ENTITY_H
