#if !defined(STATE_MAIN_MENU)
#define STATE_MAIN_MENU

#include "engine/state/states.h"

extern const State SCORES_STATE;

void scores_state_init();
void scores_state_update();
void scores_state_draw();
void scores_state_destroy();

#endif // STATE_MAIN_MENU
