#include "states/state_main_manu.h"

#include "memory_sections.h"

#include "engine/state/states.h"
#include "engine/math/math.h"

int main()
{
    set_current_state(&MAIN_MENU_STATE);
    states_loop();
}