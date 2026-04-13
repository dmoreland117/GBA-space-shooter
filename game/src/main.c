#include "engine/state/states.h"
#include "states/state_0.h"
#include "memory_sections.h"

#include "engine/math/math.h"

int main()
{
    set_current_state(STATES_TABLE_START);
    states_loop();
}