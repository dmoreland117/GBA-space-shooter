#if !defined(STATE_MAIN_MENU)
#define STATE_MAIN_MENU

#include "engine/state/states.h"

extern const State MAIN_MENU_STATE;

void main_menu_init();
void main_menu_update();
void main_menu_draw();
void main_menu_destroy();

#endif // STATE_MAIN_MENU
