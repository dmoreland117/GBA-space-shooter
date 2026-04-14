#include "engine/entity/entities.h"
#include "dsgbalib/gba.h"
#include "engine/video/sprites.h"
#include "engine/animation/animations.h"


EWRAM_BSS RuntimeEntity _runtime_entities_pool[MAX_LOADED_ENTITIES];
EWRAM_BSS EntityVTable  _runtime_vtable_pool[MAX_LOADED_ENTITIES];

void entities_init()
{
    REG_DISPCNT |= ENABLE_OBJS | SPRITES_LINEAR_ARRAY;
}

RuntimeEntity *entities_create_entity(EntityData* entity, Vec2_uint16 *pos)
{
    for (uint8_t i = 0; i < MAX_LOADED_ENTITIES; i++)
    {
        RuntimeEntity* re = &_runtime_entities_pool[i];
        if (re->flags & RT_ENTITY_FLAG_ACTIVE) continue;

        EntityVTable* vtable = &_runtime_vtable_pool[i];

        vtable->init_callback = entity->vtable->init_callback;
        vtable->update_callback = entity->vtable->update_callback;
        vtable->collide_callback = entity->vtable->collide_callback;
        vtable->destroy_callback = entity->vtable->destroy_callback;
        vtable->draw_callback = entity->vtable->draw_callback;

        re->entity = entity;
        re->flags = RT_ENTITY_FLAG_ACTIVE;
        re->vtable_id = i;
        re->id = entity->id;

        re->screen_position.x = TO_FIX(pos->x);
        re->screen_position.y = TO_FIX(pos->y);

        vtable->init_callback(re);

        return re;
    }

    return nullptr;
}
void entities_free_entity(RuntimeEntity* entity)
{
    if (!entity->flags & RT_ENTITY_FLAG_ACTIVE) return;

    EntityVTable* vtable = &_runtime_vtable_pool[entity->vtable_id];

    vtable->destroy_callback(entity);

    entity->flags = 0;

    // reset velocity.
    entity->velocity.x = 0;
    entity->velocity.y = 0;

    anims_destroy_animation(entity->animation);
    spr_clear_sprite(entity->oam_attribs);
    entity->animation = nullptr;
    entity->oam_attribs = nullptr;
    entity->entity = nullptr;

    entity->screen_position.x = 0;
    entity->screen_position.y = 0;
}
void entties_draw()
{
    for (uint8_t i = 0; i < MAX_LOADED_ENTITIES; i++)
    {
        RuntimeEntity* re = &_runtime_entities_pool[i];
        if (!(re->flags & RT_ENTITY_FLAG_ACTIVE)) continue;
        if (!(re->flags & RT_ENTITY_FLAG_DRAW)) continue;

        Vec2_uint8 np;
        np.x = FROM_FIX(re->screen_position.x);
        np.y = FROM_FIX(re->screen_position.y);

        spr_update_sprite_position(re->oam_attribs, &np);

        EntityVTable* v = &_runtime_vtable_pool[re->vtable_id];
        if (v->draw_callback)
        {
            v->draw_callback(re);
        }

    }
}
void entities_update()
{
    for (uint8_t i = 0; i < MAX_LOADED_ENTITIES; i++)
    {
        RuntimeEntity* re = &_runtime_entities_pool[i];
        if (!(re->flags & RT_ENTITY_FLAG_ACTIVE)) continue;
        if (!(re->flags & RT_ENTITY_FLAG_PROCESS_UPDATE)) continue;

        EntityVTable* vtable = &_runtime_vtable_pool[re->vtable_id];
        vtable->update_callback(re);

        re->screen_position.x += re->velocity.x;
        re->screen_position.y += re->velocity.y;
    } 
}

bool entity_collide(const RuntimeEntity* a, const RuntimeEntity* b)
{
    int ax = FROM_FIX(a->screen_position.x);
    int ay = FROM_FIX(a->screen_position.y);
    int bx = FROM_FIX(b->screen_position.x);
    int by = FROM_FIX(b->screen_position.y);

    bool aa = ax < bx + b->entity->size.x;
    bool bb = ax + a->entity->size.x > bx;
    bool c = ay < by + b->entity->size.y;
    bool d = ay + a->entity->size.y > by;

    return (
        aa && bb && c && d
    );
}

void entities_check_collisions()
{
    for (int i = 0; i < MAX_LOADED_ENTITIES; i++)
    {
        RuntimeEntity* a = &_runtime_entities_pool[i];
        if (!(a->flags & RT_ENTITY_FLAG_ACTIVE)) continue;
        if (!(a->flags & RT_ENTITY_FLAG_COLLISION)) continue;

        for (int j = i + 1; j < MAX_LOADED_ENTITIES; j++)
        {
            RuntimeEntity* b = &_runtime_entities_pool[j];
            if (!(b->flags & RT_ENTITY_FLAG_ACTIVE)) continue;
            if (!(b->flags & RT_ENTITY_FLAG_COLLISION)) continue;

            if (entity_collide(a, b))
            {
                EntityVTable* av = &_runtime_vtable_pool[a->vtable_id];
                av->collide_callback(a, b);
                
                EntityVTable* bv = &_runtime_vtable_pool[b->vtable_id];
                bv->collide_callback(b, a);
            }
        }
    }
}
RuntimeEntity *entities_get_player()
{
    for (uint8_t i = 0; i < MAX_LOADED_ENTITIES; i++)
    {
        RuntimeEntity* re = &_runtime_entities_pool[i];
        if (!(re->flags & RT_ENTITY_FLAG_ACTIVE)) continue;

        if (re->id == 0) return re;
    }

    return nullptr;
}