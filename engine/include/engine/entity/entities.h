#if !defined(ENTITIES_H)
#define ENTITIES_H

#include "engine/entity/runtime_entity.h"
#include "engine/entity/entities.h"

#define MAX_LOADED_ENTITIES 64

//void entities_init(EntityData* entities);

RuntimeEntity* entities_create_entity(EntityData* entity, Vec2_uint16* pos);
void           entities_free_entity(RuntimeEntity* entity);

void entities_update();
void entties_draw();
void entities_check_collisions();

RuntimeEntity* get_runtime_entities_pool();
/// @brief Get the Player or Entity 0
/// @return the first entity with id 0
RuntimeEntity* entities_get_player();

#endif // ENTITIES_H
