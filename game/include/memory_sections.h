#if !defined(MEMORY_H)
#define MEMORY_H

#include "engine/entity/entity.h"
#include "engine/state/state.h"

#define ENTITIES_TABLE __attribute__((section(".entities_table"))) const

extern const EntityData __entities_table_start;
extern const EntityData __entities_table_end;

#define ENTITIES_TABLE_START &__entities_table_start
#define ENTITIES_TABLE_END   &__entities_table_end

#define STATES_TABLE __attribute__((section(".states_table"))) const

extern const State __states_table_start;
extern const State __states_table_end;

#define STATES_TABLE_START &__states_table_start
#define STATES_TABLE_END   &__states_table_end

#endif