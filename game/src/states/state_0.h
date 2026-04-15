#if !defined(STATE_0_H)
#define STATE_0_H

#include "engine/state/state.h"

#define ENEMY_SPAWN_TIMER_INTERVAL 30000

extern const State LEVEL_STATE;

void state_0_init();
void state_0_update();
void state_0_draw();


#endif // STATE_0_H
